#include "Parser.h"
#include "GlobalMethod.h"

#include <vector>

using namespace std;

Column columns[(unsigned long long)COLUMN_NUM::MAX]{
		{"employeeNum", "\\d{8}"},
		{"name", "[a-z,A-Z, ]+"},
		{"cl", "CL[1-4]"},
		{"phoneNum", "01[0-9]-\\d{3,4}-\\d{4}"},
		{"birthday", "\\d{8}"},
		{"certi", "(ADV)|(PRO)|(EX)"},
};

OPERATION_TYPE Parser::parseOperationType(const string paramStr) {
	if (paramStr == "ADD") return OPERATION_TYPE::ADD;
	if (paramStr == "DEL") return OPERATION_TYPE::DEL;
	if (paramStr == "SCH") return OPERATION_TYPE::SCH;
	if (paramStr == "MOD") return OPERATION_TYPE::MOD;
	else return OPERATION_TYPE::MAX;	//abnormal case
										//	TODO: throw exception?
}

OPTION1 Parser::parseOption1(const std::string paramStr) {
	if (paramStr == "-p") return OPTION1::P;
	if (paramStr == " ") return OPTION1::NONE;	//normal case
	else return OPTION1::MAX;	//abnormal case
								//	TODO: throw exception?
}

OPTION2 Parser::parseOption2(const std::string paramStr) {
	if (paramStr == "-y") return OPTION2::Y;
	if (paramStr == "-m") return OPTION2::M;
	if (paramStr == "-d") return OPTION2::D;
	if (paramStr == "-l") return OPTION2::L;
	if (paramStr == "-f") return OPTION2::F;
	if (paramStr == " ") return OPTION2::NONE;	//normal case
	else return OPTION2::MAX;	//abnormal case
								//	TODO: throw exception?
}

OPTION3 Parser::parseOption3(const std::string paramStr) {
	if (paramStr == " ") return OPTION3::NONE;	//normal case
	else return OPTION3::MAX;	//abnormal case
								//	TODO: throw exception?
}

COLUMN_NUM columnStrToNum(const std::string columnStr) {
	for (int i = 0; i < (int)COLUMN_NUM::MAX; i++) {
		if (columns[i].getColumnName() == columnStr) return (COLUMN_NUM)i;
	}
	return COLUMN_NUM::NONE;
}
std::string columnNumToStr(const COLUMN_NUM columnNum) {
	if (columnNum <= COLUMN_NUM::NONE || columnNum >= COLUMN_NUM::MAX)
		return "";
	return columns[(unsigned long long)columnNum].getColumnName();
}

std::string Parser::validCheckColumnName(const std::string paramStr) {
	for (int i = 0; i < (int)COLUMN_NUM::MAX; i++) {
		if (columns[i].getColumnName() == paramStr) return paramStr;
	}
	return " ";	//abnormal case
}

std::string Parser::validCheckColumnData(const string dataStr, const string columnStr) {
	//TODO: add valid check -> invalid시에 throw exception
	for (int i = 0; i < (int)COLUMN_NUM::MAX; i++) {
		if (columns[i].getColumnName() == columnStr) {
			if (columns[i].checkValidDataFormat(dataStr)) return dataStr;
			else return " ";
		}
	}
	return " ";	//abnormal case
}


struct ParserResult Parser::parse(string queryStirng) {
	struct ParserResult result;

	try {
		vector<string> words = splitString(queryStirng, ',');

		//TODO: try-catch 추가 (parsing Error)
		result.operationType = parseOperationType(words[0]);
		result.option1 = parseOption1(words[1]);
		result.option2 = parseOption2(words[2]);
		result.option3 = parseOption3(words[3]);

		switch (result.operationType) {
		case OPERATION_TYPE::ADD:
			result.info.employeeNum = validCheckColumnData(words[4], "employeeNum");
			result.info.name = validCheckColumnData(words[5], "name");
			result.info.cl = validCheckColumnData(words[6], "cl");
			result.info.phoneNum = validCheckColumnData(words[7], "phoneNum");
			result.info.birthday = validCheckColumnData(words[8], "birthday");
			result.info.certi = validCheckColumnData(words[9], "certi");
			result.searchColumn = "employeeNum";
			result.searchData = result.info.employeeNum;
			break;
		case OPERATION_TYPE::DEL:
		case OPERATION_TYPE::SCH:
			result.searchColumn = validCheckColumnName(words[4]);
			result.searchData = validCheckColumnData(words[5], result.searchColumn);
			break;
		case OPERATION_TYPE::MOD:
			result.searchColumn = validCheckColumnName(words[4]);
			result.searchData = validCheckColumnData(words[5], result.searchColumn);
			result.changeColumn = validCheckColumnName(words[6]);
			result.changeData = validCheckColumnData(words[7], result.changeColumn);
			break;
		default:
			;
		}
	}
	catch (exception& e) {
		//TODO: exception ? exception을 던지려면, Manager에서 받아줘야 함
		e.what();
	}
	return result;
}
