#include "runtime_visitor.h"
#include "st_objects.h"
#include "stack_machine.h"
#include "stfunction.h"
#include <iostream>

namespace satelit {

StackMachine stack_;
using namespace data_types;
using namespace Poco::Dynamic;

RuntimeVisitor::RuntimeVisitor(VariableMap& vars) :  vars_(vars) {
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
    auto result = visitChildren(ctx);

    std::string name = ctx->ID()->getText();
    
    std::vector<Var> args;
    for (int i = ctx->expr().size() - 1; i >= 0; i--) {
        args.push_back(stack_.pop());
    }
    STFunction::SPtr func = STObjects::Get().get_function(name);
    auto value = func->Run(args);
    stack_.push(value);

    return result;
}


}
