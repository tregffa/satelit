#include "data_types/variable_map.h"

using namespace Poco::Dynamic;

namespace satelit::data_types {

bool VariableMap::insert(std::string name, Var value) {
    if (names_.count(name)) return false;
    
    values_.push_back(value);
    names_.emplace(std::move(name),values_.size() - 1);
    return true;
}

const Var& VariableMap::get(std::string_view name) const {
    int position = names_.at(std::string(name));
    return values_[position];
}

const Var& VariableMap::get(int position) const {
    return values_[position];
}

bool VariableMap::set(std::string_view name, Var value) {
    std::string key(name);
    if (!names_.count(key)) return false;
    int position = names_.at(key);
    values_[position] = value;
    return true;
}

bool VariableMap::set(size_t index, Var value) {
    if (index >= values_.size()) return false;
    values_[index] = value;
    return false;
}

}
