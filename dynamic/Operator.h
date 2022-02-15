#include "Define.h"
#include <vector>


class Operator {
public:
	
	virtual Operator* operate(std::vector<EmployeeInfo> employeeInfo, ParserResult parserResult) = 0;
};


class AddOperator : public Operator {
public:
	Operator* operate(std::vector<EmployeeInfo> employeeInfo, ParserResult parserResult);
};

class DeleteOperator : public Operator {
public:
	Operator* operate(std::vector<EmployeeInfo> employeeInfo, ParserResult parserResult);
};

class SearchOperator : public Operator {
public:
	Operator* operate(std::vector<EmployeeInfo> employeeInfo, ParserResult parserResult);
};

class ModifyOperator : public Operator {
public:
	Operator* operate(std::vector<EmployeeInfo> employeeInfo, ParserResult parserResult);
};




class IFactoryOperator {
public:
	virtual Operator* createOperator(const ParserResult& parserResult) = 0;
};

class FactoryOperator : public IFactoryOperator {
public:
	Operator* createOperator(const ParserResult& parserResult) override;
};
