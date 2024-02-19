include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        release-1.12.1
)
FetchContent_MakeAvailable(googletest)
add_library(GTest::GTest INTERFACE IMPORTED)
target_link_libraries(GTest::GTest INTERFACE gtest_main)

add_executable(satelit_tests
    main.cpp
    prog_test.cpp
    )

target_link_libraries(satelit_tests
 PRIVATE satelit antlr4_static Threads::Threads GTest::GTest)

add_test(satelit_gtests satelit_tests)
