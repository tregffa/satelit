#include "stack_machine.h"

namespace satelit {

void StackMachine::addition() {
    auto [left, right] = top_pair();
    stack_.push(left + right);
}

void StackMachine::multiple() {
    auto [left, right] = top_pair();
    stack_.push(left * right);
}

void StackMachine::push(int value) {
    stack_.push(value);
}

int StackMachine::pop() {
    int top = stack_.top();
    stack_.pop();
    return top;
}

int StackMachine::top() {
    return stack_.top();
}

std::pair<int, int> StackMachine::top_pair() {
    int left = stack_.top();
    stack_.pop();
    int right = stack_.top();
    stack_.pop();
    return {left, right};
}

} // namespace satelit

