#ifndef COMPILER_H
#define COMPILER_H

#include "st_objects.h"

namespace satelit {

class Compiler {
public:
    Compiler(std::string_view text);
private:
    TParser::ProgramContext* prog_;
    antlr4::ANTLRInputStream input_;
    std::shared_ptr<TLexer> lexer_;
    std::shared_ptr<TParser> parser_;
    std::shared_ptr<antlr4::CommonTokenStream> tokens_;
};


}
#endif
