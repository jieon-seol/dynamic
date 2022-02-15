#include <iostream>
#include <vector>
#include <string>
#include "Define.h"
#include "Searcher.h"

using namespace std;

vector<EmployeeInfo> g_DB;

vector<string> splitString(const string& targetStr, char delimiter) {
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
		;// Error
	}

	vector<EmployeeInfo> result;
	for (auto info : g_DB) {
		if (parserResult.searchData.compare(info.employeeNum) == 0) {
			result.emplace_back(info);
			return result;
		}
	}
	return result;
}

vector<EmployeeInfo> NameSearcher::search(const ParserResult& parserResult) {
	if (parserResult.searchColumn.compare("name")) {
		;// Error
	}

	string searchName = parserResult.searchData;
	OPTION2 nameOption = parserResult.option2;
	vector<EmployeeInfo> result;

	for (auto info : g_DB) {
		if (searchName.compare(getNameByOption(info.name, nameOption)) == 0) {
			result.emplace_back(info);
		}
	}

	return result;
}

string NameSearcher::getNameByOption(string name, OPTION2 option) {
	if (option == OPTION2::NONE) return name;

	vector<string> subStr = splitString(name, ' ');
	if (subStr.size() != 2) {
		;// Error
	}

	if (option == OPTION2::L) {
		return subStr[0];
	}
	else if (option == OPTION2::F) {
		return subStr[1];
	}
	else {
		; // Error
	}
}

vector<EmployeeInfo> ClSearcher::search(const ParserResult& parserResult) {
	vector<EmployeeInfo> result;
	for (auto info : g_DB) {
		if (parserResult.searchData.compare(info.cl) == 0) {
			result.emplace_back(info);
		}
	}
	return result;
}

string PhoneNumberSearcher::getNumberByOption(string phoneNumber, OPTION2 numberOption) {
	if (numberOption == OPTION2::NONE) return phoneNumber;

	vector<string> subStr = splitString(phoneNumber, '-');
	if (subStr.size() != 3) {
		;// Error
	}

	if (numberOption == OPTION2::M) {
		return subStr[1];
	}
	else if (numberOption == OPTION2::L) {
		return subStr[2];
	}
	else {
		; // Error
	}
}

vector<EmployeeInfo> PhoneNumberSearcher::search(const ParserResult& parserResult) {
	string searchNumber = parserResult.searchData;
	OPTION2 numberOption = parserResult.option2;
	vector<EmployeeInfo> result;

	for (auto info : g_DB) {
		if (searchNumber.compare(getNumberByOption(info.phoneNum, numberOption)) == 0) {
			result.emplace_back(info);
		}
	}

	return result;
}