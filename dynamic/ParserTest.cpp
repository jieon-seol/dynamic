#include "gtest/gtest.h"
#include "Parser.h"
#include <string>
using namespace std;

class ParserTestPrivate : public ::testing::Test {
protected:
	OPERATION_TYPE parseOperationType(const std::string paramStr) { return parser.parseOperationType(paramStr); }
	OPTION1 parseOption1(const std::string paramStr) { return parser.parseOption1(paramStr); }
	OPTION2 parseOption2(const std::string paramStr) { return parser.parseOption2(paramStr); }
	OPTION3 parseOption3(const std::string paramStr) { return parser.parseOption3(paramStr); }
	std::string validCheckColumnName(const std::string columnStr) { return parser.validCheckColumnName(columnStr); }
	std::string validCheckColumnData(const std::string dataStr, const string columnStr) { return parser.validCheckColumnData(dataStr, columnStr); }
private:
	Parser parser;
};

TEST_F(ParserTestPrivate, test_refactoring_column) {
	EXPECT_EQ(COLUMN_NUM::employeeNum, columnStrToNum("employeeNum"));
	EXPECT_EQ(COLUMN_NUM::name, columnStrToNum("name"));
	EXPECT_EQ(COLUMN_NUM::cl, columnStrToNum("cl"));
	EXPECT_EQ(COLUMN_NUM::phoneNum, columnStrToNum("phoneNum"));
	EXPECT_EQ(COLUMN_NUM::birthday, columnStrToNum("birthday"));
	EXPECT_EQ(COLUMN_NUM::certi, columnStrToNum("certi"));

	EXPECT_EQ(columnNumToStr(COLUMN_NUM::employeeNum), "employeeNum");
	EXPECT_EQ(columnNumToStr(COLUMN_NUM::name), "name");
	EXPECT_EQ(columnNumToStr(COLUMN_NUM::cl), "cl");
	EXPECT_EQ(columnNumToStr(COLUMN_NUM::phoneNum), "phoneNum");
	EXPECT_EQ(columnNumToStr(COLUMN_NUM::birthday), "birthday");
	EXPECT_EQ(columnNumToStr(COLUMN_NUM::certi), "certi");

	EXPECT_EQ("employeeNum", validCheckColumnName("employeeNum"));
	EXPECT_EQ("name", validCheckColumnName("name"));
	EXPECT_EQ("cl", validCheckColumnName("cl"));
	EXPECT_EQ("phoneNum", validCheckColumnName("phoneNum"));
	EXPECT_EQ("birthday", validCheckColumnName("birthday"));
	EXPECT_EQ("certi", validCheckColumnName("certi"));

	//regex
	EXPECT_EQ("010-1234-1234", validCheckColumnData("010-1234-1234", "phoneNum"));
	EXPECT_EQ("010-124-1234", validCheckColumnData("010-124-1234", "phoneNum"));
	EXPECT_EQ("TTETHU HBO", validCheckColumnData("TTETHU HBO", "name"));
	EXPECT_EQ("CL2", validCheckColumnData("CL2", "cl"));
	EXPECT_EQ("19861203", validCheckColumnData("19861203", "birthday"));
	EXPECT_EQ("PRO", validCheckColumnData("PRO", "certi"));
}
#if 10

