#ifndef COMPILEVISITOR_H
#define COMPILEVISITOR_H

#include "TParserBaseVisitor.h"

namespace satelit {

struct GlobalData;

class CompileVisitor : public TParserBaseVisitor {
public:
    CompileVisitor(GlobalData& data);

    std::any visitProgram(TParser::ProgramContext *ctx) override;

    std::any visitStat(TParser::StatContext *ctx) override;

    std::any visitExpr(TParser::ExprContext *ctx) override;

    std::any visitFunc(TParser::FuncContext *ctx) override;

    std::any visitFunc_def(TParser::Func_defContext *ctx) override;

    std::any visitFunc_var_in(TParser::Func_var_inContext *ctx) override;

    void PrintVars();
private:
    GlobalData& data_;
};


}
#endif
