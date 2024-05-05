#include "compiler.h"
#include "compile_visitor.h"
#include "exceptions/exceptions.h"

#include "antlr4-runtime.h"
#include "TLexer.h"
#include "TParser.h"

using namespace antlr4;

namespace satelit {

Compiler::Compiler(std::string_view text) {
    input_.load(std::string(text));
    lexer_ = std::make_shared<TLexer>(&input_);
    tokens_ = std::make_shared<CommonTokenStream>(lexer_.get());
    tokens_->fill();

    parser_ = std::make_shared<TParser>(tokens_.get());
    prog_ = parser_->program();

    CompileVisitor compiler;
    compiler.visit(prog_);
}

}