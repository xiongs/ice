// **********************************************************************
//
// Copyright (c) 2001
// MutableRealms, Inc.
// Huntsville, AL, USA
//
// All Rights Reserved
//
// **********************************************************************

#ifndef GEN_H
#define GEN_H

#include <Slice/Parser.h>
#include <Slice/OutputUtil.h>

namespace Slice
{

class Gen : ::IceInternal::noncopyable
{
public:

    Gen(const std::string&,
	const std::string&,
	const std::string&,
	const std::vector<std::string>&,
	const std::string&);
    ~Gen();

    bool operator!() const; // Returns true if there was a constructor error

    void generate(const UnitPtr&);

private:

    std::string changeInclude(const std::string&);
    void printHeader(Output&);

    Output H;
    Output C;

    std::string _base;
    std::string _include;
    std::vector<std::string> _includePaths;
    std::string _dllExport;

    class TypesVisitor : ::IceInternal::noncopyable, public ParserVisitor
    {
    public:

	TypesVisitor(Output&, Output&, const std::string&);

	virtual void visitModuleStart(const ModulePtr&);
	virtual void visitModuleEnd(const ModulePtr&);
	virtual void visitVector(const VectorPtr&);
	virtual void visitEnum(const EnumPtr&);
	virtual void visitNative(const NativePtr&);

    private:

	Output& H;
	Output& C;

	std::string _dllExport;
    };

    class ProxyDeclVisitor : ::IceInternal::noncopyable, public ParserVisitor
    {
    public:

	ProxyDeclVisitor(Output&, Output&, const std::string&);

	virtual void visitUnitStart(const UnitPtr&);
	virtual void visitUnitEnd(const UnitPtr&);
	virtual void visitModuleStart(const ModulePtr&);
	virtual void visitModuleEnd(const ModulePtr&);
	virtual void visitClassDecl(const ClassDeclPtr&);

    private:

	Output& H;
	Output& C;

	std::string _dllExport;
    };

    class ProxyVisitor : ::IceInternal::noncopyable, public ParserVisitor
    {
    public:

	ProxyVisitor(Output&, Output&, const std::string&);

	virtual void visitUnitStart(const UnitPtr&);
	virtual void visitUnitEnd(const UnitPtr&);
	virtual void visitModuleStart(const ModulePtr&);
	virtual void visitModuleEnd(const ModulePtr&);
	virtual void visitClassDefStart(const ClassDefPtr&);
	virtual void visitClassDefEnd(const ClassDefPtr&);
	virtual void visitOperation(const OperationPtr&);

    private:

	Output& H;
	Output& C;

	std::string _dllExport;
    };

    class DelegateVisitor : ::IceInternal::noncopyable, public ParserVisitor
    {
    public:

	DelegateVisitor(Output&, Output&, const std::string&);

	virtual void visitUnitStart(const UnitPtr&);
	virtual void visitUnitEnd(const UnitPtr&);
	virtual void visitModuleStart(const ModulePtr&);
	virtual void visitModuleEnd(const ModulePtr&);
	virtual void visitClassDefStart(const ClassDefPtr&);
	virtual void visitClassDefEnd(const ClassDefPtr&);
	virtual void visitOperation(const OperationPtr&);

    private:

	Output& H;
	Output& C;

	std::string _dllExport;
    };

    class DelegateMVisitor : ::IceInternal::noncopyable, public ParserVisitor
    {
    public:

	DelegateMVisitor(Output&, Output&, const std::string&);

	virtual void visitUnitStart(const UnitPtr&);
	virtual void visitUnitEnd(const UnitPtr&);
	virtual void visitModuleStart(const ModulePtr&);
	virtual void visitModuleEnd(const ModulePtr&);
	virtual void visitClassDefStart(const ClassDefPtr&);
	virtual void visitClassDefEnd(const ClassDefPtr&);
	virtual void visitOperation(const OperationPtr&);

    private:

	Output& H;
	Output& C;

	std::string _dllExport;
    };

    class ObjectDeclVisitor : ::IceInternal::noncopyable, public ParserVisitor
    {
    public:

	ObjectDeclVisitor(Output&, Output&, const std::string&);

	virtual void visitModuleStart(const ModulePtr&);
	virtual void visitModuleEnd(const ModulePtr&);
	virtual void visitClassDecl(const ClassDeclPtr&);

    private:

	Output& H;
	Output& C;

	std::string _dllExport;
    };

    class ObjectVisitor : ::IceInternal::noncopyable, public ParserVisitor
    {
    public:

	ObjectVisitor(Output&, Output&, const std::string&);

	virtual void visitModuleStart(const ModulePtr&);
	virtual void visitModuleEnd(const ModulePtr&);
	virtual void visitClassDefStart(const ClassDefPtr&);
	virtual void visitClassDefEnd(const ClassDefPtr&);
	virtual void visitOperation(const OperationPtr&);
	virtual void visitDataMember(const DataMemberPtr&);

    private:

	Output& H;
	Output& C;

	std::string _dllExport;
    };

    class IceVisitor : ::IceInternal::noncopyable, public ParserVisitor
    {
    public:

	IceVisitor(Output&, Output&, const std::string&);

	virtual void visitUnitStart(const UnitPtr&);
	virtual void visitUnitEnd(const UnitPtr&);
	virtual void visitClassDecl(const ClassDeclPtr&);
	virtual void visitClassDefStart(const ClassDefPtr&);

    private:

	Output& H;
	Output& C;

	std::string _dllExport;
    };

    class HandleVisitor : ::IceInternal::noncopyable, public ParserVisitor
    {
    public:

	HandleVisitor(Output&, Output&, const std::string&);

	virtual void visitModuleStart(const ModulePtr&);
	virtual void visitModuleEnd(const ModulePtr&);
	virtual void visitClassDecl(const ClassDeclPtr&);
	virtual void visitClassDefStart(const ClassDefPtr&);

    private:

	Output& H;
	Output& C;

	std::string _dllExport;
    };
};

}

#endif
