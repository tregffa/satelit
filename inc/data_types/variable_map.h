#ifndef STAELIT_DATA_TYPES_VARIABLE_MAP_H
#define STAELIT_DATA_TYPES_VARIABLE_MAP_H

#include <unordered_map>
#include <vector>
#include <Poco/Dynamic/Var.h>

namespace satelit::data_types {

    class VariableMap {
    public:
        VariableMap() {}
        [[nodiscard]] bool insert(std::string name, Poco::Dynamic::Var value);
        
        [[nodiscard]] const Poco::Dynamic::Var& get(std::string_view name) const;
        [[nodiscard]] const Poco::Dynamic::Var& get(int position) const;
        
        [[nodiscard]] bool set(std::string_view name, Poco::Dynamic::Var value);
        bool set(size_t index, Poco::Dynamic::Var value);
        
        size_t size() { return values_.size(); }
        bool count(const std::string& str) { return names_.count(str); }
    
    private:
        std::unordered_map<std::string, Poco::Dynamic::Var> names_;
        std::vector<Poco::Dynamic::Var> values_;
    };

}

#endif