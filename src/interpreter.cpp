#include "interpreter.h"
#include "runtime_visitor.h"
#include "compile_visitor.h"

using namespace antlr4;

namespace satelit {

void Interpreter::Compile(std::string text) {
    input_.load(text);
    lexer_ = std::make_shared<TLexer>(&input_);
    tokens_ = std::make_shared<CommonTokenStream>(lexer_.get());
    tokens_->fill();

    parser_ = std::make_shared<TParser>(tokens_.get());
    prog_ = parser_->program();

    CompileVisitor compiler(data_);
    compiler.visit(prog_);
}

void Interpreter::Run(std::string_view main) {
    if(!compiled_) return;
    RuntimeVisitor runtime(data_, main);
    runtime.visit(prog_);
}

void STFunction::Run(GlobalData& data) {
    ANTLRInputStream input(raw_text_);
    TLexer lexer(&input);
    CommonTokenStream tokens(&lexer);

    tokens.fill();

    TParser parser(&tokens);
    TParser::ProgramContext* prog = parser.program();

    //RuntimeVisitor runtime(data);
    //runtime.visit(prog);
}

}
