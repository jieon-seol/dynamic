#pragma once
#include <string>
using namespace std;

enum OPTION { PRINT_BRIEF, PRINT_DETAIL, LRI };
enum OPERATION_TYPE { ADD, DEL, SCH, MOD };
enum CAREER_LEVEL { CL1, CL2, CL3, CL4 };
enum CERTI_LEVEL { ADV, PRO, EX };

struct EmployeeInfo {
	int employeeNum;
	string name;
	CAREER_LEVEL cl;
	int phoneNum;
	int birthday;
	CERTI_LEVEL certi;
};

struct ParserResult {
	OPERATION_TYPE operationType;
	OPTION option1;	// print detail
	OPTION option2;	// �˻� ���� �ɼ�
	OPTION option3;	// �ɼ�3: ����� �������
	string searchColumn;
	string searchData;
	string changeColumn;
	string changeData;

	EmployeeInfo info;
};
