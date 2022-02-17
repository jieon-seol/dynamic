#pragma once
#include "Define.h"
#include <map>
#include <string>

class Printer {
public:
	static std::string getPrintString(const ParserResult& parserResult, const std::map<std::string, EmployeeInfo>& targetEmployees);
};