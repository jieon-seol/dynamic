#include "Parser.h"
#include "GlobalMethod.h"

using namespace std;

vector<Column> columns {
		{"employeeNum", "\\d{8}"},
		{"name", "[a-z,A-Z, ]+"},
		{"cl", "CL[1-4]"},
		{"phoneNum", "(01[0-9]-\\d{3,4}-\\d{4})|(\\d{3,4})"},
		{"birthday", "(\\d{8})|(\\d{4})|(0[1-9]|1[0-2])|(0[1-9]|[12][0-9]|3[01])"},
		{"certi", "(ADV)|(PRO)|(EX)"},
};

OPERATION_TYPE Parser::parseOperationType(const string paramStr) {
	if (paramStr == "ADD") return OPERATION_TYPE::ADD;
	if (paramStr == "DEL") return OPERATION_TYPE::DEL;
	if (paramStr == "SCH") return OPERATION_TYPE::SCH;
	if (paramStr == "MOD") return OPERATION_TYPE::MOD;
	else return OPERATION_TYPE::MAX;//abnormal case
}

OPTION1 Parser::parseOption1(const string paramStr) {
	if (paramStr == "-p") return OPTION1::P;
	if (paramStr == " ")  return OPTION1::NONE;//normal case
	else return OPTION1::MAX;//abnormal case
}

OPTION2 Parser::parseOption2(const string paramStr) {
	if (paramStr == "-y") return OPTION2::Y;
	if (paramStr == "-m") return OPTION2::M;
	if (paramStr == "-d") return OPTION2::D;
	if (paramStr == "-l") return OPTION2::L;
	if (paramStr == "-f") return OPTION2::F;
	if (paramStr == " ")  return OPTION2::NONE;//normal case
	else return OPTION2::MAX;//abnormal case
}

OPTION3 Parser::parseOption3(const string paramStr) {
	if (paramStr == " ")
		return OPTION3::NONE;//normal case
	else
		return OPTION3::MAX;//abnormal case
}

Parser::COLUMN_NUM Parser::columnStrToNum(const string columnStr) {
	for (int i = 0; i < columns.size(); i++) {
		if (columns[i].columnStr_ == columnStr)
			return (COLUMN_NUM)i;
	}
	return COLUMN_NUM::NONE;
}

string Parser::columnNumToStr(const COLUMN_NUM columnNum) {
	if (columnNum <= COLUMN_NUM::NONE || columnNum >= COLUMN_NUM::MAX)
		return "";
	return columns[(int)columnNum].columnStr_;
}

string Parser::validCheckColumnName(const string columnStr) {
	for (int i = 0; i < columns.size(); i++) {
		if (columns[i].columnStr_ == columnStr) return columnStr;
	}
	return "";//abnormal case
}

string Parser::validCheckColumnData(const string dataStr, COLUMN_NUM columnType) {
	if (columnType <= COLUMN_NUM::NONE || columnType >= COLUMN_NUM::MAX)
		return "";//abnormal case
	if (checkValidDataFormat(columns[(int)columnType].dataRegexFormat_, dataStr))
		return dataStr;
	else
		return ""; //abnormal case
}

void Parser::parseADD(struct ParserResult& result, const vector<string>& words) {
	result.option1 = parseOption1(words[1]);
	result.option2 = parseOption2(words[2]);
	result.option3 = parseOption3(words[3]);

	result.info.employeeNum	= validCheckColumnData(words[4], COLUMN_NUM::employeeNum);
	result.info.name		= validCheckColumnData(words[5], COLUMN_NUM::name);
	result.info.cl			= validCheckColumnData(words[6], COLUMN_NUM::cl);
	result.info.phoneNum	= validCheckColumnData(words[7], COLUMN_NUM::phoneNum);
	result.info.birthday	= validCheckColumnData(words[8], COLUMN_NUM::birthday);
	result.info.certi		= validCheckColumnData(words[9], COLUMN_NUM::certi);
	result.searchColumn		= "employeeNum";
	result.searchData		= result.info.employeeNum;
}

void Parser::parseDEL(struct ParserResult& result, const vector<string>& words) {
	result.option1 = parseOption1(words[1]);
	result.option2 = parseOption2(words[2]);
	result.option3 = parseOption3(words[3]);

	result.searchColumn = validCheckColumnName(words[4]);
	result.searchData	= validCheckColumnData(words[5], columnStrToNum(result.searchColumn));
}

void Parser::parseSCH(struct ParserResult& result, const vector<string>& words) {
	result.option1 = parseOption1(words[1]);
	result.option2 = parseOption2(words[2]);
	result.option3 = parseOption3(words[3]);

	result.searchColumn = validCheckColumnName(words[4]);
	result.searchData	= validCheckColumnData(words[5], columnStrToNum(result.searchColumn));
}

void Parser::parseMOD(struct ParserResult& result, const vector<string>& words) {
	result.option1 = parseOption1(words[1]);
	result.option2 = parseOption2(words[2]);
	result.option3 = parseOption3(words[3]);

	result.searchColumn = validCheckColumnName(words[4]);
	result.searchData	= validCheckColumnData(words[5], columnStrToNum(result.searchColumn));
	result.changeColumn = validCheckColumnName(words[6]);
	result.changeData	= validCheckColumnData(words[7], columnStrToNum(result.changeColumn));
}

struct ParserResult Parser::parse(string queryStirng) {
	struct ParserResult result;

	vector<string> words = splitString(queryStirng, ',');

	result.operationType = parseOperationType(words[0]);

	switch (result.operationType) {
		//TODO: factory
	case OPERATION_TYPE::ADD: parseADD(result, words); break;
	case OPERATION_TYPE::DEL: parseDEL(result, words); break;
	case OPERATION_TYPE::SCH: parseSCH(result, words); break;
	case OPERATION_TYPE::MOD: parseMOD(result, words); break;
	default:
		;
	}

	return result;
}
