#include "gtest/gtest.h"
#include "Operator.h"

TEST(OPERATORTEST, FactoryOperatorTest ) {

	FactoryOperator* FO = new FactoryOperator();
	ParserResult FakeParserResult;
	FakeParserResult.operationType = OPERATION_TYPE::ADD;
	EXPECT_EQ(FO->createOperator(FakeParserResult), new AddOperator());

	FakeParserResult.operationType = OPERATION_TYPE::DEL;
	EXPECT_EQ(FO->createOperator(FakeParserResult), new DeleteOperator());

	FakeParserResult.operationType = OPERATION_TYPE::SCH;
	EXPECT_EQ(FO->createOperator(FakeParserResult), new SearchOperator());

	FakeParserResult.operationType = OPERATION_TYPE::MOD;
	EXPECT_EQ(FO->createOperator(FakeParserResult), new ModifyOperator());
}