TEST_F(ParserTestPrivate, Test_PrivateMethod) {


	EXPECT_EQ(OPERATION_TYPE::ADD, parseOperationType("ADD"));
	EXPECT_EQ(OPERATION_TYPE::DEL, parseOperationType("DEL"));
	EXPECT_EQ(OPERATION_TYPE::SCH, parseOperationType("SCH"));
	EXPECT_EQ(OPERATION_TYPE::MOD, parseOperationType("MOD"));
	//TODO: exception case
	//EXPECT_EQ(OPERATION_TYPE::MAX, parseOperationType("ABCD"));

	EXPECT_EQ(OPTION1::P, parseOption1("-p"));
	EXPECT_EQ(OPTION1::NONE, parseOption1(" "));
	//TODO: exception case
	//EXPECT_EQ(OPTION1::MAX, parseOption1("-r"));

	EXPECT_EQ(OPTION2::Y, parseOption2("-y"));
	EXPECT_EQ(OPTION2::M, parseOption2("-m"));
	EXPECT_EQ(OPTION2::D, parseOption2("-d"));
	EXPECT_EQ(OPTION2::L, parseOption2("-l"));
	EXPECT_EQ(OPTION2::F, parseOption2("-f"));
	EXPECT_EQ(OPTION2::NONE, parseOption2(" "));
	//TODO: exception case
	//EXPECT_EQ(OPTION2::MAX, parseOption2("-s"));

	EXPECT_EQ(OPTION3::NONE, parseOption3(" "));
	//TODO: exception case
	//EXPECT_EQ(OPTION2::MAX, parseOption2("-q"));

	EXPECT_EQ("employeeNum", validCheckColumnName("employeeNum"));
	EXPECT_EQ("name", validCheckColumnName("name"));
	EXPECT_EQ("cl", validCheckColumnName("cl"));
	EXPECT_EQ("phoneNum", validCheckColumnName("phoneNum"));
	EXPECT_EQ("birthday", validCheckColumnName("birthday"));
	EXPECT_EQ("certi", validCheckColumnName("certi"));
	//TODO: exception case
	//EXPECT_EQ("asdf", validCheckColumnName("certi"));

	//TODO: parserData()에 대한 예외처리 구현 & test
}
#endif

#if 10

TEST(ParserTest, test_ADD_normal_01) {
	Parser* pParser = new Parser();
	string str = "ADD, , , ,15123099,VXIHXOTH JHOP,CL3,010-3112-2609,19771211,ADV";
	struct ParserResult result = pParser->parse(str);

	EXPECT_EQ(OPERATION_TYPE::ADD, result.operationType);
	EXPECT_EQ(OPTION1::NONE, result.option1);
	EXPECT_EQ(OPTION2::NONE, result.option2);
	EXPECT_EQ(OPTION3::NONE, result.option3);
	EXPECT_EQ("15123099", result.info.employeeNum);
	EXPECT_EQ("VXIHXOTH JHOP", result.info.name);
	EXPECT_EQ("CL3", result.info.cl);
	EXPECT_EQ("010-3112-2609", result.info.phoneNum);
	EXPECT_EQ("19771211", result.info.birthday);
	EXPECT_EQ("ADV", result.info.certi);
}
#endif

