#include "compile_visitor.h"
#include "stfunction.h"
#include <iostream>
#include <numeric>
#include "exceptions/exceptions.h"

namespace satelit {

CompileVisitor::CompileVisitor(FunctionData& data) :
    data_(data) {
}

std::any CompileVisitor::visitProgram(TParser::ProgramContext *ctx) {
    return visitChildren(ctx);
}

std::any CompileVisitor::visitStat(TParser::StatContext *ctx) {
    auto var_name = ctx->ID()->getText();
    if (!data_.vars_.count(var_name)) throw UndefinedVariable();
    return visitChildren(ctx);
}

std::any CompileVisitor::visitExpr(TParser::ExprContext *ctx) {
    return visitChildren(ctx);
}

std::any CompileVisitor::visitFunc(TParser::FuncContext *ctx) {
    std::cout << "Func" << std::endl;
    return visitChildren(ctx);
}

std::any CompileVisitor::visitFunc_def(TParser::Func_defContext *ctx) {
    //STFunction function(std::move(ctx->body->getText()));
    //data_.functions.emplace(ctx->name->getText(), std::move(function));
    data_.name_ = ctx->name->getText();
    bool res = data_.vars_.insert(data_.name_, 0);
    return visitChildren(ctx);
}

std::any CompileVisitor::visitFunc_var_in(TParser::Func_var_inContext *ctx) {
    for (auto& var_name : ctx->ID()) {
        if (!data_.vars_.insert(var_name->getText(), 0)) {
            throw DoubleDefenition();
        }
    }
    return visitChildren(ctx);
}

}
