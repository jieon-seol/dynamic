#include "gtest/gtest.h"
#include "Operator.h"

namespace {
	void IsEmployeeInfoMatched(const std::map<int, EmployeeInfo>& dataBase, int key,
		const std::string& employeeNum, const std::string& name, const std::string& cl,
		const std::string& phoneNum, const std::string& birthday, const std::string& certi) {
		EXPECT_EQ(dataBase.at(key).employeeNum, employeeNum);
		EXPECT_EQ(dataBase.at(key).name, name);
		EXPECT_EQ(dataBase.at(key).cl, cl);
		EXPECT_EQ(dataBase.at(key).phoneNum, phoneNum);
		EXPECT_EQ(dataBase.at(key).birthday, birthday);
		EXPECT_EQ(dataBase.at(key).certi, certi);
	}
}


TEST(OPERATORTEST, AddOperatorTest) {
	std::map<int, EmployeeInfo> dataBase;
	Operator* pAddOper = new AddOperator(&dataBase);

	std::map<int, EmployeeInfo> emptyDataBase;
	ParserResult addParserResult = { OPERATION_TYPE::ADD,
									OPTION1::NONE,
									OPTION2::NONE,
									OPTION3::NONE,
									std::string(),
									std::string(),
									std::string(),
									std::string(),
									EmployeeInfo{ "01122329", "DN WD", "CL4", "010-7174-5680", "20071117", "PRO" }
	};

	EXPECT_EQ(dataBase.size(),0);

	pAddOper->operate(&emptyDataBase, addParserResult);

	EXPECT_EQ(dataBase.size(), 1);

	for (const auto& employee : dataBase) {
		EXPECT_EQ(employee.second.employeeNum, "01122329");
	}
	IsEmployeeInfoMatched(dataBase, 2001122329, "01122329", "DN WD", "CL4", "010-7174-5680", "20071117", "PRO");
}

TEST(OPERATORTEST, DeleteOperatorTest) {
		std::map<int, EmployeeInfo> dataBase;
		Operator* pAddOper = new AddOperator(&dataBase);
		Operator* pDelOper = new DeleteOperator(&dataBase);

		std::map<int, EmployeeInfo> searchedDelDataBase;
		ParserResult addParserResult = { OPERATION_TYPE::ADD,
										OPTION1::NONE,
										OPTION2::NONE,
										OPTION3::NONE,
										std::string(),
										std::string(),
										std::string(),
										std::string(),
										EmployeeInfo{ "01122329", "DN WD", "CL4", "010-7174-5680", "20071117", "PRO" }
		};

		pAddOper->operate(&searchedDelDataBase, addParserResult);

		EXPECT_EQ(dataBase.size(), 1);
		searchedDelDataBase[2001122329] = EmployeeInfo{ "01122329", "DN WD", "CL4", "010-7174-5680", "20071117", "PRO" };

		pDelOper->operate(&searchedDelDataBase, addParserResult);

		EXPECT_EQ(dataBase.size(), 0);
}