#if 10
TEST(ParserTest, test_DEL_normal_01_employeeNum) {
	Parser* pParser = new Parser();
	string str = "DEL, , , ,employeeNum,18115040";
	struct ParserResult result = pParser->parse(str);

	EXPECT_EQ(OPERATION_TYPE::DEL, result.operationType);
	EXPECT_EQ(OPTION1::NONE, result.option1);
	EXPECT_EQ(OPTION2::NONE, result.option2);
	EXPECT_EQ(OPTION3::NONE, result.option3);
	EXPECT_EQ("employeeNum", result.searchColumn);
	EXPECT_EQ("18115040", result.searchData);
	EXPECT_EQ("", result.info.employeeNum);
	EXPECT_EQ("", result.info.name);
	EXPECT_EQ("", result.info.cl);
	EXPECT_EQ("", result.info.phoneNum);
	EXPECT_EQ("", result.info.birthday);
	EXPECT_EQ("", result.info.certi);
}
TEST(ParserTest, test_DEL_normal_02_name_01) {
	Parser* pParser = new Parser();
	string str = "DEL, , , ,name,MPOSXU";
	struct ParserResult result = pParser->parse(str);

	EXPECT_EQ(OPERATION_TYPE::DEL, result.operationType);
	EXPECT_EQ(OPTION1::NONE, result.option1);
	EXPECT_EQ(OPTION2::NONE, result.option2);
	EXPECT_EQ(OPTION3::NONE, result.option3);
	EXPECT_EQ("name", result.searchColumn);
	EXPECT_EQ("MPOSXU", result.searchData);
	EXPECT_EQ("", result.info.employeeNum);
	EXPECT_EQ("", result.info.name);
	EXPECT_EQ("", result.info.cl);
	EXPECT_EQ("", result.info.phoneNum);
	EXPECT_EQ("", result.info.birthday);
	EXPECT_EQ("", result.info.certi);
}
TEST(ParserTest, test_DEL_normal_02_name_02) {
	Parser* pParser = new Parser();
	string str = "DEL,-p,-l, ,name,MPOSXU";
	struct ParserResult result = pParser->parse(str);

	EXPECT_EQ(OPERATION_TYPE::DEL, result.operationType);
	EXPECT_EQ(OPTION1::P, result.option1);
	EXPECT_EQ(OPTION2::L, result.option2);
	EXPECT_EQ(OPTION3::NONE, result.option3);
	EXPECT_EQ("name", result.searchColumn);
	EXPECT_EQ("MPOSXU", result.searchData);
	EXPECT_EQ("", result.info.employeeNum);
	EXPECT_EQ("", result.info.name);
	EXPECT_EQ("", result.info.cl);
	EXPECT_EQ("", result.info.phoneNum);
	EXPECT_EQ("", result.info.birthday);
	EXPECT_EQ("", result.info.certi);
}
TEST(ParserTest, test_DEL_normal_02_name_03) {
	Parser* pParser = new Parser();
	string str = "DEL,-p,-f, ,name,MPOSXU";
	struct ParserResult result = pParser->parse(str);

	EXPECT_EQ(OPERATION_TYPE::DEL, result.operationType);
	EXPECT_EQ(OPTION1::P, result.option1);
	EXPECT_EQ(OPTION2::F, result.option2);
	EXPECT_EQ(OPTION3::NONE, result.option3);
	EXPECT_EQ("name", result.searchColumn);
	EXPECT_EQ("MPOSXU", result.searchData);
	EXPECT_EQ("", result.info.employeeNum);
	EXPECT_EQ("", result.info.name);
	EXPECT_EQ("", result.info.cl);
	EXPECT_EQ("", result.info.phoneNum);
	EXPECT_EQ("", result.info.birthday);
	EXPECT_EQ("", result.info.certi);
}
TEST(ParserTest, test_DEL_normal_03_cl) {
	Parser* pParser = new Parser();
	string str = "DEL,-p, , ,cl,CL3";
	struct ParserResult result = pParser->parse(str);

	EXPECT_EQ(OPERATION_TYPE::DEL, result.operationType);
	EXPECT_EQ(OPTION1::P, result.option1);
	EXPECT_EQ(OPTION2::NONE, result.option2);
	EXPECT_EQ(OPTION3::NONE, result.option3);
	EXPECT_EQ("cl", result.searchColumn);
	EXPECT_EQ("CL3", result.searchData);
	EXPECT_EQ("", result.info.employeeNum);
	EXPECT_EQ("", result.info.name);
	EXPECT_EQ("", result.info.cl);
	EXPECT_EQ("", result.info.phoneNum);
	EXPECT_EQ("", result.info.birthday);
	EXPECT_EQ("", result.info.certi);
}
TEST(ParserTest, test_DEL_normal_04_phoneNum) {
	Parser* pParser = new Parser();
	string str = "DEL,-p,-m, ,phoneNum,010-5645-6122";
	struct ParserResult result = pParser->parse(str);

	EXPECT_EQ(OPERATION_TYPE::DEL, result.operationType);
	EXPECT_EQ(OPTION1::P, result.option1);
	EXPECT_EQ(OPTION2::M, result.option2);
	EXPECT_EQ(OPTION3::NONE, result.option3);
	EXPECT_EQ("phoneNum", result.searchColumn);
	EXPECT_EQ("010-5645-6122", result.searchData);
	EXPECT_EQ("", result.info.employeeNum);
	EXPECT_EQ("", result.info.name);
	EXPECT_EQ("", result.info.cl);
	EXPECT_EQ("", result.info.phoneNum);
	EXPECT_EQ("", result.info.birthday);
	EXPECT_EQ("", result.info.certi);
}
TEST(ParserTest, test_DEL_normal_05_birthday) {
	Parser* pParser = new Parser();
	string str = "DEL, ,-d, ,birthday,79110836";
	struct ParserResult result = pParser->parse(str);

	EXPECT_EQ(OPERATION_TYPE::DEL, result.operationType);
	EXPECT_EQ(OPTION1::NONE, result.option1);
	EXPECT_EQ(OPTION2::D, result.option2);
	EXPECT_EQ(OPTION3::NONE, result.option3);
	EXPECT_EQ("birthday", result.searchColumn);
	EXPECT_EQ("79110836", result.searchData);
	EXPECT_EQ("", result.info.employeeNum);
	EXPECT_EQ("", result.info.name);
	EXPECT_EQ("", result.info.cl);
	EXPECT_EQ("", result.info.phoneNum);
	EXPECT_EQ("", result.info.birthday);
	EXPECT_EQ("", result.info.certi);
}
TEST(ParserTest, test_DEL_normal_06_certi) {
	Parser* pParser = new Parser();
	string str = "DEL,-p, , ,certi,PRO";
	struct ParserResult result = pParser->parse(str);

	EXPECT_EQ(OPERATION_TYPE::DEL, result.operationType);
	EXPECT_EQ(OPTION1::P, result.option1);
	EXPECT_EQ(OPTION2::NONE, result.option2);
	EXPECT_EQ(OPTION3::NONE, result.option3);
	EXPECT_EQ("certi", result.searchColumn);
	EXPECT_EQ("PRO", result.searchData);
	EXPECT_EQ("", result.info.employeeNum);
	EXPECT_EQ("", result.info.name);
	EXPECT_EQ("", result.info.cl);
	EXPECT_EQ("", result.info.phoneNum);
	EXPECT_EQ("", result.info.birthday);
	EXPECT_EQ("", result.info.certi);
}

