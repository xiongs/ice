// **********************************************************************
//
// Copyright (c) 2003-2015 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

package IceInternal;

import java.util.concurrent.Callable;

import Ice.ConnectionI;

public class QueueRequestHandler implements RequestHandler
{
    public
    QueueRequestHandler(Instance instance, RequestHandler delegate)
    {
        _executor = instance.getQueueExecutor();
        assert(delegate != null);
        _delegate = delegate;
    }

    @Override
    public RequestHandler
    update(RequestHandler previousHandler, RequestHandler newHandler)
    {
        //
        // Only update to new handler if the previous handler matches this one.
        //
        if(previousHandler == this || previousHandler == _delegate)
        {
            if(newHandler != null)
            {
                return new QueueRequestHandler(_delegate.getReference().getInstance(), newHandler);
            }
            else
            {
                return null;
            }
        }
        return this;
    }

    @Override
    public int
    sendAsyncRequest(final ProxyOutgoingAsyncBase out) throws RetryException
    {
        return _executor.execute(new Callable<Integer>()
        {
            @Override
            public Integer call() throws RetryException
            {
                return _delegate.sendAsyncRequest(out);
            }
        });
    }

    @Override
    public void
    asyncRequestCanceled(final OutgoingAsyncBase outAsync, final Ice.LocalException ex)
    {
        _executor.executeNoThrow(new Callable<Void>()
        {
            @Override
            public Void call()
            {
                _delegate.asyncRequestCanceled(outAsync, ex);
                return null;
            }
        });
    }

    @Override
    public Reference
    getReference()
    {
        return _delegate.getReference();
    }

    @Override
    public ConnectionI
    getConnection()
    {
        return _delegate.getConnection();
    }

    private final RequestHandler _delegate;
    private final QueueExecutorService _executor;
}
