#ifndef RUNTIME_VISITOR_H
#define RUNTIME_VISITOR_H

#include "TParserBaseVisitor.h"

namespace satelit {

struct GlobalData;

class RuntimeVisitor : public TParserBaseVisitor {
public:
    RuntimeVisitor(GlobalData& data, std::string_view main);

    std::any visitProgram(TParser::ProgramContext *ctx) override;

    std::any visitStat(TParser::StatContext *ctx) override;

    std::any visitExpr(TParser::ExprContext *ctx) override;

    std::any visitFunc(TParser::FuncContext *ctx) override;

    std::any visitFunc_def(TParser::Func_defContext *ctx) override;

    void PrintVars();
private:
    GlobalData& data_;
    std::string main_;
};


}
#endif
