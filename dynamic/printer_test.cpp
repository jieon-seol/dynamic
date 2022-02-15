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