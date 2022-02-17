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

	void updateYearOfEmployeeNum(std::string& employeeNum) {
		if (employeeNum.front() == '6' || employeeNum.front() == '7' || employeeNum.front() == '8' || employeeNum.front() == '9') {
			employeeNum = "19" + employeeNum;
		}
		else {
			employeeNum = "20" + employeeNum;
		}
	}

	bool employeeCompare(const EmployeeInfo& employee1, const EmployeeInfo& employee2) {
		std::string employeeNum1 = employee1.employeeNum;
		std::string employeeNum2 = employee2.employeeNum;
		updateYearOfEmployeeNum(employeeNum1);
		updateYearOfEmployeeNum(employeeNum2);
		return std::stoi(employeeNum1) < std::stoi(employeeNum2);
	}

	std::vector<EmployeeInfo> sort(const std::vector<EmployeeInfo>& targetEmployees) {
		std::vector<EmployeeInfo> newEmployeeList = targetEmployees;
		sort(newEmployeeList.begin(), newEmployeeList.end(), employeeCompare);
		return newEmployeeList;
	}
}

std::string Printer::getPrintString(const ParserResult& parserResult, const std::vector<EmployeeInfo>& targetEmployees)
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

	auto newEmployeeList = sort(targetEmployees);

	constexpr int MAX_PRINT_RECORD = 5;
	for (int i = 0; i < MAX_PRINT_RECORD && i < newEmployeeList.size(); ++i){
		const auto& employee = newEmployeeList[i];
		result += operationTypeToString(parserResult) + ",";
		result += employeeInfoToString(employee);
		result += "\n";
	}

	return result;
}
