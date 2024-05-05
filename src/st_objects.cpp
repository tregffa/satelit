#include "st_objects.h"

namespace satelit {

STObjects& STObjects::Get() {
    static STObjects instance;
    return instance;
}

void STObjects::insertFuntion(std::string name, STFunction::SPtr func) {
    functions_.emplace(std::move(name), func);
}


}