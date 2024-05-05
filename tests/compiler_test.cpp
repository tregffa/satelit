#include <gtest/gtest.h>
#include "compiler.h"

using namespace satelit;
using namespace ::testing;
using Poco::Dynamic::Var;

TEST(CompilerTest, CompileAndCreateSTFunction) {
    Compiler compiler(R"(
        FUNCTION retVal : VOID
        VAR_INPUT
            x : INT;
        END_VAR
        VAR_OUTPUT
            a : INT;
        END_VAR
            a := x;
        END_FUNCTION)");
    auto& objects = compiler.get_global_objects();
    EXPECT_TRUE(objects.has_function("retVal"));
}

TEST(CompilerTest, CompileAndCreateSeveralSTFunctions) {
    
    Compiler compiler(R"(
        FUNCTION foo : INT
        VAR_INPUT
            x : INT;
        END_VAR
            foo := 15;
        END_FUNCTION

        FUNCTION bar : INT
        VAR_INPUT
            x : INT;
        END_VAR
        VAR_OUTPUT
            a : INT;
        END_VAR
            bar := 15;
        END_FUNCTION)");

    auto& objects = compiler.get_global_objects();
    
    auto foo = objects.get_function("foo");
    EXPECT_EQ(foo->get_name(), "foo");

    auto bar = objects.get_function("bar");
    EXPECT_EQ(bar->get_name(), "bar");
}


