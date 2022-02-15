
#include "Operator.h"


Operator* FactoryOperator::createOperator(const ParserResult& parserResult)
{
	switch (parserResult.operationType)
	{
	case OPERATION_TYPE::ADD:
		return new AddOperator();
	case OPERATION_TYPE::DEL:
		return new DeleteOperator();
	case OPERATION_TYPE::SCH:
		return new SearchOperator();
	case OPERATION_TYPE::MOD:
		return new ModifyOperator();

	}
}


int AddOperator::operate(ParserResult parserResult)
{
	return 0;
}


int DeleteOperator::operate(ParserResult parserResult)
{
	return 0;
}


int SearchOperator::operate(ParserResult parserResult)
{
	return 0;
}


int ModifyOperator::operate(ParserResult parserResult)
{
	return 0;
}


