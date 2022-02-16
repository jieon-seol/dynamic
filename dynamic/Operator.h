#include "Define.h"
#include <iostream>
#include <vector>
#define ALREADY_INCLUDED_DATABASE 0

class Operator {
public:
	Operator(std::vector<EmployeeInfo>* pDb) :pdataBase_(pDb) {};
	virtual ~Operator() {};
	virtual void operate(std::vector<EmployeeInfo>* pSearchDb, ParserResult& parserResult) = 0;
	
protected:
	std::vector<EmployeeInfo>* pdataBase_;
};


class AddOperator : public Operator {
public:
	AddOperator(std::vector<EmployeeInfo>* pDb) :Operator(pDb) {};
	void operate(std::vector<EmployeeInfo>* pSearchedDb, ParserResult& parserResult) override;
	void addDataBase(EmployeeInfo inputEmployeeInfo);
};

class DeleteOperator : public Operator {
public:
	DeleteOperator(std::vector<EmployeeInfo>* pDb) :Operator(pDb) {};
	void operate(std::vector<EmployeeInfo>* pSearchedDb, ParserResult& parserResult) override;
};

class SearchOperator : public Operator {
public:
	SearchOperator(std::vector<EmployeeInfo>* pDb) :Operator(pDb) {};
	void operate(std::vector<EmployeeInfo>* pSearchedDb, ParserResult& parserResult) override;
};

class ModifyOperator : public Operator {
public:
	ModifyOperator(std::vector<EmployeeInfo>* pDb) :Operator(pDb) {};
	void operate(std::vector<EmployeeInfo>* pSearchedDb, ParserResult& parserResult) override;
};




class IFactoryOperator {
public:
	virtual Operator* getOperator(ParserResult& parserResult) = 0;
	virtual ~IFactoryOperator() {};
};

class FactoryOperator : public IFactoryOperator {
public:
	FactoryOperator(std::vector<EmployeeInfo>* pdataBase);
	Operator* getOperator(ParserResult& parserResult) override;
	~FactoryOperator() {
		delete pAddOperator_;
		delete pDeleteOperator_;
		delete pSearchOperator_;
		delete pModifyOperator_;
	};
protected:
	Operator* pAddOperator_;
	Operator* pDeleteOperator_;
	Operator* pSearchOperator_;
	Operator* pModifyOperator_;
};
