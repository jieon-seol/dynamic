#include "GlobalMethod.h"
#include <sstream>
#include <iostream>

std::string getKeyFromEmployeeNum(const std::string& employeeNum) {
	if (employeeNum.front() == '6' || employeeNum.front() == '7' || employeeNum.front() == '8' || employeeNum.front() == '9') {
		return "19" + employeeNum;
	}

	return "20" + employeeNum;
}

std::vector<std::string> splitString(const std::string& targetStr, const char delimiter) {
	std::vector<std::string> wordVector;
	std::istringstream stringStream(targetStr);
	std::string word;

	while (getline(stringStream, word, delimiter)) {
		wordVector.push_back(word);
	}

	return wordVector;
}