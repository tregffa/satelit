#include <gtest/gtest.h>
#include "stfunction.h"

using namespace satelit;
using namespace ::testing;
using Poco::Dynamic::Var;

TEST(SimplePrograms, CompileAndRunFunction) {
    STFunction st_function;
    st_function.Compile("FUNCTION main : INT\n"
                    "BEGIN\n"
                    "main = 5 + 3 + 2;\n"
                    "END_FUNCTION");
    int res = st_function.Run({});
    EXPECT_EQ(res, 10);
}

TEST(SimplePrograms, ProvideInputVars) {
    STFunction st_function;
    st_function.Compile("\
        FUNCTION sum : INT\n\
            VAR_INPUT\n\
                a : INT;\n\
                b: INT;\n\
            END_VAR\n\
        BEGIN\n\
            sum = a + b; \
        END_FUNCTION");
    auto& vars = st_function.get_variabels();
    EXPECT_TRUE(vars.count("a"));
    EXPECT_TRUE(vars.count("b"));
    EXPECT_TRUE(vars.count("sum"));

    int res = st_function.Run({ 4, 10 });
    EXPECT_EQ(res, 14);
}

TEST(SimplePrograms, ProvideRealTypes) {
    STFunction st_function;
    st_function.Compile("FUNCTION main : REAL\n"
        "BEGIN\n"
        "main = 5.5 + 3.6;\n"
        "END_FUNCTION");
    auto& vars = st_function.get_variabels();

    float res = st_function.Run({});
    EXPECT_NEAR(res, 9.1, 0.01);
}

TEST(SimplePrograms, ProvideInputDifferentTypesVars) {
    STFunction st_function;
    st_function.Compile("\
        FUNCTION sum : REAL\n\
            VAR_INPUT\n\
                a : REAL;\n\
                b: REAL;\n\
            END_VAR\n\
        BEGIN\n\
            sum = a + b; \
        END_FUNCTION");
    auto& vars = st_function.get_variabels();
    EXPECT_TRUE(vars.count("a"));
    EXPECT_TRUE(vars.count("b"));
    EXPECT_TRUE(vars.count("sum"));

    Var res = st_function.Run({ 4, 10.5 });
    EXPECT_EQ(res, 14.5);
}

//
//TEST(SimplePrograms, DISABLED_SimpleProgramm) {
//    Interpreter interpreter;
//    interpreter.Compile("a1 = 5 * 2 + 6 + 5 * 2; "
//                    "b1 = 2 + 5;"
//                    "c1 = a1 + b1;");
//    auto& vars = interpreter.get_variabels();
//    EXPECT_EQ(vars["a1"], 26);
//    EXPECT_EQ(vars["b1"], 7);
//    EXPECT_EQ(vars["c1"], 33);
//}
//
//TEST(SimplePrograms, DISABLED_ProgWhithFuncCall) {
//    Interpreter interpreter;
//    interpreter.Compile("a1 = MAX(5,3);");
//    auto& vars = interpreter.get_variabels();
//    EXPECT_EQ(vars["a1"], 5);
//}
//
//TEST(SimplePrograms, DISABLED_FunctionDefenition) {
//    Interpreter interpreter;
//    interpreter.Compile("FUNCTION A : INT\n"
//                    "BEGIN\n"
//                    "a1 = 5 + 3;\n"
//                    "END_FUNCTION");
//    auto& funcs = interpreter.get_functions();
//    EXPECT_EQ(funcs.count("A"), 1);
//}
//
//TEST(SimplePrograms, DISABLED_FunctionVariableDefenition) {
//    Interpreter interpreter;
//    interpreter.Compile("FUNCTION A : INT\
//                    VAR_INPUT\
//                        n : INT;\
//                        n1 : INT;\
//                    END_VAR\
//                    BEGIN\
//                    a1 = n + 3;\
//                    END_FUNCTION");
//    auto& vars= interpreter.get_variabels();
//    EXPECT_EQ(vars.count("n"), 1);
//}
//
//TEST(SimplePrograms, DISABLED_FunctionCall) {
//    Interpreter interpreter;
//    interpreter.Compile("FUNCTION A : INT\n"
//                    "BEGIN\n"
//                    "a1 = 5 + 3;\n"
//                    "return a1;"
//                    "END_FUNCTION");
//    interpreter.Compile("A()");
//
//}
