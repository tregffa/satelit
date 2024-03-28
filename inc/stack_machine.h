#ifndef STACK_MACHINE_H
#define STACK_MACHINE_H

#include <stack>
#include <Poco/Dynamic/Var.h>

namespace satelit {


class StackMachine {
public:
    StackMachine(){}

    void addition();
    void multiple();
    void push(Poco::Dynamic::Var value);
    Poco::Dynamic::Var pop();
    Poco::Dynamic::Var top();
private:
    std::pair<Poco::Dynamic::Var, Poco::Dynamic::Var> top_pair();
    std::stack<Poco::Dynamic::Var> stack_;
};


}
#endif // STACK_MACHINE_H
