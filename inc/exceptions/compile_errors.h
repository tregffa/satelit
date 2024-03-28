#include <exception>

namespace satelit {

class UndefinedVariable : public std::exception {
public:
    UndefinedVariable() {}
};

class DoubleDefenition : public std::exception {
public:
    DoubleDefenition() {}
};

}
