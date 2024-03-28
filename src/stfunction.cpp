#include "stfunction.h"
#include "runtime_visitor.h"
#include "compile_visitor.h"
#include "exceptions/exceptions.h"


using namespace antlr4;

namespace satelit {

void STFunction::Compile(std::string text) {
    input_.load(text);
    lexer_ = std::make_shared<TLexer>(&input_);
    tokens_ = std::make_shared<CommonTokenStream>(lexer_.get());
    tokens_->fill();

    parser_ = std::make_shared<TParser>(tokens_.get());
    prog_ = parser_->program();

    CompileVisitor compiler(data_);
    compiler.visit(prog_);
    compiled_ = true;
}

Poco::Dynamic::Var STFunction::Run(const std::vector<int>& args) {
    if (!compiled_) throw NotCompiled();
    for (size_t i = 0; i < args.size(); i++) {
        data_.vars_.set(i + 1, args[i]);
    }
    RuntimeVisitor runtime(data_);
    runtime.visit(prog_);
    return data_.vars_.get(data_.name_);
}

}
