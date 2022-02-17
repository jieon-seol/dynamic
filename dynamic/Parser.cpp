#include "Parser.h"
#include "GlobalMethod.h"

#include <vector>

using namespace std;

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

std::string Parser::validCheckColumnName(const std::string paramStr) {
	if (paramStr == "employeeNum" ||
		paramStr == "name" ||
		paramStr == "cl" ||
		paramStr == "phoneNum" ||
		paramStr == "birthday" ||
		paramStr == "certi") {
		return paramStr;
	}
	else return " ";	//abnormal case
}

std::string Parser::validCheckColumnData(const std::string paramStr, const COLUMN_NUM type) {
	//TODO: add valid check -> invalid시에 throw exception
	switch (type) {
	case COLUMN_NUM::employeeNum: return paramStr;
	case COLUMN_NUM::name: return paramStr;
	case COLUMN_NUM::cl: return paramStr;
	case COLUMN_NUM::phoneNum: return paramStr;
	case COLUMN_NUM::birthday: return paramStr;
	case COLUMN_NUM::certi: return paramStr;
	default: return " ";//abnormal case: 없는 타입에 대한 요청이면 parsing하지 않고 " "을 리턴한다
	}
}

COLUMN_NUM Parser::columnStrToNum(const string columnStr) {
	if (columnStr == "employeeNum")	return COLUMN_NUM::employeeNum;
	if (columnStr == "name")		return COLUMN_NUM::name;
	if (columnStr == "cl")			return COLUMN_NUM::cl;
	if (columnStr == "phoneNum")	return COLUMN_NUM::phoneNum;
	if (columnStr == "birthday")	return COLUMN_NUM::birthday;
	if (columnStr == "certi")		return COLUMN_NUM::certi;
	else return COLUMN_NUM::MAX;	//abnormal case
								//	TODO: throw exception?
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
			result.info.employeeNum = validCheckColumnData(words[4], COLUMN_NUM::employeeNum);
			result.info.name = validCheckColumnData(words[5], COLUMN_NUM::name);
			result.info.cl = validCheckColumnData(words[6], COLUMN_NUM::cl);
			result.info.phoneNum = validCheckColumnData(words[7], COLUMN_NUM::phoneNum);
			result.info.birthday = validCheckColumnData(words[8], COLUMN_NUM::birthday);
			result.info.certi = validCheckColumnData(words[9], COLUMN_NUM::certi);
			result.searchColumn = "employeeNum";
			result.searchData = result.info.employeeNum;
			break;
		case OPERATION_TYPE::DEL:
		case OPERATION_TYPE::SCH:
			result.searchColumn = validCheckColumnName(words[4]);
			result.searchData = validCheckColumnData(words[5], columnStrToNum(result.searchColumn));
			break;
		case OPERATION_TYPE::MOD:
			result.searchColumn = validCheckColumnName(words[4]);
			result.searchData = validCheckColumnData(words[5], columnStrToNum(result.searchColumn));
			result.changeColumn = validCheckColumnName(words[6]);
			result.changeData = validCheckColumnData(words[7], columnStrToNum(result.changeColumn));
			break;
		default:
			;
		}
	} catch (exception &e) {
		//TODO: exception ? exception을 던지려면, Manager에서 받아줘야 함
		e.what();
	}
	return result;
}
