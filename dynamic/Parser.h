#pragma once
#include <string>
#include <vector>
#include <regex>
#include "Define.h"

enum class COLUMN_NUM { NONE = -1, employeeNum, name, cl, phoneNum, birthday, certi, MAX };

struct Column {
	std::string columnStr_;
	std::string dataRegexFormat_;
};


class OperationParser {
	friend class ParserTestPrivate;

public:
	virtual void parse(struct ParserResult& result, const std::vector<std::string>& words) = 0;

protected:
	static OPERATION_TYPE parseOperationType(const std::string paramStr);
	static OPTION1 parseOption1(const std::string paramStr);
	static OPTION2 parseOption2(const std::string paramStr);
	static OPTION3 parseOption3(const std::string paramStr);
	static COLUMN_NUM columnStrToNum(const std::string columnStr);
	static std::string columnNumToStr(const COLUMN_NUM columnNum);
	static std::string validCheckColumnName(const std::string columnStr);
	static std::string validCheckColumnData(const std::string dataStr, COLUMN_NUM columnType);

#define PERFORMANCE_MODE 01
	static bool checkValidDataFormat(std::string format, std::string dataStr) {
#if PERFORMANCE_MODE
		return true;
#else
		std::regex re(format, std::regex::optimize);
		return regex_match(dataStr, re);
#endif
	}
};

class AddOperationParser : public OperationParser {
	void parse(struct ParserResult& result, const std::vector<std::string>& words) override {
		result.operationType = OPERATION_TYPE::ADD;
		result.option1 = parseOption1(words[1]);
		result.option2 = parseOption2(words[2]);
		result.option3 = parseOption3(words[3]);

		result.info.employeeNum = validCheckColumnData(words[4], COLUMN_NUM::employeeNum);
		result.info.name = validCheckColumnData(words[5], COLUMN_NUM::name);
		result.info.cl = validCheckColumnData(words[6], COLUMN_NUM::cl);
		result.info.phoneNum = validCheckColumnData(words[7], COLUMN_NUM::phoneNum);
		result.info.birthday = validCheckColumnData(words[8], COLUMN_NUM::birthday);
		result.info.certi = validCheckColumnData(words[9], COLUMN_NUM::certi);
		result.searchColumn = "employeeNum";
		result.searchData = result.info.employeeNum;
	}
};

class DelOperationParser : public OperationParser {
	void parse(struct ParserResult& result, const std::vector<std::string>& words) override {
		result.operationType = OPERATION_TYPE::DEL;
		result.option1 = parseOption1(words[1]);
		result.option2 = parseOption2(words[2]);
		result.option3 = parseOption3(words[3]);

		result.searchColumn = validCheckColumnName(words[4]);
		result.searchData = validCheckColumnData(words[5], columnStrToNum(result.searchColumn));
	}
};

class SchOperationParser : public OperationParser {
	void parse(struct ParserResult& result, const std::vector<std::string>& words) override {
		result.operationType = OPERATION_TYPE::SCH;
		result.option1 = parseOption1(words[1]);
		result.option2 = parseOption2(words[2]);
		result.option3 = parseOption3(words[3]);

		result.searchColumn = validCheckColumnName(words[4]);
		result.searchData = validCheckColumnData(words[5], columnStrToNum(result.searchColumn));
	}
};

class ModOperationParser : public OperationParser {
	void parse(struct ParserResult& result, const std::vector<std::string>& words) override {
		result.operationType = OPERATION_TYPE::MOD;
		result.option1 = parseOption1(words[1]);
		result.option2 = parseOption2(words[2]);
		result.option3 = parseOption3(words[3]);

		result.searchColumn = validCheckColumnName(words[4]);
		result.searchData = validCheckColumnData(words[5], columnStrToNum(result.searchColumn));
		result.changeColumn = validCheckColumnName(words[6]);
		result.changeData = validCheckColumnData(words[7], columnStrToNum(result.changeColumn));
	}
};


class Parser {
public:
	friend class ParserTestPrivate;

	Parser() {
		pAddOperationParser = new AddOperationParser();
		pDelOperationParser = new DelOperationParser();
		pSchOperationParser = new SchOperationParser();
		pModOperationParser = new ModOperationParser();
	}

	ParserResult parse(std::string queryStirng);

	OperationParser* getOperation(std::string operationStr) {
		if (operationStr == "ADD") return pAddOperationParser;
		if (operationStr == "DEL") return pDelOperationParser;
		if (operationStr == "SCH") return pSchOperationParser;
		if (operationStr == "MOD") return pModOperationParser;
		else return nullptr;
	}

private:
	AddOperationParser* pAddOperationParser;
	DelOperationParser* pDelOperationParser;
	SchOperationParser* pSchOperationParser;
	ModOperationParser* pModOperationParser;
};
