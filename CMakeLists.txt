# req# minimum required CMAKE version
CMAKE_MINIMUM_REQUIRED(VERSION 3.7 FATAL_ERROR)
project(satelit)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

# compiler must be 20
set(CMAKE_CXX_STANDARD 20)

# required if linking to static library
add_definitions(-DANTLR4CPP_STATIC)

set(ANTLR4_WITH_STATIC_CRT OFF)

find_package(antlr4-runtime REQUIRED)
find_package(Poco REQUIRED)

# add antrl4cpp artifacts to project environment
include_directories(${ANTLR4_INCLUDE_DIRS})
set(ANTLR_EXECUTABLE ${PROJECT_SOURCE_DIR}/thirdparty/antlr/antlr-4.12.0-complete.jar)

# add macros to generate ANTLR Cpp code from grammar
find_package(ANTLR REQUIRED)

set(THREADS_PREFER_PTHREAD_FLAG ON)
find_package(Threads REQUIRED)

# Call macro to add lexer and grammar to your build dependencies.
antlr_target(SampleGrammarLexer TLexer.g4 LEXER
             PACKAGE satelit)

antlr_target(SampleGrammarParser TParser.g4 PARSER VISITOR
             PACKAGE satelit
             DEPENDS_ANTLR SampleGrammarLexer
             COMPILE_FLAGS -lib ${ANTLR_SampleGrammarLexer_OUTPUT_DIR}
             )


# include generated files in project environment
include_directories(${ANTLR_SampleGrammarLexer_OUTPUT_DIR})
include_directories(${ANTLR_SampleGrammarParser_OUTPUT_DIR})
include_directories(${PROJECT_SOURCE_DIR}/inc})

# add generated grammar to demo binary target
add_library(satelit STATIC
    src/interpreter.cpp
    src/runtime_visitor.cpp
    src/stack_machine.cpp
    src/compile_visitor.cpp
    ${ANTLR_SampleGrammarLexer_CXX_OUTPUTS}
    ${ANTLR_SampleGrammarParser_CXX_OUTPUTS}  "inc/stfunction.h" "src/stfunction.cpp" "inc/exceptions/runtime_errors.h" "inc/exceptions/exceptions.h" "inc/data_types/variable_map.h" "src/data_types/variable_map.cpp")

target_include_directories(satelit PUBLIC ${PROJECT_SOURCE_DIR}/inc)
target_link_libraries(satelit antlr4_static Poco::Poco Threads::Threads)

add_subdirectory(tests)