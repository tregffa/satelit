#include <gtest/gtest.h>
#include "compiler.h"


using namespace satelit;
using namespace ::testing;
using Poco::Dynamic::Var;

TEST(ArifmeticsTest, PlusIntOperation) {
    Compiler compiler(R"(
        FUNCTION plus : INT
        VAR_INPUT
            x : INT;
            y : INT;
        END_VAR
            plus := x + y;
        END_FUNCTION)");

    STFunction::SPtr st_function = STObjects::Get().get_function("plus");
    
    int result = st_function->Run({550, 450});
    EXPECT_EQ(result, 1000);
}