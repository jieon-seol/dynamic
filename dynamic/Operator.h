#include "Define.h"
#include <iostream>
#include <map>
#define ALREADY_INCLUDED_DATABASE 1

class Operator {
public:
	Operator(std::map<std::string, EmployeeInfo>* pDb) :pdataBase_(pDb) {};
	virtual ~Operator() {};
	virtual void operate(const std::map<std::string, EmployeeInfo>* pSearchDb, const ParserResult& parserResult) = 0;
	
protected:
	std::map<std::string, EmployeeInfo>* pdataBase_;
};


class AddOperator : public Operator {
public:
	AddOperator(std::map<std::string, EmployeeInfo>* pDb) :Operator(pDb) {};
	void operate(const std::map<std::string, EmployeeInfo>* pSearchedDb, const ParserResult& parserResult) override;
private:
	void addDataBase(const EmployeeInfo& inputEmployeeInfo);
};

class DeleteOperator : public Operator {
public:
	DeleteOperator(std::map<std::string, EmployeeInfo>* pDb) :Operator(pDb) {};
	void operate(const std::map<std::string, EmployeeInfo>* pSearchedDb, const ParserResult& parserResult) override;
};

class SearchOperator : public Operator {
public:
	SearchOperator(std::map<std::string, EmployeeInfo>* pDb) :Operator(pDb) {};
	void operate(const std::map<std::string, EmployeeInfo>* pSearchedDb, const ParserResult& parserResult) override;
};

class ModifyOperator : public Operator {
public:
	ModifyOperator(std::map<std::string, EmployeeInfo>* pDb) :Operator(pDb) {};
	void operate(const std::map<std::string, EmployeeInfo>* pSearchedDb, const ParserResult& parserResult) override;
};




class IFactoryOperator {
public:
	virtual Operator* getOperator(ParserResult& parserResult) = 0;
	virtual ~IFactoryOperator() {};
};

class FactoryOperator : public IFactoryOperator {
public:
	FactoryOperator(std::map<std::string, EmployeeInfo>* pdataBase);
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
