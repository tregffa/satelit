#ifndef IPROGRAMM_H
#define IPROGRAMM_H

#include <Poco/Dynamic/Var.h>

namespace satelit {

class IProgramm {
public:
	virtual ~IProgramm() {};

	virtual void Compile(std::string text) = 0;
	virtual Poco::Dynamic::Var Run(const std::vector<int>& args) = 0;
};

}

#endif 
