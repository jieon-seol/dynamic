#include "gtest/gtest.h"
#include "printer.h"
#include <vector>

TEST(Printer, NullTest) {
	EXPECT_EQ(Printer::getPrintString(ParserResult(), std::vector<EmployeeInfo>()), "");
}

TEST(Printer, EmptyTest) {
	ParserResult empty_result;
	empty_result.operationType = OPERATION_TYPE::ADD;
	EXPECT_EQ(Printer::getPrintString(empty_result, std::vector<EmployeeInfo>()), "");

	empty_result.operationType = OPERATION_TYPE::DEL;
	EXPECT_EQ(Printer::getPrintString(empty_result, std::vector<EmployeeInfo>()), "DEL,NONE");

	empty_result.operationType = OPERATION_TYPE::SCH;
	EXPECT_EQ(Printer::getPrintString(empty_result, std::vector<EmployeeInfo>()), "SCH,NONE");

	empty_result.operationType = OPERATION_TYPE::MOD;
	EXPECT_EQ(Printer::getPrintString(empty_result, std::vector<EmployeeInfo>()), "MOD,NONE");
}

TEST(Printer, BriefPrintTest) {
	std::vector<EmployeeInfo> employees;
	employees.push_back(EmployeeInfo{ "91351446", "LIM PNQN", "CL3", "010-6094-6223", "19700122", "PRO" });
	employees.push_back(EmployeeInfo{ "93916535", "JANG YHFQ", "CL3", "010-1509-9243", "19580525", "PRO" });
	employees.push_back(EmployeeInfo{ "07843022", "SEO KFI", "CL3", "010-4837-6716", "19810630", "ADV" });

	ParserResult empty_result;
	empty_result.option1 = OPTION1::NONE;
	empty_result.operationType = OPERATION_TYPE::ADD;
	EXPECT_EQ(Printer::getPrintString(empty_result, employees), "");

	empty_result.operationType = OPERATION_TYPE::DEL;
	EXPECT_EQ(Printer::getPrintString(empty_result, employees), "DEL,3");

	empty_result.operationType = OPERATION_TYPE::SCH;
	EXPECT_EQ(Printer::getPrintString(empty_result, employees), "SCH,3");

	empty_result.operationType = OPERATION_TYPE::MOD;
	EXPECT_EQ(Printer::getPrintString(empty_result, employees), "MOD,3");
}