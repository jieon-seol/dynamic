#pragma once
#include <string>
#include <vector>

enum class OPTION1 { NONE = -1, P, MAX };
enum class OPTION2 { NONE = -1, Y, M, D, L, F, MAX };
enum class OPTION3 { NONE = -1, MAX };
enum class OPERATION_TYPE { NONE = -1, ADD, DEL, SCH, MOD, MAX };

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
	OPTION1 option1;	// print detail
	OPTION2 option2;	// 검색 세부 옵션
	OPTION3 option3;	// 옵션3: 현재는 비어있음
	std::string searchColumn;
	std::string searchData;
	std::string changeColumn;
	std::string changeData;

	EmployeeInfo info;
};

std::vector<EmployeeInfo> dataBase;
