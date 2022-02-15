#include "Define.h"
#include <vector>


class Operator {
public:
	
	virtual int operate(ParserResult parserResult) = 0;
};


class AddOperator : public Operator {
public:
	int operate(ParserResult parserResult);
};

class DeleteOperator : public Operator {
public:
	int operate(ParserResult parserResult);
};

class SearchOperator : public Operator {
public:
	int operate(ParserResult parserResult);
};

class ModifyOperator : public Operator {
public:
	int operate(ParserResult parserResult);
};




class IFactoryOperator {
public:
	virtual Operator* createOperator(const ParserResult& parserResult) = 0;
};

class FactoryOperator : public IFactoryOperator {
public:
	Operator* createOperator(const ParserResult& parserResult) override;
};
