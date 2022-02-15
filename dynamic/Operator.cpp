#include "Operator.h"


void Operator::addDataBase(EmployeeInfo employeeInfo) {
	dataBase.emplace_back(employeeInfo);
}


void AddOperator::operate(std::vector<EmployeeInfo>* pDb, ParserResult parserResult) {
	return;
}


void DeleteOperator::operate(std::vector<EmployeeInfo>* pDb, ParserResult parserResult) {
	return;
}


void SearchOperator::operate(std::vector<EmployeeInfo>* pDb, ParserResult parserResult) {
	return;
}


void ModifyOperator::operate(std::vector<EmployeeInfo>* pDb, ParserResult parserResult) {
	return;
}

FactoryOperator::FactoryOperator() {
	pAddOperator_ = new AddOperator();
	pDeleteOperator_ = new DeleteOperator();
	pSearchOperator_ = new SearchOperator();
	pModifyOperator_ = new ModifyOperator();
}

Operator* FactoryOperator::getOperator(ParserResult& parserResult) {


	Operator* retOperator = nullptr;
	switch (parserResult.operationType)
	{
	case OPERATION_TYPE::ADD:
		retOperator = pAddOperator_;
	case OPERATION_TYPE::DEL:
		retOperator = pDeleteOperator_;
	case OPERATION_TYPE::SCH:
		retOperator = pSearchOperator_;
	case OPERATION_TYPE::MOD:
		retOperator = pModifyOperator_;
	}
	return retOperator;
}




