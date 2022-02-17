#include "gtest/gtest.h"
#include "printer.h"
#include <vector>

TEST(Printer, NullTest) {
	EXPECT_EQ(Printer::getPrintString(ParserResult(), std::map<std::string, EmployeeInfo>()), "");
}

TEST(Printer, EmptyTest) {
	ParserResult empty_result;
	empty_result.operationType = OPERATION_TYPE::ADD;
	EXPECT_EQ(Printer::getPrintString(empty_result, std::map<std::string, EmployeeInfo>()), "");

	empty_result.operationType = OPERATION_TYPE::DEL;
	EXPECT_EQ(Printer::getPrintString(empty_result, std::map<std::string, EmployeeInfo>()), "DEL,NONE\n");

	empty_result.operationType = OPERATION_TYPE::SCH;
	EXPECT_EQ(Printer::getPrintString(empty_result, std::map<std::string, EmployeeInfo>()), "SCH,NONE\n");

	empty_result.operationType = OPERATION_TYPE::MOD;
	EXPECT_EQ(Printer::getPrintString(empty_result, std::map<std::string, EmployeeInfo>()), "MOD,NONE\n");
}

TEST(Printer, BriefPrintTest) {
	std::map<std::string, EmployeeInfo> employees;
	employees["1991351446"] = EmployeeInfo{ "91351446", "LIM PNQN", "CL3", "010-6094-6223", "19700122", "PRO" };
	employees["1993916535"] = EmployeeInfo{ "93916535", "JANG YHFQ", "CL3", "010-1509-9243", "19580525", "PRO" };
	employees["2007843022"] = EmployeeInfo{ "07843022", "SEO KFI", "CL3", "010-4837-6716", "19810630", "ADV" };

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
	std::map<std::string, EmployeeInfo> employees;
	employees["1991351446"] = EmployeeInfo{ "91351446", "LIM PNQN", "CL3", "010-6094-6223", "19700122", "PRO" };
	employees["1993916535"] = EmployeeInfo{ "93916535", "JANG YHFQ", "CL3", "010-1509-9243", "19580525", "PRO" };
	employees["2007843022"] = EmployeeInfo{ "07843022", "SEO KFI", "CL3", "010-4837-6716", "19810630", "ADV" };

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
	std::map<std::string, EmployeeInfo> employees;
	employees["2007843022"] = EmployeeInfo{ "07843022", "SEO KFI", "CL3", "010-4837-6716", "19810630", "ADV" };
	employees["1991351446"] = EmployeeInfo{ "91351446", "LIM PNQN", "CL3", "010-6094-6223", "19700122", "PRO" };
	employees["2018050301"] = EmployeeInfo{ "18050301", "KIM JANG", "CL2", "010-2317-6311", "19940330", "EX" };
	employees["1993916535"] = EmployeeInfo{ "93916535", "JANG YHFQ", "CL3", "010-1509-9243", "19580525", "PRO" };
	

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
	std::map<std::string, EmployeeInfo> employees;
	employees["2007843022"] = EmployeeInfo{ "07843022", "SEO KFI", "CL3", "010-4837-6716", "19810630", "ADV" };
	employees["1991351446"] = EmployeeInfo{ "91351446", "LIM PNQN", "CL3", "010-6094-6223", "19700122", "PRO" };
	employees["2018050301"] = EmployeeInfo{ "18050301", "KIM JANG", "CL2", "010-2317-6311", "19940330", "EX" };
	employees["2001122329"] = EmployeeInfo{ "01122329", "DN WD", "CL4", "010-7174-5680", "20071117", "PRO" };
	employees["2008108827"] = EmployeeInfo{ "08108827", "RTAH VNUP", "CL3", "010-9031-2726", "19780417", "ADV" };
	employees["1985125741"] = EmployeeInfo{ "85125741", "FBAH RTIJ", "CL1", "010-8900-1478", "19780228", "ADV" };

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