#include <iostream>
#include <string>
#include "Searcher.h"

using namespace std;

namespace {
	vector<string> splitString(const string& targetStr, const char delimiter) {
		vector<string> subStringVector;
		size_t previous = 0;
		size_t current = targetStr.find(delimiter);

		while (current != string::npos) {
			string substring = targetStr.substr(previous, current - previous);
			subStringVector.push_back(substring);
			previous = current + 1;
			current = targetStr.find(delimiter, previous);
		}
		subStringVector.push_back(targetStr.substr(previous, current - previous));

		return subStringVector;
	}
}

vector<EmployeeInfo> EmployeeNumSearcher::search(const ParserResult& parserResult) const {
	vector<EmployeeInfo> result;
	for (const auto& info : (*pDataBase_)) {
		if (parserResult.searchData == info.employeeNum) {
			result.emplace_back(info);
			return result;
		}
	}
	return result;
}

vector<EmployeeInfo> NameSearcher::search(const ParserResult& parserResult) const {
	string searchName = parserResult.searchData;
	OPTION2 nameOption = parserResult.option2;
	vector<EmployeeInfo> result;

	for (const auto& info : (*pDataBase_)) {
		if (searchName == filterData(info.name, nameOption)) {
			result.emplace_back(info);
		}
	}

	return result;
}

string NameSearcher::filterData(const string& name, const OPTION2 nameOption) const {
	if (nameOption == OPTION2::NONE) {
		return name;
	}

	vector<string> subName = splitString(name, ' ');
	if (subName.size() != 2) {
		throw invalid_argument("ERROR: Invalid Name");
	}

	if (nameOption == OPTION2::L) {
		return subName[0];
	}

	if (nameOption == OPTION2::F) {
		return subName[1];
	}

	throw invalid_argument("ERROR: Invalid Name Option2");
}

vector<EmployeeInfo> ClSearcher::search(const ParserResult& parserResult) const {
	vector<EmployeeInfo> result;
	for (const auto& info : (*pDataBase_)) {
		if (parserResult.searchData == info.cl) {
			result.emplace_back(info);
		}
	}
	return result;
}

vector<EmployeeInfo> PhoneNumberSearcher::search(const ParserResult& parserResult) const {
	string searchNumber = parserResult.searchData;
	OPTION2 numberOption = parserResult.option2;
	vector<EmployeeInfo> result;

	for (const auto& info : (*pDataBase_)) {
		if (searchNumber == filterData(info.phoneNum, numberOption)) {
			result.emplace_back(info);
		}
	}

	return result;
}

string PhoneNumberSearcher::filterData(const string& phoneNum, const OPTION2 numOption) const {
	if (numOption == OPTION2::NONE) {
		return phoneNum;
	}

	vector<string> subPhoneNum = splitString(phoneNum, '-');
	if (subPhoneNum.size() != 3) {
		throw invalid_argument("ERROR: Invalid Phone Number");
	}

	if (numOption == OPTION2::M) {
		return subPhoneNum[1];
	}

	if (numOption == OPTION2::L) {
		return subPhoneNum[2];
	}

	throw invalid_argument("ERROR: Invalid Phone Number Option2");
}

vector<EmployeeInfo> BirthdaySearcher::search(const ParserResult& parserResult) const {
	string searchBirth = parserResult.searchData;
	OPTION2 birthOption = parserResult.option2;
	vector<EmployeeInfo> result;

	for (const auto& info : (*pDataBase_)) {
		if (searchBirth == filterData(info.birthday, birthOption)) {
			result.emplace_back(info);
		}
	}

	return result;
}

string BirthdaySearcher::filterData(const string& birthDay, const OPTION2 birthOption) const {
	if (birthOption == OPTION2::NONE) return birthDay;

	if (birthOption == OPTION2::Y) {
		return birthDay.substr(0, 4);
	}
	else if (birthOption == OPTION2::M) {
		return birthDay.substr(4, 2);
	}
	else if (birthOption == OPTION2::D) {
		return birthDay.substr(6, 2);
	}

	throw invalid_argument("ERROR: Invalid Birthday Option2");
}

vector<EmployeeInfo> CertiSearcher::search(const ParserResult& parserResult) const {
	vector<EmployeeInfo> result;

	for (const auto& info : (*pDataBase_)) {
		if (parserResult.searchData == info.certi) {
			result.emplace_back(info);
		}
	}

	return result;
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