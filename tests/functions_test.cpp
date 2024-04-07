#include <gtest/gtest.h>
#include "stfunction.h"

using namespace satelit;
using namespace ::testing;
using Poco::Dynamic::Var;

TEST(FunctionsTest, VarOutput) {
    STFunction st_function;
    st_function.Compile("\
        FUNCTION retVal : INT\n\
            VAR_OUTPUT\n\
                a : INT;\n\
            END_VAR\n\
        BEGIN\n\
            a := 15; \
        END_FUNCTION");
    int res = st_function.Run({});
    auto& out = st_function.get_out_vars().get("a");
    EXPECT_EQ(out, 15);
}