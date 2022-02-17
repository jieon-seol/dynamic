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
	EXPECT_EQ(Printer::getPrintString(empty_result, std::vector<EmployeeInfo>()), "DEL,NONE\n");

	empty_result.operationType = OPERATION_TYPE::SCH;
	EXPECT_EQ(Printer::getPrintString(empty_result, std::vector<EmployeeInfo>()), "SCH,NONE\n");

	empty_result.operationType = OPERATION_TYPE::MOD;
	EXPECT_EQ(Printer::getPrintString(empty_result, std::vector<EmployeeInfo>()), "MOD,NONE\n");
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
	EXPECT_EQ(Printer::getPrintString(empty_result, employees), "DEL,3\n");

	empty_result.operationType = OPERATION_TYPE::SCH;
	EXPECT_EQ(Printer::getPrintString(empty_result, employees), "SCH,3\n");

	empty_result.operationType = OPERATION_TYPE::MOD;
	EXPECT_EQ(Printer::getPrintString(empty_result, employees), "MOD,3\n");
}

TEST(Printer, DetailPrintTest) {
	std::vector<EmployeeInfo> employees;
	employees.push_back(EmployeeInfo{ "91351446", "LIM PNQN", "CL3", "010-6094-6223", "19700122", "PRO" });
	employees.push_back(EmployeeInfo{ "93916535", "JANG YHFQ", "CL3", "010-1509-9243", "19580525", "PRO" });
	employees.push_back(EmployeeInfo{ "07843022", "SEO KFI", "CL3", "010-4837-6716", "19810630", "ADV" });

	ParserResult empty_result;
	empty_result.option1 = OPTION1::P;
	empty_result.operationType = OPERATION_TYPE::ADD;
	EXPECT_EQ(Printer::getPrintString(empty_result, employees), "");

	empty_result.operationType = OPERATION_TYPE::DEL;
	EXPECT_EQ(Printer::getPrintString(empty_result, employees),
		"DEL,91351446,LIM PNQN,CL3,010-6094-6223,19700122,PRO\n\
DEL,93916535,JANG YHFQ,CL3,010-1509-9243,19580525,PRO\n\
DEL,07843022,SEO KFI,CL3,010-4837-6716,19810630,ADV\n"
	);

	empty_result.operationType = OPERATION_TYPE::SCH;
	EXPECT_EQ(Printer::getPrintString(empty_result, employees),
		"SCH,91351446,LIM PNQN,CL3,010-6094-6223,19700122,PRO\n\
SCH,93916535,JANG YHFQ,CL3,010-1509-9243,19580525,PRO\n\
SCH,07843022,SEO KFI,CL3,010-4837-6716,19810630,ADV\n"
	);

	empty_result.operationType = OPERATION_TYPE::MOD;
	EXPECT_EQ(Printer::getPrintString(empty_result, employees),
		"MOD,91351446,LIM PNQN,CL3,010-6094-6223,19700122,PRO\n\
MOD,93916535,JANG YHFQ,CL3,010-1509-9243,19580525,PRO\n\
MOD,07843022,SEO KFI,CL3,010-4837-6716,19810630,ADV\n"
	);
}

TEST(Printer, DetailPrintSortedTest) {
	std::vector<EmployeeInfo> employees;
	employees.push_back(EmployeeInfo{ "07843022", "SEO KFI", "CL3", "010-4837-6716", "19810630", "ADV" });
	employees.push_back(EmployeeInfo{ "91351446", "LIM PNQN", "CL3", "010-6094-6223", "19700122", "PRO" });
	employees.push_back(EmployeeInfo{ "18050301", "KIM JANG", "CL2", "010-2317-6311", "19940330", "EX" });
	employees.push_back(EmployeeInfo{ "93916535", "JANG YHFQ", "CL3", "010-1509-9243", "19580525", "PRO" });
	

	ParserResult empty_result;
	empty_result.option1 = OPTION1::P;
	empty_result.operationType = OPERATION_TYPE::ADD;
	EXPECT_EQ(Printer::getPrintString(empty_result, employees), "");

	empty_result.operationType = OPERATION_TYPE::DEL;
	EXPECT_EQ(Printer::getPrintString(empty_result, employees),
		"DEL,91351446,LIM PNQN,CL3,010-6094-6223,19700122,PRO\n\
DEL,93916535,JANG YHFQ,CL3,010-1509-9243,19580525,PRO\n\
DEL,07843022,SEO KFI,CL3,010-4837-6716,19810630,ADV\n\
DEL,18050301,KIM JANG,CL2,010-2317-6311,19940330,EX\n"
);

	empty_result.operationType = OPERATION_TYPE::SCH;
	EXPECT_EQ(Printer::getPrintString(empty_result, employees),
		"SCH,91351446,LIM PNQN,CL3,010-6094-6223,19700122,PRO\n\
SCH,93916535,JANG YHFQ,CL3,010-1509-9243,19580525,PRO\n\
SCH,07843022,SEO KFI,CL3,010-4837-6716,19810630,ADV\n\
SCH,18050301,KIM JANG,CL2,010-2317-6311,19940330,EX\n"
);

	empty_result.operationType = OPERATION_TYPE::MOD;
	EXPECT_EQ(Printer::getPrintString(empty_result, employees),
		"MOD,91351446,LIM PNQN,CL3,010-6094-6223,19700122,PRO\n\
MOD,93916535,JANG YHFQ,CL3,010-1509-9243,19580525,PRO\n\
MOD,07843022,SEO KFI,CL3,010-4837-6716,19810630,ADV\n\
MOD,18050301,KIM JANG,CL2,010-2317-6311,19940330,EX\n"
);
}

TEST(Printer, DetailPrintBiggerThanFiveTest) {
	std::vector<EmployeeInfo> employees;
	employees.push_back(EmployeeInfo{ "07843022", "SEO KFI", "CL3", "010-4837-6716", "19810630", "ADV" });
	employees.push_back(EmployeeInfo{ "91351446", "LIM PNQN", "CL3", "010-6094-6223", "19700122", "PRO" });
	employees.push_back(EmployeeInfo{ "18050301", "KIM JANG", "CL2", "010-2317-6311", "19940330", "EX" });
	employees.push_back(EmployeeInfo{ "01122329", "DN WD", "CL4", "010-7174-5680", "20071117", "PRO" });
	employees.push_back(EmployeeInfo{ "08108827", "RTAH VNUP", "CL3", "010-9031-2726", "19780417", "ADV" });
	employees.push_back(EmployeeInfo{ "85125741", "FBAH RTIJ", "CL1", "010-8900-1478", "19780228", "ADV" });

	ParserResult empty_result;
	empty_result.option1 = OPTION1::P;

	empty_result.operationType = OPERATION_TYPE::SCH;
	EXPECT_EQ(Printer::getPrintString(empty_result, employees),
		"SCH,85125741,FBAH RTIJ,CL1,010-8900-1478,19780228,ADV\n\
SCH,91351446,LIM PNQN,CL3,010-6094-6223,19700122,PRO\n\
SCH,01122329,DN WD,CL4,010-7174-5680,20071117,PRO\n\
SCH,07843022,SEO KFI,CL3,010-4837-6716,19810630,ADV\n\
SCH,08108827,RTAH VNUP,CL3,010-9031-2726,19780417,ADV\n");
}