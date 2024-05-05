#ifndef ST_OBJECTS_H
#define ST_OBJECTS_H

#include "stfunction.h"
#include "data_types/variable_map.h"

namespace satelit {

class STObjects {
    friend class Compiler;
public:
    static STObjects& Get();

    bool has_function(std::string_view name) const { return functions_.count(std::string(name)); }
    STFunction::SPtr get_function(const std::string& name) { return functions_.at(name); }
    void insertFuntion(std::string name, STFunction::SPtr func);
private:
    STObjects() = default;
    STObjects(const STObjects&) = delete;
    STObjects& operator=(const STObjects&) = delete;

    std::unordered_map<std::string, std::shared_ptr<STFunction>> functions_;
    data_types::VariableMap variabels_;
};


}
#endif
