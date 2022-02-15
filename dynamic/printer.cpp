#include "printer.h"

std::string Printer::getPrintString(const ParserResult& parserResult, const std::vector<EmployeeInfo>& targetEmployees)
{
	std::string result;
	if (parserResult.operationType == OPERATION_TYPE::DEL) {
		result += "DEL,";
	}
	else if (parserResult.operationType == OPERATION_TYPE::SCH) {
		result += "SCH,";
	}
	else if (parserResult.operationType == OPERATION_TYPE::MOD) {
		result += "MOD,";
	}
	else {
		return std::string();
	}

	if (targetEmployees.empty()) {
		result += "NONE";
		return result;
	}

	return result;
}
