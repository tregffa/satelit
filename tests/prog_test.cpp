#include <gtest/gtest.h>
#include "interpreter.h"

using namespace satelit;
using namespace ::testing;

TEST(SimplePrograms, CompileFunction) {
    Interpreter interpreter;
    interpreter.Compile("FUNCTION main : INT\n"
                    "BEGIN\n"
                    "main = 5 + 3;\n"
                    "END_FUNCTION");
    interpreter.Run("main");
    auto& vars = interpreter.get_variabels();
    EXPECT_EQ(vars["a1"], 8);
}

TEST(SimplePrograms, DISABLED_RunFunction) {
    Interpreter interpreter;
    interpreter.Compile("FUNCTION main : INT\n"
                    "BEGIN\n"
                    "main = 5 + 3;\n"
                    "END_FUNCTION");
    interpreter.Run("main");
    auto& vars = interpreter.get_variabels();
    EXPECT_EQ(vars["a1"], 8);
}

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

TEST(SimplePrograms, DISABLED_FunctionDefenition) {
    Interpreter interpreter;
    interpreter.Compile("FUNCTION A : INT\n"
                    "BEGIN\n"
                    "a1 = 5 + 3;\n"
                    "END_FUNCTION");
    auto& funcs = interpreter.get_functions();
    EXPECT_EQ(funcs.count("A"), 1);
}

TEST(SimplePrograms, DISABLED_FunctionVariableDefenition) {
    Interpreter interpreter;
    interpreter.Compile("FUNCTION A : INT\
                    VAR_INPUT\
                        n : INT;\
                        n1 : INT;\
                    END_VAR\
                    BEGIN\
                    a1 = n + 3;\
                    END_FUNCTION");
    auto& vars= interpreter.get_variabels();
    EXPECT_EQ(vars.count("n"), 1);
}

TEST(SimplePrograms, DISABLED_FunctionCall) {
    Interpreter interpreter;
    interpreter.Compile("FUNCTION A : INT\n"
                    "BEGIN\n"
                    "a1 = 5 + 3;\n"
                    "return a1;"
                    "END_FUNCTION");
    interpreter.Compile("A()");

}
