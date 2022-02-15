#include "printer.h"

std::string Printer::getPrintString(const ParserResult& parserResult, const std::vector<EmployeeInfo>& targetEmployees)
{
	std::string result;

	if (parserResult.operationType != OPERATION_TYPE::DEL && parserResult.operationType != OPERATION_TYPE::SCH && parserResult.operationType != OPERATION_TYPE::MOD) {
		return std::string();
	}

	if (targetEmployees.empty()) {
		if (parserResult.operationType == OPERATION_TYPE::DEL) {
			result += "DEL,";
		}
		else if (parserResult.operationType == OPERATION_TYPE::SCH) {
			result += "SCH,";
		}
		else if (parserResult.operationType == OPERATION_TYPE::MOD) {
			result += "MOD,";
		}
		result += "NONE";
		return result;
	}

	if (parserResult.option1 == OPTION1::NONE) {
		if (parserResult.operationType == OPERATION_TYPE::DEL) {
			result += "DEL,";
		}
		else if (parserResult.operationType == OPERATION_TYPE::SCH) {
			result += "SCH,";
		}
		else if (parserResult.operationType == OPERATION_TYPE::MOD) {
			result += "MOD,";
		}
		result += std::to_string(targetEmployees.size());
		return result;
	}

	for (const auto& employee : targetEmployees) {
		if (parserResult.operationType == OPERATION_TYPE::DEL) {
			result += "DEL,";
		}
		else if (parserResult.operationType == OPERATION_TYPE::SCH) {
			result += "SCH,";
		}
		else if (parserResult.operationType == OPERATION_TYPE::MOD) {
			result += "MOD,";
		}

		result += employee.employeeNum + ",";
		result += employee.name + ",";
		result += employee.cl + ",";
		result += employee.phoneNum + ",";
		result += employee.birthday + ",";
		result += employee.certi + "\n";
	}
	return result;
}
