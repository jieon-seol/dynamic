#include "Parser.h"

#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

OPERATION_TYPE Parser::parseOperationType(string paramStr) {
	if (paramStr == "ADD") return OPERATION_TYPE::ADD;
	if (paramStr == "DEL") return OPERATION_TYPE::DEL;
	if (paramStr == "SCH") return OPERATION_TYPE::SCH;
	if (paramStr == "MOD") return OPERATION_TYPE::MOD;
	else return OPERATION_TYPE::MAX;	//abnormal case
										//	TODO: throw exception?
}

OPTION1 Parser::parseOption1(std::string paramStr) {
	if (paramStr == "-p") return OPTION1::P;
	if (paramStr == " ") return OPTION1::NONE;	//normal case
	else return OPTION1::MAX;	//abnormal case
								//	TODO: throw exception?
}

OPTION2 Parser::parseOption2(std::string paramStr) {
	if (paramStr == "-y") return OPTION2::Y;
	if (paramStr == "-m") return OPTION2::M;
	if (paramStr == "-d") return OPTION2::D;
	if (paramStr == "-l") return OPTION2::L;
	if (paramStr == "-f") return OPTION2::F;
	if (paramStr == " ") return OPTION2::NONE;	//normal case
	else return OPTION2::MAX;	//abnormal case
								//	TODO: throw exception?
}

OPTION3 Parser::parseOption3(std::string paramStr) {
	if (paramStr == " ") return OPTION3::NONE;	//normal case
	else return OPTION3::MAX;	//abnormal case
								//	TODO: throw exception?
}

std::string Parser::parseColumn(std::string paramStr) {
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

std::string Parser::parseData(std::string paramStr, INFO_TYPE type) {
	//TODO: add valid check -> invalid시에 throw exception
	switch (type) {
	case INFO_TYPE::employeeNum: return paramStr;
	case INFO_TYPE::name: return paramStr;
	case INFO_TYPE::cl: return paramStr;
	case INFO_TYPE::phoneNum: return paramStr;
	case INFO_TYPE::birthday: return paramStr;
	case INFO_TYPE::certi: return paramStr;
	default: return " ";//abnormal case: 없는 타입에 대한 요청이면 parsing하지 않고 " "을 리턴한다
	}
}

INFO_TYPE toInfoType(string columnStr) {
	if (columnStr == "employeeNum")	return INFO_TYPE::employeeNum;
	if (columnStr == "name")		return INFO_TYPE::name;
	if (columnStr == "cl")			return INFO_TYPE::cl;
	if (columnStr == "phoneNum")	return INFO_TYPE::phoneNum;
	if (columnStr == "birthday")	return INFO_TYPE::birthday;
	if (columnStr == "certi")		return INFO_TYPE::certi;
	else return INFO_TYPE::MAX;	//abnormal case
								//	TODO: throw exception?
}

struct ParserResult Parser::parse(string queryStirng) {
	struct ParserResult result;
	vector<string> words;
	istringstream ss(queryStirng);
	string word;

	try {
		while (getline(ss, word, ',')) {
			words.push_back(word);
		}

		//TODO: try-catch 추가 (parsing Error)
		result.operationType = parseOperationType(words[0]);
		result.option1 = parseOption1(words[1]);
		result.option2 = parseOption2(words[2]);
		result.option3 = parseOption3(words[3]);

		switch (result.operationType) {
		case OPERATION_TYPE::ADD:
			result.info.employeeNum = parseData(words[4], INFO_TYPE::employeeNum);
			result.info.name = parseData(words[5], INFO_TYPE::name);
			result.info.cl = parseData(words[6], INFO_TYPE::cl);
			result.info.phoneNum = parseData(words[7], INFO_TYPE::phoneNum);
			result.info.birthday = parseData(words[8], INFO_TYPE::birthday);
			result.info.certi = parseData(words[9], INFO_TYPE::certi);
			result.searchColumn = "employeeNum";
			result.searchData = result.info.employeeNum;
			break;
		case OPERATION_TYPE::DEL:
		case OPERATION_TYPE::SCH:
			result.searchColumn = parseColumn(words[4]);
			result.searchData = parseData(words[5], toInfoType(result.searchColumn));
			break;
		case OPERATION_TYPE::MOD:
			result.searchColumn = parseColumn(words[4]);
			result.searchData = parseData(words[5], toInfoType(result.searchColumn));
			result.changeColumn = parseColumn(words[6]);
			result.changeData = parseData(words[7], toInfoType(result.changeColumn));
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