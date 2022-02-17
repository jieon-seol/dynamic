#include "Operator.h"
#include "GlobalMethod.h"

void AddOperator::operate(const std::map<int, EmployeeInfo>* pSearchedDb, const ParserResult& parserResult) {
	if (pSearchedDb->size() == ALREADY_INCLUDED_DATABASE) {
		throw std::invalid_argument("ERROR: Already included database");
		return;
	}
	addDataBase(parserResult.info);
	return;
}

void AddOperator::addDataBase(const EmployeeInfo& inputEmployeeInfo) {
	int key = getKeyFromEmployeeNum(inputEmployeeInfo.employeeNum);
	(*pdataBase_)[key] = inputEmployeeInfo;
	return;
}


void DeleteOperator::operate(const std::map<int, EmployeeInfo>* pSearchedDb, const ParserResult& parserResult) {
	for (const auto& searchedInfo : (*pSearchedDb)) {
		(*pdataBase_).erase(searchedInfo.first);
	}
	return;
}


void SearchOperator::operate(const std::map<int, EmployeeInfo>* pSearchedDb, const ParserResult& parserResult) {
	return;
}


void ModifyOperator::operate(const std::map<int, EmployeeInfo>* pSearchedDb, const ParserResult& parserResult) {
	for (const auto& searchedInfo : (*pSearchedDb)) {
		if (parserResult.changeColumn == "name") {
			(*pdataBase_)[searchedInfo.first].name = parserResult.changeData;
		}
		else if (parserResult.changeColumn == "cl") {
			(*pdataBase_)[searchedInfo.first].cl = parserResult.changeData;
		}
		else if (parserResult.changeColumn == "phoneNum") {
			(*pdataBase_)[searchedInfo.first].phoneNum = parserResult.changeData;
		}
		else if (parserResult.changeColumn == "birthday") {
			(*pdataBase_)[searchedInfo.first].birthday = parserResult.changeData;
		}
		else if (parserResult.changeColumn == "certi") {
			(*pdataBase_)[searchedInfo.first].certi = parserResult.changeData;
		}
	}
	return;
}

FactoryOperator::FactoryOperator(std::map<int, EmployeeInfo>* pDb) {
	pAddOperator_ = new AddOperator(pDb);
	pDeleteOperator_ = new DeleteOperator(pDb);
	pSearchOperator_ = new SearchOperator(pDb);
	pModifyOperator_ = new ModifyOperator(pDb);
}

FactoryOperator::~FactoryOperator() {
	if (pAddOperator_) delete pAddOperator_;
	if (pDeleteOperator_) delete pDeleteOperator_;
	if (pAddOperator_) delete pSearchOperator_;
	if (pAddOperator_) delete pModifyOperator_;
};

Operator* FactoryOperator::getOperator(ParserResult& parserResult) {
	Operator* retOperator = nullptr;
	switch (parserResult.operationType)
	{
	case OPERATION_TYPE::ADD:
		retOperator = pAddOperator_;
		break;
	case OPERATION_TYPE::DEL:
		retOperator = pDeleteOperator_;
		break;
	case OPERATION_TYPE::SCH:
		retOperator = pSearchOperator_;
		break;
	case OPERATION_TYPE::MOD:
		retOperator = pModifyOperator_;
		break;
	}
	return retOperator;
}




