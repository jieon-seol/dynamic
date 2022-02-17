#include <iostream>
#include <vector>
#include <string>
#include "Searcher.h"
#include "GlobalMethod.h"

using namespace std;

map<string, EmployeeInfo> EmployeeNumSearcher::search(const ParserResult& parserResult) const {
	map<string, EmployeeInfo> searchedInfo;

	string key = getKeyFromEmployeeNum(parserResult.searchData);
	if ((*pDataBase_).count(key)) {
		searchedInfo[key] = (*pDataBase_)[key];
	}

	return searchedInfo;
}

map<string, EmployeeInfo> NameSearcher::search(const ParserResult& parserResult) const {
	string searchName = parserResult.searchData;
	OPTION2 nameOption = parserResult.option2;
	map<string, EmployeeInfo> searchedInfo;

	for (const auto& info : (*pDataBase_)) {
		if (parserResult.searchData == filterData(info.second.name, nameOption)) {
			searchedInfo[info.first] = info.second;
		}
	}

	return searchedInfo;
}

string NameSearcher::filterData(const string& name, const OPTION2 nameOption) const {
	if (nameOption == OPTION2::NONE) {
		return name;
	}

	vector<string> subName = splitString(name, ' ');
	if (subName.size() != MAX_SUB_NAME_COUNT) {
		throw invalid_argument("ERROR: Invalid Name");
	}

	if (nameOption == OPTION2::F) {
		return subName[LAST_NAME_INDEX];
	}

	if (nameOption == OPTION2::L) {
		return subName[FIRST_NAME_INDEX];
	}

	throw invalid_argument("ERROR: Invalid Name Option2");
}

map<string, EmployeeInfo> ClSearcher::search(const ParserResult& parserResult) const {
	map<string, EmployeeInfo> searchedInfo;

	for (const auto& info : (*pDataBase_)) {
		if (parserResult.searchData == info.second.cl) {
			searchedInfo[info.first] = info.second;
		}
	}

	return searchedInfo;
}

map<string, EmployeeInfo> PhoneNumberSearcher::search(const ParserResult& parserResult) const {
	string searchNumber = parserResult.searchData;
	OPTION2 numberOption = parserResult.option2;
	map<string, EmployeeInfo> searchedInfo;

	for (const auto& info : (*pDataBase_)) {
		if (parserResult.searchData == filterData(info.second.phoneNum, numberOption)) {
			searchedInfo[info.first] = info.second;
		}
	}

	return searchedInfo;
}

string PhoneNumberSearcher::filterData(const string& phoneNum, const OPTION2 numOption) const {
	if (numOption == OPTION2::NONE) {
		return phoneNum;
	}

	vector<string> subPhoneNum = splitString(phoneNum, '-');
	if (subPhoneNum.size() != MAX_SUB_PHONE_NUM_COUNT) {
		throw invalid_argument("ERROR: Invalid Phone Number");
	}

	if (numOption == OPTION2::M) {
		return subPhoneNum[MIDDLE_PHONE_NUM_INDEX];
	}

	if (numOption == OPTION2::L) {
		return subPhoneNum[LAST_PHONE_NUM_INDEX];
	}

	throw invalid_argument("ERROR: Invalid Phone Number Option2");
}

map<string, EmployeeInfo> BirthdaySearcher::search(const ParserResult& parserResult) const {
	string searchBirth = parserResult.searchData;
	OPTION2 birthOption = parserResult.option2;
	map<string, EmployeeInfo> searchedInfo;

	for (const auto& info : (*pDataBase_)) {
		if (parserResult.searchData == filterData(info.second.birthday, birthOption)) {
			searchedInfo[info.first] = info.second;
		}
	}

	return searchedInfo;
}

string BirthdaySearcher::filterData(const string& birthDay, const OPTION2 birthOption) const {
	if (birthOption == OPTION2::NONE) {
		return birthDay;
	}

	if (birthOption == OPTION2::Y) {
		return birthDay.substr(YEAR_START_INDEX, YEAR_NUM_COUNT);
	}
	
	if (birthOption == OPTION2::M) {
		return birthDay.substr(MONTH_START_INDEX, MONTH_NUM_COUNT);
	}
	
	if (birthOption == OPTION2::D) {
		return birthDay.substr(DAY_START_INDEX, DAY_NUM_COUNT);
	}

	throw invalid_argument("ERROR: Invalid Birthday Option2");
}

map<string, EmployeeInfo> CertiSearcher::search(const ParserResult& parserResult) const {
	map<string, EmployeeInfo> searchedInfo;

	for (const auto& info : (*pDataBase_)) {
		if (parserResult.searchData == info.second.certi) {
			searchedInfo[info.first] = info.second;
		}
	}

	return searchedInfo;
}

Searcher* FactorySearcher::getSearcher(const ParserResult& parserResult) const {
	if (parserResult.operationType == OPERATION_TYPE::ADD) {
		return pEmployeeNumSearcher_;
	}

	Searcher* pSearcher = nullptr;
	string searchColumn = parserResult.searchColumn;

	if (searchColumn == "employeeNum") {
		pSearcher = pEmployeeNumSearcher_;
	}
	else if (searchColumn == "name") {
		pSearcher = pNameSearcher_;
	}
	else if (searchColumn == "cl") {
		pSearcher = pClSearcher_;
	}
	else if (searchColumn == "phoneNum") {
		pSearcher = pPhoneNumSearcher_;
	}
	else if (searchColumn == "birthday") {
		pSearcher = pBirthdaySearcher_;
	}
	else if (searchColumn == "certi") {
		pSearcher = pCertiSearcher_;
	}
	else {
		throw invalid_argument("ERROR: Invalid Search Column");
	}

	return pSearcher;
}