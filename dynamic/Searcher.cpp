#include <iostream>
#include <vector>
#include <string>
#include <assert.h>
#include "Define.h"
#include "Searcher.h"

using namespace std;

vector<EmployeeInfo> g_Db;

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

vector<EmployeeInfo> EmployeeNumSearcher::search(const ParserResult& parserResult) {
	if (parserResult.searchColumn.compare("employeeNum")) {
		assert(false);
	}

	vector<EmployeeInfo> result;
	for (auto info : (*pDb_)) {
		if (parserResult.searchData.compare(info.employeeNum) == 0) {
			result.emplace_back(info);
			return result;
		}
	}
	return result;
}

vector<EmployeeInfo> NameSearcher::search(const ParserResult& parserResult) {
	if (parserResult.searchColumn.compare("name")) {
		assert(false);
	}

	string searchName = parserResult.searchData;
	OPTION2 nameOption = parserResult.option2;
	vector<EmployeeInfo> result;

	for (auto info : (*pDb_)) {
		if (searchName.compare(getNameByOption(info.name, nameOption)) == 0) {
			result.emplace_back(info);
		}
	}

	return result;
}

string NameSearcher::getNameByOption(const string& name, const OPTION2 option) {
	if (option == OPTION2::NONE) {
		return name;
	}

	vector<string> subStr = splitString(name, ' ');
	if (subStr.size() != 2) {
		assert(false);
	}

	if (option == OPTION2::L) {
		return subStr[0];
	}

	if (option == OPTION2::F) {
		return subStr[1];
	}
	
	assert(false);
}

vector<EmployeeInfo> ClSearcher::search(const ParserResult& parserResult) {
	if (parserResult.searchColumn.compare("cl")) {
		assert(false);
	}

	vector<EmployeeInfo> result;
	for (auto info : (*pDb_)) {
		if (parserResult.searchData.compare(info.cl) == 0) {
			result.emplace_back(info);
		}
	}
	return result;
}

string PhoneNumberSearcher::getNumberByOption(const string& phoneNumber, const OPTION2 numberOption) {
	if (numberOption == OPTION2::NONE) {
		return phoneNumber;
	}

	vector<string> subStr = splitString(phoneNumber, '-');
	if (subStr.size() != 3) {
		assert(false);
	}

	if (numberOption == OPTION2::M) {
		return subStr[1];
	}
	
	if (numberOption == OPTION2::L) {
		return subStr[2];
	}

	assert(false);
}

vector<EmployeeInfo> PhoneNumberSearcher::search(const ParserResult& parserResult) {
	if (parserResult.searchColumn.compare("phoneNum")) {
		assert(false);
	}

	string searchNumber = parserResult.searchData;
	OPTION2 numberOption = parserResult.option2;
	vector<EmployeeInfo> result;

	for (auto info : (*pDb_)) {
		if (searchNumber.compare(getNumberByOption(info.phoneNum, numberOption)) == 0) {
			result.emplace_back(info);
		}
	}

	return result;
}

vector<EmployeeInfo> BirthdaySearcher::search(const ParserResult& parserResult) {
	if (parserResult.searchColumn.compare("birthday")) {
		assert(false);
	}

	string searchBirth = parserResult.searchData;
	OPTION2 birthOption = parserResult.option2;
	vector<EmployeeInfo> result;

	for (auto info : (*pDb_)) {
		if (searchBirth.compare(getBirthDayByOption(info.birthday, birthOption)) == 0) {
			result.emplace_back(info);
		}
	}

	return result;
}

string BirthdaySearcher::getBirthDayByOption(const string& birthDay, const OPTION2 birthOption) {
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
}

vector<EmployeeInfo> CertiSearcher::search(const ParserResult& parserResult) {
	if (parserResult.searchColumn.compare("certi")) {
		assert(false);
	}

	vector<EmployeeInfo> result;
	for (auto info : (*pDb_)) {
		if (parserResult.searchData.compare(info.certi) == 0) {
			result.emplace_back(info);
		}
	}

	return result;
}