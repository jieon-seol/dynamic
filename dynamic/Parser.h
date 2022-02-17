#pragma once
#include <string>
#include "Define.h"

enum class COLUMN_NUM { NONE = -1, employeeNum, name, cl, phoneNum, birthday, certi, MAX };

class Parser {
public:
	friend class ParserTestPrivate;
	/* TODO: Doxygen style ? 찾아보고 적용
	parse():
	retrun ParserResult
	*/
	ParserResult parse(std::string queryStirng);
private:
	OPERATION_TYPE parseOperationType(const std::string paramStr);
	OPTION1 parseOption1(const std::string paramStr);
	OPTION2 parseOption2(const std::string paramStr);
	OPTION3 parseOption3(const std::string paramStr);
	std::string validCheckColumnName(const std::string paramStr);
	std::string validCheckColumnData(const std::string paramStr, const COLUMN_NUM num);

};

COLUMN_NUM columnStrToNum(const std::string columnStr);
std::string columnNumToStr(const COLUMN_NUM columnNum);
