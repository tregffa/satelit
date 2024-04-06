#include "runtime_visitor.h"
#include "stack_machine.h"
#include "stfunction.h"
#include <iostream>
#include <numeric>

namespace satelit {

StackMachine stack_;

RuntimeVisitor::RuntimeVisitor(FunctionData& data) : name_(data.name_), 
    vars_(data.vars_) {
}

std::any RuntimeVisitor::visitProgram(TParser::ProgramContext *ctx) {
    return visitChildren(ctx);
}

std::any RuntimeVisitor::visitStat(TParser::StatContext *ctx) {
    auto result = visitChildren(ctx);
    auto var_name = ctx->ID()->getText();
    bool res = vars_.set(var_name, stack_.pop());
    return result;
}

std::any RuntimeVisitor::visitExpr(TParser::ExprContext *ctx) {
    auto result = visitChildren(ctx);
    if (ctx->ID()) {
        stack_.push(vars_.get(ctx->getText()));
    } else if (ctx->PLUS()) {
        stack_.addition();
    } else if (ctx->MULT()){
        stack_.multiple();
    } else if (ctx->AND()){
        std::cout << "AND" << std::endl;
    } else if (ctx->func()){
        std::cout << "FUNC" << std::endl;
    }
    return result;
}

std::any RuntimeVisitor::visitNumber(TParser::NumberContext* ctx) {
    if (ctx->DEC()) {
        stack_.push(stoi(ctx->getText()));
    } else if (ctx->FLOAT()) {
        stack_.push(stof(ctx->getText()));
    }
    return visitChildren(ctx);
}

std::any RuntimeVisitor::visitFunc(TParser::FuncContext *ctx) {
    std::cout << "Func need execute function" << std::endl;
    visitChildren(ctx);
    return std::any{};
}

std::any RuntimeVisitor::visitFunc_def(TParser::Func_defContext *ctx) {
    return visitChildren(ctx);
}

void RuntimeVisitor::PrintVars() {
    //for(auto& [name, value] : vars_){
    //    std::cout << name << "\t=\t" << value << std::endl;
    //}
}

}
