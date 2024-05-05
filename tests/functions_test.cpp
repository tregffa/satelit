#include <gtest/gtest.h>
#include "compiler.h"

using namespace satelit;
using namespace ::testing;
using Poco::Dynamic::Var;

TEST(FunctionsTest, CompileAndRunSimpleFunction) {
    Compiler compiler(R"(
        FUNCTION retVal : INT
            retVal := 15;
        END_FUNCTION)");
    
    STFunction::SPtr st_function = STObjects::Get().get_function("retVal");

    int res = st_function->Run({});
    auto& out = st_function->get_variabels().get("retVal");
    EXPECT_EQ(out, 15);
}

TEST(FunctionsTest, RunFunctionInFunction) {
    Compiler compiler(R"( 
        FUNCTION foo : INT 
        VAR_INPUT
            x : INT;
            y : INT;
        END_VAR
            foo : = x + y;
        END_FUNCTION


        FUNCTION main : INT
            main : = foo(450, 550);
        END_FUNCTION)");
    
    STFunction::SPtr st_function = STObjects::Get().get_function("main");
    
    int res = st_function->Run({});
    EXPECT_EQ(res, 1000);
}