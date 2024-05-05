#ifndef COMPILEVISITOR_H
#define COMPILEVISITOR_H

#include "TParserBaseVisitor.h"
#include "data_types/variable_map.h"
#include "stfunction.h"

namespace satelit {

struct STObjects;

class CompileVisitor : public TParserBaseVisitor {
public:
    CompileVisitor() {};

    std::any visitProgram(TParser::ProgramContext *ctx) override;

    std::any visitFunc_def(TParser::Func_defContext *ctx) override;

    std::any visitFunc_var_in(TParser::Func_var_inContext *ctx) override;
    
    std::any visitFunc_var_out(TParser::Func_var_outContext* ctx) override;

private:
    STFunction::SPtr func_sptr;
    size_t order_{ 0 };
};


}
#endif
