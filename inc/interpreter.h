#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "antlr4-runtime.h"
#include "TLexer.h"
#include "TParser.h"
#include "TParserBaseVisitor.h"

namespace satelit {


class Interpreter {
public:
    Interpreter(){}
private:
    TParser::ProgramContext* prog_;
    antlr4::ANTLRInputStream input_;
    std::shared_ptr<TLexer> lexer_;
    std::shared_ptr<TParser> parser_;
    std::shared_ptr<antlr4::CommonTokenStream> tokens_;
    bool compiled_ { false };
};
}

#endif // INTERPRETER_H
