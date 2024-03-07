#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "antlr4-runtime.h"
#include "TLexer.h"
#include "TParser.h"
#include "TParserBaseVisitor.h"

namespace satelit {

struct GlobalData;

class STFunction {
public:
    STFunction(std::string raw_text) : raw_text_(std::move(raw_text)){}
    void Run(GlobalData& data);
private:
    std::string raw_text_;
};

struct GlobalData {
    std::unordered_map<std::string, int> variables;
    std::unordered_map<std::string, STFunction> functions;
};

class Interpreter {
public:
    Interpreter(){}
    void Compile(std::string text);
    void Run(std::string_view main);
    std::unordered_map<std::string, int>& get_variabels() {return data_.variables;}
    std::unordered_map<std::string, STFunction>& get_functions() {return data_.functions;}
private:
    GlobalData data_;
    TParser::ProgramContext* prog_;
    antlr4::ANTLRInputStream input_;
    std::shared_ptr<TLexer> lexer_;
    std::shared_ptr<TParser> parser_;
    std::shared_ptr<antlr4::CommonTokenStream> tokens_;
    bool compiled_ { false };
};
}

#endif // INTERPRETER_H
