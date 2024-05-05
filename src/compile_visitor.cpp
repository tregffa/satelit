#include "compile_visitor.h"
#include "st_objects.h"
#include <iostream>
#include <numeric>
#include "exceptions/exceptions.h"

namespace satelit {

using namespace Poco::Dynamic;

std::any CompileVisitor::visitProgram(TParser::ProgramContext *ctx) {
    return visitChildren(ctx);
}

std::any CompileVisitor::visitFunc_def(TParser::Func_defContext *ctx) {
    func_sptr = std::make_shared<STFunction>(ctx->name->getText(), ctx->body->getText());
    func_sptr->get_variabels().insert(ctx->name->getText(), 0);

    auto ret = visitChildren(ctx);
    STObjects::Get().insertFuntion(ctx->name->getText(), func_sptr);
    return ret;
}

std::any CompileVisitor::visitFunc_var_in(TParser::Func_var_inContext *ctx) {
    auto& variabels = func_sptr->get_variabels();
    for (size_t i = 0; i < ctx->ID().size(); i++) {
        auto name = ctx->ID(i)->getText();
        if(!variabels.insert(name, 0)) throw DoubleDefenition();
    }
    return visitChildren(ctx);
}

std::any CompileVisitor::visitFunc_var_out(TParser::Func_var_outContext* ctx) {
    auto& variabels = func_sptr->get_variabels();

    for (size_t i = 0; i < ctx->ID().size(); i++) {
        auto name = ctx->ID(i)->getText();
        if (!variabels.insert(name, 0)) throw DoubleDefenition();
    }
    return visitChildren(ctx);
}

}
