#ifndef RUNTIME_VISITOR_H
#define RUNTIME_VISITOR_H

#include "TParserBaseVisitor.h"
#include "data_types/variable_map.h"

namespace satelit {

struct FunctionData;

class RuntimeVisitor : public TParserBaseVisitor {
public:
    RuntimeVisitor(data_types::VariableMap& vars);

    std::any visitProgram(TParser::ProgramContext *ctx) override;

    std::any visitStat(TParser::StatContext *ctx) override;

    std::any visitExpr(TParser::ExprContext *ctx) override;

    std::any visitFunc(TParser::FuncContext *ctx) override;

    std::any visitNumber(TParser::NumberContext* ctx) override;

private:
    data_types::VariableMap& vars_;

};


}
#endif
