#include "GlobalMethod.h"
#include <sstream>
#include <iostream>

std::vector<std::string> splitString(const std::string& targetStr, const char delimiter) {
	std::vector<std::string> wordVector;
	std::istringstream stringStream(targetStr);
	std::string word;

	while (getline(stringStream, word, delimiter)) {
		wordVector.push_back(word);
	}

	return wordVector;
}