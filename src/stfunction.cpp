#include "stfunction.h"
#include "runtime_visitor.h"
#include "compile_visitor.h"
#include "exceptions/exceptions.h"
#include "st_objects.h"


using namespace antlr4;
using namespace Poco::Dynamic;

namespace satelit {
STFunction::STFunction(std::string name, std::string text) : 
    name_(std::move(name)), body_(std::move(text)) {
}

void STFunction::Compile(const std::string& text) {
    input_.load(text);
    lexer_ = std::make_shared<TLexer>(&input_);
    tokens_ = std::make_shared<CommonTokenStream>(lexer_.get());
    tokens_->fill();

    parser_ = std::make_shared<TParser>(tokens_.get());
    prog_ctx_ = parser_->program();
}

Var STFunction::Run(const std::vector<Var>& args) {
    if (!compiled_) Compile(body_);

    for (size_t i = 0; i < args.size(); i++) {
        vars_.set(i + 1, args[i]);
    }

    RuntimeVisitor runtime(vars_);
    runtime.visit(prog_ctx_);

    return vars_.get(name_);
}

}
