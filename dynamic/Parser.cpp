#include "Parser.h"
#include "GlobalMethod.h"

using namespace std;

vector<Column> columns{
		{"employeeNum", "\\d{8}"},
		{"name", "[a-z,A-Z, ]+"},
		{"cl", "CL[1-4]"},
		{"phoneNum", "(01[0-9]-\\d{3,4}-\\d{4})|(\\d{3,4})"},
		{"birthday", "(\\d{8})|(\\d{4})|(0[1-9]|1[0-2])|(0[1-9]|[12][0-9]|3[01])"},
		{"certi", "(ADV)|(PRO)|(EX)"},
};

OPERATION_TYPE OperationParser::parseOperationType(const string paramStr) {
	if (paramStr == "ADD") return OPERATION_TYPE::ADD;
	if (paramStr == "DEL") return OPERATION_TYPE::DEL;
	if (paramStr == "SCH") return OPERATION_TYPE::SCH;
	if (paramStr == "MOD") return OPERATION_TYPE::MOD;
	return OPERATION_TYPE::MAX;//abnormal case
}

OPTION1 OperationParser::parseOption1(const string paramStr) {
	if (paramStr == "-p") return OPTION1::P;
	if (paramStr == " ")  return OPTION1::NONE;//normal case
	return OPTION1::MAX;//abnormal case
}

OPTION2 OperationParser::parseOption2(const string paramStr) {
	if (paramStr == "-y") return OPTION2::Y;
	if (paramStr == "-m") return OPTION2::M;
	if (paramStr == "-d") return OPTION2::D;
	if (paramStr == "-l") return OPTION2::L;
	if (paramStr == "-f") return OPTION2::F;
	if (paramStr == " ")  return OPTION2::NONE;//normal case
	return OPTION2::MAX;//abnormal case
}

OPTION3 OperationParser::parseOption3(const string paramStr) {
	if (paramStr == " ")
		return OPTION3::NONE;//normal case
	return OPTION3::MAX;//abnormal case
}

COLUMN_NUM OperationParser::columnStrToNum(const string columnStr) {
	for (int i = 0; i < columns.size(); i++) {
		if (columns[i].columnStr_ == columnStr)
			return (COLUMN_NUM)i;
	}
	return COLUMN_NUM::NONE;
}

string OperationParser::columnNumToStr(const COLUMN_NUM columnNum) {
	if (columnNum <= COLUMN_NUM::NONE || columnNum >= COLUMN_NUM::MAX)
		return "";
	return columns[(int)columnNum].columnStr_;
}

string OperationParser::validCheckColumnName(const string columnStr) {
	for (int i = 0; i < columns.size(); i++) {
		if (columns[i].columnStr_ == columnStr) return columnStr;
	}
	return "";//abnormal case
}

string OperationParser::validCheckColumnData(const string dataStr, COLUMN_NUM columnType) {
	if (columnType <= COLUMN_NUM::NONE || columnType >= COLUMN_NUM::MAX)
		return "";//abnormal case
	if (checkValidDataFormat(columns[(int)columnType].dataRegexFormat_, dataStr))
		return dataStr;
	return ""; //abnormal case
}

struct ParserResult Parser::parse(string queryStirng) {
	struct ParserResult result;

	vector<string> words = splitString(queryStirng, ',');
	OperationParser* pOperation = getOperation(words[0]);
	if (pOperation)	pOperation->parse(result, words);

	return result;
}
