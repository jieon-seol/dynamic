#include "Define.h"
#include <vector>


class Operator {
public:
	virtual ~Operator() {};
	virtual void operate(std::vector<EmployeeInfo>* pDb, ParserResult parserResult) = 0;
	void addDataBase(EmployeeInfo employeeInfo);
protected:
	std::vector<EmployeeInfo>* pdataBase;
};


class AddOperator : public Operator {
public:
	void operate(std::vector<EmployeeInfo>* pDb, ParserResult parserResult) override;
};

class DeleteOperator : public Operator {
public:
	void operate(std::vector<EmployeeInfo>* pDb, ParserResult parserResult) override;
};

class SearchOperator : public Operator {
public:
	void operate(std::vector<EmployeeInfo>* pDb, ParserResult parserResult) override;
};

class ModifyOperator : public Operator {
public:
	void operate(std::vector<EmployeeInfo>* pDb, ParserResult parserResult) override;
};




class IFactoryOperator {
public:
	virtual Operator* getOperator(ParserResult& parserResult) = 0;
	virtual ~IFactoryOperator() {};
};

class FactoryOperator : public IFactoryOperator {
public:
	FactoryOperator();
	Operator* getOperator(ParserResult& parserResult) override;
protected:
	Operator* pAddOperator_;
	Operator* pDeleteOperator_;
	Operator* pSearchOperator_;
	Operator* pModifyOperator_;
};
