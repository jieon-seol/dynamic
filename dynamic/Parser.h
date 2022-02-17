#pragma once
#include <string>
#include <vector>
#include <regex>
#include "Define.h"

#define PERFORMANCE_MODE 01
//regex_match()시간이 걸릴 수 있으므로, regex 검사를 끕니다


struct Column {
	std::string columnStr_;
	std::string dataRegexFormat_;
};

class Parser {
public:
enum class COLUMN_NUM { NONE = -1, employeeNum, name, cl, phoneNum, birthday, certi, MAX };

	friend class ParserTestPrivate;
	ParserResult parse(std::string queryStirng);

private:
	static COLUMN_NUM columnStrToNum(const std::string columnStr);
	static std::string columnNumToStr(const COLUMN_NUM columnNum);
	OPERATION_TYPE parseOperationType(const std::string paramStr);
	OPTION1 parseOption1(const std::string paramStr);
	OPTION2 parseOption2(const std::string paramStr);
	OPTION3 parseOption3(const std::string paramStr);
	static std::string validCheckColumnName(const std::string columnStr);
	static std::string validCheckColumnData(const std::string dataStr, COLUMN_NUM columnType);

	static bool checkValidDataFormat(std::string format, std::string dataStr) {
#if PERFORMANCE_MODE
		return true;
#else
		regex re(format, regex::optimize);
		return regex_match(dataStr, re);
#endif
	}
};
