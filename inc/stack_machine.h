#ifndef STACK_MACHINE_H
#define STACK_MACHINE_H

#include <stack>

namespace satelit {


class StackMachine {
public:
    StackMachine(){}

    void addition();
    void multiple();
    void push(int value);
    int pop();
    int top();
private:
    std::pair<int, int> top_pair();
    std::stack<int> stack_;
};


}
#endif // STACK_MACHINE_H
