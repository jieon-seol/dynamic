#include "gtest/gtest.h"
#include "Operator.h"

TEST(OPERATORTEST, FactoryOperatorTest ) {

	FactoryOperator* FO = new FactoryOperator();
	ParserResult FackParserResult;
	FackParserResult.operationType = OPERATION_TYPE::ADD;
	EXPECT_EQ(FO->createOperator(FackParserResult), new AddOperator());

	FackParserResult.operationType = OPERATION_TYPE::DEL;
	EXPECT_EQ(FO->createOperator(FackParserResult), new DeleteOperator());

	FackParserResult.operationType = OPERATION_TYPE::SCH;
	EXPECT_EQ(FO->createOperator(FackParserResult), new SearchOperator());

	FackParserResult.operationType = OPERATION_TYPE::MOD;
	EXPECT_EQ(FO->createOperator(FackParserResult), new ModifyOperator());
}