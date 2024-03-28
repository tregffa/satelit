#ifndef STFUNCTION_H
#define STFUNCTION_H

#include "antlr4-runtime.h"
#include "TLexer.h"
#include "TParser.h"
#include "TParserBaseVisitor.h"
#include "data_types/variable_map.h"

#include "iprogramm.h"

namespace satelit {

	struct FunctionData {
		std::string name_;
		data_types::VariableMap vars_;
	};

	class STFunction : public IProgramm {
	public:
		STFunction() {};
		virtual ~STFunction() {};

		void Compile(std::string text) override;
		Poco::Dynamic::Var Run(const std::vector<int>& args) override;

		data_types::VariableMap& get_variabels() { return data_.vars_; }
	protected:
		TParser::ProgramContext* prog_;
		antlr4::ANTLRInputStream input_;
		std::shared_ptr<TLexer> lexer_;
		std::shared_ptr<TParser> parser_;
		std::shared_ptr<antlr4::CommonTokenStream> tokens_;
		FunctionData data_;
		bool compiled_{ false };
	};

}

#endif 
