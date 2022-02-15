#pragma once
#include <string>
#include "Define.h"

enum class INFO_TYPE { NONE = -1, employeeNum, name, cl, phoneNum, birthday, certi, MAX };

class Parser {
public:
	friend class ParserTestPrivate;
	/* TODO: Doxygen style ? 찾아보고 적용
	parse():
	retrun ParserResult
	*/
	struct ParserResult parse(std::string queryStirng);
private:
	OPERATION_TYPE parseOperationType(std::string paramStr);
	OPTION1 parseOption1(std::string paramStr);
	OPTION2 parseOption2(std::string paramStr);
	OPTION3 parseOption3(std::string paramStr);
	std::string parseColumn(std::string paramStr);
	std::string parseData(std::string paramStr, INFO_TYPE type);
};