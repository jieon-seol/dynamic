#include "Operator.h"


void AddOperator::operate(const std::vector<EmployeeInfo>* pSearchedDb, const ParserResult& parserResult) {
	if (pSearchedDb->size() == ALREADY_INCLUDED_DATABASE) {
		throw std::invalid_argument("ERROR: Already included database");
		return;
	}
	addDataBase(parserResult.info);
	return;
}

void AddOperator::addDataBase(const EmployeeInfo& inputEmployeeInfo) {
	pdataBase_->emplace_back(inputEmployeeInfo);
	return;
}


void DeleteOperator::operate(const std::vector<EmployeeInfo>* pSearchedDb, const ParserResult& parserResult) {
	for (const auto& searchedInfo : *pSearchedDb) {
		for (unsigned int i = 0; i < (*pdataBase_).size(); i++) {
			if ((*pdataBase_)[i].employeeNum == searchedInfo.employeeNum) {
				pdataBase_->erase((*pdataBase_).begin() + i);
				break;
			}
		}
	}
	return;
}


void SearchOperator::operate(const std::vector<EmployeeInfo>* pSearchedDb, const ParserResult& parserResult) {
	return;
}


void ModifyOperator::operate(const std::vector<EmployeeInfo>* pSearchedDb, const ParserResult& parserResult) {
	for (const auto& searchedInfo : *pSearchedDb) {
		for (auto& dataBaseInfo : *pdataBase_) {
			if (dataBaseInfo.employeeNum != searchedInfo.employeeNum) continue;

			if (parserResult.changeColumn == "name") {
				dataBaseInfo.name = parserResult.changeData;
			}
			else if (parserResult.changeColumn == "cl") {
				dataBaseInfo.cl = parserResult.changeData;
			}
			else if (parserResult.changeColumn == "phoneNum") {
				dataBaseInfo.phoneNum = parserResult.changeData;
			}
			else if (parserResult.changeColumn == "birthday") {
				dataBaseInfo.birthday = parserResult.changeData;
			}
			else if (parserResult.changeColumn == "certi") {
				dataBaseInfo.certi = parserResult.changeData;
			}
			break;
		}
	}
	return;
}

FactoryOperator::FactoryOperator(std::vector<EmployeeInfo>* pDb) {
	pAddOperator_ = new AddOperator(pDb);
	pDeleteOperator_ = new DeleteOperator(pDb);
	pSearchOperator_ = new SearchOperator(pDb);
	pModifyOperator_ = new ModifyOperator(pDb);
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




