#pragma once
#include <string>

enum OPTION { PRINT_BRIEF, PRINT_DETAIL, LRI };
enum OPERATION_TYPE { ADD, DEL, SCH, MOD };

struct EmployeeInfo {
	std::string employeeNum;
	std::string name;
	std::string cl;
	std::string phoneNum;
	std::string birthday;
	std::string certi;
};

struct ParserResult {
	OPERATION_TYPE operationType;
	OPTION option1;	// print detail
	OPTION option2;	// 검색 세부 옵션
	OPTION option3;	// 옵션3: 현재는 비어있음
	std::string searchColumn;
	std::string searchData;
	std::string changeColumn;
	std::string changeData;

	EmployeeInfo info;
};