TEST(ParserTest, test_SCH_normal_01_birthday) {
	Parser* pParser = new Parser();
	string str = "SCH,-p,-d, ,birthday,22020217";
	struct ParserResult result = pParser->parse(str);

	EXPECT_EQ(OPERATION_TYPE::SCH, result.operationType);
	EXPECT_EQ(OPTION1::P, result.option1);
	EXPECT_EQ(OPTION2::D, result.option2);
	EXPECT_EQ(OPTION3::NONE, result.option3);
	EXPECT_EQ("birthday", result.searchColumn);
	EXPECT_EQ("22020217", result.searchData);
	EXPECT_EQ("", result.info.employeeNum);
	EXPECT_EQ("", result.info.name);
	EXPECT_EQ("", result.info.cl);
	EXPECT_EQ("", result.info.phoneNum);
	EXPECT_EQ("", result.info.birthday);
	EXPECT_EQ("", result.info.certi);
}

TEST(ParserTest, test_MOD_normal_01) {
	Parser* pParser = new Parser();
	string str = "MOD,-p, , ,phoneNum,010-8900-1478,certi,PRO";
	struct ParserResult result = pParser->parse(str);

	EXPECT_EQ(OPERATION_TYPE::MOD, result.operationType);
	EXPECT_EQ(OPTION1::P, result.option1);
	EXPECT_EQ(OPTION2::NONE, result.option2);
	EXPECT_EQ(OPTION3::NONE, result.option3);
	EXPECT_EQ("phoneNum", result.searchColumn);
	EXPECT_EQ("010-8900-1478", result.searchData);
	EXPECT_EQ("certi", result.changeColumn);
	EXPECT_EQ("PRO", result.changeData);
	EXPECT_EQ("", result.info.employeeNum);
	EXPECT_EQ("", result.info.name);
	EXPECT_EQ("", result.info.cl);
	EXPECT_EQ("", result.info.phoneNum);
	EXPECT_EQ("", result.info.birthday);
	EXPECT_EQ("", result.info.certi);
}
//TODO: exception case에 대한 TC 추가

#endif