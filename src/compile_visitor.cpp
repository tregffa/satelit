#include "compile_visitor.h".h"
#include "interpreter.h"
#include <iostream>
#include <numeric>

namespace satelit {

CompileVisitor::CompileVisitor(GlobalData& data) :
    data_(data) {
}

std::any CompileVisitor::visitProgram(TParser::ProgramContext *ctx) {
    return visitChildren(ctx);
}

std::any CompileVisitor::visitStat(TParser::StatContext *ctx) {
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
    STFunction function(std::move(ctx->body->getText()));
    data_.functions.emplace(ctx->name->getText(), std::move(function));
    return visitChildren(ctx);
}

}
