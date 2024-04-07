#ifndef STAELIT_ST_VARIABLE_H
#define STAELIT_ST_VARIABLE_H

#include <unordered_map>
#include <vector>
#include <Poco/Dynamic/Var.h>

namespace satelit::data_types {

    enum class Type {
        kVar,
        kInput,
        kOutput
    };

    class STVariable : public Poco::Dynamic::Var {
    public:
        STVariable() {}
    private:
        Type type{ kVar };


}

#endif