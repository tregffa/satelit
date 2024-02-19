#include <gtest/gtest.h>
#include "interpreter.h"

using namespace satelit;
using namespace ::testing;

TEST(SimplePrograms, DISABLED_SimpleProgramm) {
    Interpreter interpreter;
    interpreter.Compile("a1 = 5 * 2 + 6 + 5 * 2; "
                    "b1 = 2 + 5;"
                    "c1 = a1 + b1;");
    auto& vars = interpreter.get_variabels();
    EXPECT_EQ(vars["a1"], 26);
    EXPECT_EQ(vars["b1"], 7);
    EXPECT_EQ(vars["c1"], 33);
}

TEST(SimplePrograms, DISABLED_ProgWhithFuncCall) {
    Interpreter interpreter;
    interpreter.Compile("a1 = MAX(5,3);");
    auto& vars = interpreter.get_variabels();
    EXPECT_EQ(vars["a1"], 5);
}

TEST(SimplePrograms, FunctionDefenition) {
    Interpreter interpreter;
    interpreter.Compile("FUNCTION A : INT\n"
                    "BEGIN\n"
                    "a1 = 5 + 3;\n"
                    "END_FUNCTION");
    auto& funcs = interpreter.get_functions();
    EXPECT_EQ(funcs.count("A"), 1);
}

TEST(SimplePrograms, FunctionVariableDefenition) {
    Interpreter interpreter;
    interpreter.Compile("FUNCTION A : INT\
                    VAR_INPUT\
                        n : INT;\
                    END_VAR\
                    BEGIN\
                    a1 = n + 3;\
                    END_FUNCTION");
    auto& vars= interpreter.get_variabels();
    EXPECT_EQ(vars.count("n"), 1);
}
