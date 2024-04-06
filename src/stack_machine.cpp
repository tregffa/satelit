#include "stack_machine.h"
#include <iostream>

using namespace Poco::Dynamic;

namespace satelit {

void StackMachine::addition() {
    auto [left, right] = top_pair();
    stack_.push(left + right);
}

void StackMachine::multiple() {
    auto [left, right] = top_pair();
    stack_.push(left * right);
}

void StackMachine::push(Var value) {
    stack_.push(value);
}

Var StackMachine::pop() {
    Var top = stack_.top();
    stack_.pop();
    return top;
}

Var StackMachine::top() {
    return stack_.top();
}

std::pair<Var, Var> StackMachine::top_pair() {
    Var left = stack_.top();
    stack_.pop();
    Var right = stack_.top();
    stack_.pop();
    return {left, right};
}

} // namespace satelit

