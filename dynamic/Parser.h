#pragma once
#include <string>
#include <regex>
#include "Define.h"

#define PERFORMANCE_MODE 01
//regex_match()시간이 걸릴 수 있으므로, regex 검사를 끕니다

enum class COLUMN_NUM { NONE = -1, employeeNum, name, cl, phoneNum, birthday, certi, MAX };
class Column {
public:
	Column(std::string columnName, std::string valueCheckRegex) {
		columnName_ = columnName;
		data_regex_format_ = valueCheckRegex;
	}
	bool isValidValue(std::string valueStr) {
		//TODO: valueStr이 val_format에 맞는지 검증한다
		return false;
	}
	std::string getColumnName() { return columnName_; }

	bool checkValidDataFormat(std::string dataStr) {
#if PERFORMANCE_MODE
		return true;
#else
		std::regex re(data_regex_format_, std::regex::optimize);
		return std::regex_match(dataStr, re);
#endif
	}
private:
	std::string columnName_;
	std::string data_regex_format_;
};

class Parser {
public:
	friend class ParserTestPrivate;
	ParserResult parse(std::string queryStirng);
private:
	OPERATION_TYPE parseOperationType(const std::string paramStr);
	OPTION1 parseOption1(const std::string paramStr);
	OPTION2 parseOption2(const std::string paramStr);
	OPTION3 parseOption3(const std::string paramStr);
	std::string validCheckColumnName(const std::string columnStr);
	std::string validCheckColumnData(const std::string dataStr, const std::string columnStr);

};

COLUMN_NUM columnStrToNum(const std::string columnStr);
std::string columnNumToStr(const COLUMN_NUM columnNum);
