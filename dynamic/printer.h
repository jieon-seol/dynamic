#pragma once
#include "Define.h"
#include <vector>

class Printer {
public:
	static std::string getPrintString(const ParserResult& parserResult, const std::vector<EmployeeInfo>& targetEmployees);
};