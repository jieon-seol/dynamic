#include "GlobalMethod.h"
#include <sstream>
#include <iostream>

int getKeyFromEmployeeNum(const std::string& employeeNum) {
	std::string fullString;
	if (employeeNum.front() == '6' || employeeNum.front() == '7' || employeeNum.front() == '8' || employeeNum.front() == '9') {
		return(std::stoi("19" + employeeNum));
	}

	return(std::stoi("20" + employeeNum));
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