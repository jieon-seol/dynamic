#include "gtest/gtest.h"
#include "printer.h"
#include <vector>

TEST(Printer, NullTest) {
	EXPECT_EQ(Printer::getPrintString(ParserResult(), std::vector<EmployeeInfo>()), "");
}
