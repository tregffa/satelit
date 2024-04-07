#ifndef COMPILEVISITOR_H
#define COMPILEVISITOR_H

#include "TParserBaseVisitor.h"

namespace satelit {

struct FunctionData;

class CompileVisitor : public TParserBaseVisitor {
public:
    CompileVisitor(FunctionData& data);

    std::any visitProgram(TParser::ProgramContext *ctx) override;

    std::any visitStat(TParser::StatContext *ctx) override;

    std::any visitExpr(TParser::ExprContext *ctx) override;

    std::any visitFunc(TParser::FuncContext *ctx) override;

    std::any visitFunc_def(TParser::Func_defContext *ctx) override;

    std::any visitFunc_var_in(TParser::Func_var_inContext *ctx) override;
    
    std::any visitFunc_var_out(TParser::Func_var_outContext* ctx) override;

    void PrintVars();
private:
    void insertVariable(TParser::TypeContext* type, std::string_view name);
    FunctionData& data_;
    size_t order_{ 0 };
};


}
#endif
