#include <exception>

namespace satelit {

class NotCompiled : public std::exception {
public:
    NotCompiled() {}
};

}
