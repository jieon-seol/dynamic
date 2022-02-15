#include "printer.h"

namespace {
	bool isValidOperationType(OPERATION_TYPE op_type) {
		return op_type == OPERATION_TYPE::DEL || \
			op_type == OPERATION_TYPE::SCH || \
			op_type == OPERATION_TYPE::MOD;
	}

	std::string OperationTypeToString(const ParserResult& parserResult) {
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

	std::string EmployeeInfoToString(const EmployeeInfo& employee) {
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

std::string Printer::getPrintString(const ParserResult& parserResult, const std::vector<EmployeeInfo>& targetEmployees)
{
	std::string result;

	if (!isValidOperationType(parserResult.operationType)) {
		return std::string();
	}

	if (targetEmployees.empty()) {
		result += OperationTypeToString(parserResult) + ",";
		result += "NONE";
		return result;
	}

	if (parserResult.option1 == OPTION1::NONE) {
		result += OperationTypeToString(parserResult) + ",";
		result += std::to_string(targetEmployees.size());
		return result;
	}

	for (const auto& employee : targetEmployees) {
		result += OperationTypeToString(parserResult) + ",";
		result += EmployeeInfoToString(employee);
		result += "\n";
	}

	return result;
}
