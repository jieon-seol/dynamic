#pragma once
#include "Define.h"
#include <vector>

class Printer {
public:
	static std::string GetPrintString(const ParserResult& parserResult, const std::vector<EmployeeInfo>& targetEmployees);
};