TEST(OPERATORTEST, ModifyOperatorPositiveTest) {
	std::map<int, EmployeeInfo> dataBase;
	Operator* pAddOper = new AddOperator(&dataBase);
	Operator* pModOper = new ModifyOperator(&dataBase);

	std::map<int, EmployeeInfo> searchedModDataBase;

	ParserResult addParserResult = { OPERATION_TYPE::ADD,
								OPTION1::NONE,
								OPTION2::NONE,
								OPTION3::NONE,
								std::string(),
								std::string(),
								std::string(),
								std::string(),
								EmployeeInfo{ "01122329", "DN WD", "CL4", "010-7174-5680", "20071117", "PRO" }
	};
	pAddOper->operate(&searchedModDataBase, addParserResult);

	addParserResult.info = EmployeeInfo{ "08108827", "RTAH VNUP", "CL3", "010-9031-2726", "19780417", "ADV" };
	pAddOper->operate(&searchedModDataBase, addParserResult);

	addParserResult.info = EmployeeInfo{ "85125741", "FBAH RTIJ", "CL1", "010-8900-1478", "19780228", "ADV" };
	pAddOper->operate(&searchedModDataBase, addParserResult);

	EXPECT_EQ(dataBase.size(), 3);

	searchedModDataBase[2001122329] = EmployeeInfo{ "01122329", "DN WD", "CL4", "010-7174-5680", "20071117", "PRO" };
	searchedModDataBase[2008108827] = EmployeeInfo{ "08108827", "RTAH VNUP", "CL3", "010-9031-2726", "19780417", "ADV" };
	searchedModDataBase[1985125741] = EmployeeInfo{ "85125741", "FBAH RTIJ", "CL1", "010-8900-1478", "19780228", "ADV" };

	ParserResult modifyParserResult = { OPERATION_TYPE::ADD,
								OPTION1::NONE,
								OPTION2::NONE,
								OPTION3::NONE,
								std::string(),
								std::string(),
								std::string(),
								std::string(),
								EmployeeInfo{ "01122329", "DN WD", "CL4", "010-7174-5680", "20071117", "PRO" }
	};
	modifyParserResult.changeColumn = "certi";
	modifyParserResult.changeData = "EX";
	pModOper->operate(&searchedModDataBase, modifyParserResult);

	
	IsEmployeeInfoMatched(dataBase, 2001122329, "01122329", "DN WD", "CL4", "010-7174-5680", "20071117", "EX");
	IsEmployeeInfoMatched(dataBase, 2008108827, "08108827", "RTAH VNUP", "CL3", "010-9031-2726", "19780417", "EX");
	IsEmployeeInfoMatched(dataBase, 1985125741, "85125741", "FBAH RTIJ", "CL1", "010-8900-1478", "19780228", "EX");


	modifyParserResult.changeColumn = "name";
	modifyParserResult.changeData = "HYUN JUN SHIN";
	pModOper->operate(&searchedModDataBase, modifyParserResult);

	IsEmployeeInfoMatched(dataBase, 2001122329, "01122329", "HYUN JUN SHIN", "CL4", "010-7174-5680", "20071117", "EX");
	IsEmployeeInfoMatched(dataBase, 2008108827, "08108827", "HYUN JUN SHIN", "CL3", "010-9031-2726", "19780417", "EX");
	IsEmployeeInfoMatched(dataBase, 1985125741, "85125741", "HYUN JUN SHIN", "CL1", "010-8900-1478", "19780228", "EX");


	modifyParserResult.changeColumn = "cl";
	modifyParserResult.changeData = "CL2";
	pModOper->operate(&searchedModDataBase, modifyParserResult);

	IsEmployeeInfoMatched(dataBase, 2001122329, "01122329", "HYUN JUN SHIN", "CL2", "010-7174-5680", "20071117", "EX");
	IsEmployeeInfoMatched(dataBase, 2008108827, "08108827", "HYUN JUN SHIN", "CL2", "010-9031-2726", "19780417", "EX");
	IsEmployeeInfoMatched(dataBase, 1985125741, "85125741", "HYUN JUN SHIN", "CL2", "010-8900-1478", "19780228", "EX");

	modifyParserResult.changeColumn = "phoneNum";
	modifyParserResult.changeData = "010-4233-7244";
	pModOper->operate(&searchedModDataBase, modifyParserResult);

	IsEmployeeInfoMatched(dataBase, 2001122329, "01122329", "HYUN JUN SHIN", "CL2", "010-4233-7244", "20071117", "EX");
	IsEmployeeInfoMatched(dataBase, 2008108827, "08108827", "HYUN JUN SHIN", "CL2", "010-4233-7244", "19780417", "EX");
	IsEmployeeInfoMatched(dataBase, 1985125741, "85125741", "HYUN JUN SHIN", "CL2", "010-4233-7244", "19780228", "EX");


	modifyParserResult.changeColumn = "birthday";
	modifyParserResult.changeData = "20030105";
	pModOper->operate(&searchedModDataBase, modifyParserResult);

	IsEmployeeInfoMatched(dataBase, 2001122329, "01122329", "HYUN JUN SHIN", "CL2", "010-4233-7244", "20030105", "EX");
	IsEmployeeInfoMatched(dataBase, 2008108827, "08108827", "HYUN JUN SHIN", "CL2", "010-4233-7244", "20030105", "EX");
	IsEmployeeInfoMatched(dataBase, 1985125741, "85125741", "HYUN JUN SHIN", "CL2", "010-4233-7244", "20030105", "EX");

}



TEST(OPERATORTEST, ModifyOperatorNegativeTest) {
	std::map<int, EmployeeInfo> dataBase;
	Operator* pAddOper = new AddOperator(&dataBase);
	Operator* pModOper = new ModifyOperator(&dataBase);

	std::map<int, EmployeeInfo> searchedModDataBase;

	ParserResult addParserResult = { OPERATION_TYPE::ADD,
								OPTION1::NONE,
								OPTION2::NONE,
								OPTION3::NONE,
								std::string(),
								std::string(),
								std::string(),
								std::string(),
								EmployeeInfo{ "01122329", "DN WD", "CL4", "010-7174-5680", "20071117", "PRO" }
	};
	pAddOper->operate(&searchedModDataBase, addParserResult);

	addParserResult.info = EmployeeInfo{ "08108827", "RTAH VNUP", "CL3", "010-9031-2726", "19780417", "ADV" };
	pAddOper->operate(&searchedModDataBase, addParserResult);

	addParserResult.info = EmployeeInfo{ "85125741", "FBAH RTIJ", "CL1", "010-8900-1478", "19780228", "ADV" };
	pAddOper->operate(&searchedModDataBase, addParserResult);

	EXPECT_EQ(dataBase.size(), 3);

	searchedModDataBase[2001122329] = EmployeeInfo{ "01122329", "DN WD", "CL4", "010-7174-5680", "20071117", "PRO" };
	searchedModDataBase[2008108827] = EmployeeInfo{ "08108827", "RTAH VNUP", "CL3", "010-9031-2726", "19780417", "ADV" };
	searchedModDataBase[1985125741] = EmployeeInfo{ "85125741", "FBAH RTIJ", "CL1", "010-8900-1478", "19780228", "ADV" };


	addParserResult.changeColumn = "employeeNum";
	addParserResult.changeData = "28360004";
	pModOper->operate(&searchedModDataBase, addParserResult);

	EXPECT_FALSE(dataBase[2028360004].employeeNum == "28360004");
	EXPECT_TRUE(dataBase[2001122329].employeeNum == "01122329");

	EXPECT_FALSE(dataBase[2028360004].employeeNum == "28360004");
	EXPECT_TRUE(dataBase[2008108827].employeeNum == "08108827");

	EXPECT_FALSE(dataBase[2028360004].employeeNum == "28360004");
	EXPECT_TRUE(dataBase[1985125741].employeeNum == "85125741");
	
}

