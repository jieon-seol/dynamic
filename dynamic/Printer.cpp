#include "printer.h"
#include <algorithm>

namespace {
	bool isValidOperationType(OPERATION_TYPE op_type) {
		return op_type == OPERATION_TYPE::DEL || \
			op_type == OPERATION_TYPE::SCH || \
			op_type == OPERATION_TYPE::MOD;
	}

	std::string operationTypeToString(const ParserResult& parserResult) {
		if (parserResult.operationType == OPERATION_TYPE::DEL) {
			return "DEL";
		}
		else if (parserResult.operationType == OPERATION_TYPE::SCH) {
			return "SCH";
		}
		else if (parserResult.operationType == OPERATION_TYPE::MOD) {
			return "MOD";
		}
		else {
			return "";
		}
	}

	std::string employeeInfoToString(const EmployeeInfo& employee) {
		std::string result;
		result += employee.employeeNum + ",";
		result += employee.name + ",";
		result += employee.cl + ",";
		result += employee.phoneNum + ",";
		result += employee.birthday + ",";
		result += employee.certi;
		return result;
	}
}

std::string Printer::getPrintString(const ParserResult& parserResult, const std::map<int, EmployeeInfo>& targetEmployees)
{
	std::string result;

	if (!isValidOperationType(parserResult.operationType)) {
		return std::string();
	}

	if (targetEmployees.empty()) {
		result += operationTypeToString(parserResult) + ",";
		result += "NONE\n";
		return result;
	}

	if (parserResult.option1 == OPTION1::NONE) {
		result += operationTypeToString(parserResult) + ",";
		result += std::to_string(targetEmployees.size());
		result += "\n";
		return result;
	}

	constexpr int MAX_PRINT_RECORD = 5;
	int printCnt = 0;
	for (const auto& employee : targetEmployees) {
		result += operationTypeToString(parserResult) + ",";
		result += employeeInfoToString(employee.second);
		result += "\n";

		printCnt++;
		if (printCnt == MAX_PRINT_RECORD) break;
	}

	return result;
}
