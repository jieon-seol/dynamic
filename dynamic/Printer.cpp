#include "printer.h"
#include <algorithm>

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

	void UpdateYearOfEmployeeNum(std::string& employeeNum) {
		if (employeeNum.front() == '6' || employeeNum.front() == '7' || employeeNum.front() == '8' || employeeNum.front() == '9') {
			employeeNum = "19" + employeeNum;
		}
		else {
			employeeNum = "20" + employeeNum;
		}
	}

	bool EmployeeCompare(const EmployeeInfo& employee1, const EmployeeInfo& employee2) {
		std::string employeeNum1 = employee1.employeeNum;
		std::string employeeNum2 = employee2.employeeNum;
		UpdateYearOfEmployeeNum(employeeNum1);
		UpdateYearOfEmployeeNum(employeeNum2);
		return std::stoi(employeeNum1) < std::stoi(employeeNum2);
	}

	std::vector<EmployeeInfo> Sort(const std::vector<EmployeeInfo>& targetEmployees) {
		std::vector<EmployeeInfo> newEmployeeList = targetEmployees;
		sort(newEmployeeList.begin(), newEmployeeList.end(), EmployeeCompare);
		return newEmployeeList;
	}
}

std::string Printer::GetPrintString(const ParserResult& parserResult, const std::vector<EmployeeInfo>& targetEmployees)
{
	std::string result;

	if (!isValidOperationType(parserResult.operationType)) {
		return std::string();
	}

	if (targetEmployees.empty()) {
		result += OperationTypeToString(parserResult) + ",";
		result += "NONE\n";
		return result;
	}

	if (parserResult.option1 == OPTION1::NONE) {
		result += OperationTypeToString(parserResult) + ",";
		result += std::to_string(targetEmployees.size());
		result += "\n";
		return result;
	}

	auto newEmployeeList = Sort(targetEmployees);

	constexpr int MAX_PRINT_RECORD = 5;
	for (int i = 0; i < MAX_PRINT_RECORD && i < newEmployeeList.size(); ++i){
		const auto& employee = newEmployeeList[i];
		result += OperationTypeToString(parserResult) + ",";
		result += EmployeeInfoToString(employee);
		result += "\n";
	}

	return result;
}
