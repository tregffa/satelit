#include "runtime_visitor.h".h"
#include "stack_machine.h"
#include "interpreter.h"
#include <iostream>
#include <numeric>

namespace satelit {

StackMachine stack_;

RuntimeVisitor::RuntimeVisitor(GlobalData& data) :
    data_(data) {
}

std::any RuntimeVisitor::visitProgram(TParser::ProgramContext *ctx) {
    return visitChildren(ctx);
}

std::any RuntimeVisitor::visitStat(TParser::StatContext *ctx) {
    auto result = visitChildren(ctx);
    auto var_name = ctx->ID()->getText();
    data_.variables[var_name] = stack_.top();
    return result;
}

std::any RuntimeVisitor::visitExpr(TParser::ExprContext *ctx) {
    auto result = visitChildren(ctx);
    if (ctx->PLUS()){
        stack_.addition();
    } else if (ctx->MULT()){
        stack_.multiple();
    } else if (ctx->AND()){
        std::cout << "AND" << std::endl;
    } else if (ctx->func()){
        std::cout << "FUNC" << std::endl;
    } else if (ctx->NUM()){
        stack_.push(stoi(ctx->getText()));
    }
    return result;
}

std::any RuntimeVisitor::visitFunc(TParser::FuncContext *ctx) {
    std::cout << "Func need execute function" << std::endl;
    return visitChildren(ctx);
}

std::any RuntimeVisitor::visitFunc_def(TParser::Func_defContext *ctx) {
    return visitChildren(ctx);
}

void RuntimeVisitor::PrintVars() {
    for(auto& [name, value] : data_.variables){
        std::cout << name << "\t=\t" << value << std::endl;
    }
}

}
