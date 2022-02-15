#include "gtest/gtest.h"
#include "Operator.h"

TEST(OPERATORTEST, FactoryOperatorTest ) {

	FactoryOperator* FO = new FactoryOperator();
	ParserResult FakeParserResult;
	FakeParserResult.operationType = OPERATION_TYPE::ADD;
	EXPECT_EQ(FO->getOperator(FakeParserResult), new AddOperator());

	FakeParserResult.operationType = OPERATION_TYPE::DEL;
	EXPECT_EQ(FO->getOperator(FakeParserResult), new DeleteOperator());

	FakeParserResult.operationType = OPERATION_TYPE::SCH;
	EXPECT_EQ(FO->getOperator(FakeParserResult), new SearchOperator());

	FakeParserResult.operationType = OPERATION_TYPE::MOD;
	EXPECT_EQ(FO->getOperator(FakeParserResult), new ModifyOperator());
}

TEST(OPERATORTEST, AddOperatorTest) {

	Operator* AddOper = new AddOperator();
	ParserResult FakeParserResult = { OPERATION_TYPE::ADD,
										OPTION1::NONE,
										OPTION2::NONE,
										OPTION3::NONE,
										std::string(),
										std::string(),
										std::string(),
										std::string(),
										EmployeeInfo{ "01122329", "DN WD", "CL4", "010-7174-5680", "20071117", "PRO" }
	};


	EXPECT_EQ(AddOper->operate(FakeParserResult), 1);

}