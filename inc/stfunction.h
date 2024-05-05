#ifndef STFUNCTION_H
#define STFUNCTION_H

#include "antlr4-runtime.h"
#include "TLexer.h"
#include "TParser.h"
#include "TParserBaseVisitor.h"
#include "data_types/variable_map.h"

#include "iprogramm.h"

namespace satelit {

class STFunction : public IProgramm {
public:
    using SPtr = std::shared_ptr<STFunction>;

    STFunction(std::string name, std::string text);
    virtual ~STFunction() {};

    void Compile(const std::string& text) override;
    Poco::Dynamic::Var Run(const std::vector<Poco::Dynamic::Var>& args) override;

    data_types::VariableMap& get_variabels() { return vars_; }
    std::string get_name() { return name_; }
    std::string get_body() { return body_; }
protected:
    antlr4::ANTLRInputStream input_;
    std::shared_ptr<TLexer> lexer_;
    std::shared_ptr<TParser> parser_;
    std::shared_ptr<antlr4::CommonTokenStream> tokens_;
    TParser::ProgramContext* prog_ctx_;

private:
    std::string name_;
    std::string body_;

private:
    data_types::VariableMap vars_;
    bool compiled_{ false };
};

}

#endif 
