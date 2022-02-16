#include "gtest/gtest.h"
#include "Operator.h"


TEST(OPERATORTEST, AddOperatorTest) {
	std::vector<EmployeeInfo> dataBase;
	Operator* addOper = new AddOperator(&dataBase);

	std::vector<EmployeeInfo> searchedDataBase;
	searchedDataBase.emplace_back(EmployeeInfo{ "01122329", "DN WD", "CL4", "010-7174-5680", "20071117", "PRO" });



	ParserResult FakeParserResult = { OPERATION_TYPE::ADD,
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
	addOper->operate(&searchedDataBase, FakeParserResult);
	EXPECT_EQ(dataBase.size(), 1);

	for (const auto& employee : dataBase) {
		EXPECT_EQ(employee.employeeNum, "01122329");
	}
}

TEST(OPERATORTEST, DeleteOperatorTest) {
		std::vector<EmployeeInfo> dataBase;
		Operator* addOper = new AddOperator(&dataBase);
		Operator* delOper = new DeleteOperator(&dataBase);

		std::vector<EmployeeInfo> searchedDataBase;
		searchedDataBase.emplace_back(EmployeeInfo{ "01122329", "DN WD", "CL4", "010-7174-5680", "20071117", "PRO" });

		ParserResult FakeParserResult = { OPERATION_TYPE::ADD,
										OPTION1::NONE,
										OPTION2::NONE,
										OPTION3::NONE,
										std::string(),
										std::string(),
										std::string(),
										std::string(),
										EmployeeInfo{ "01122329", "DN WD", "CL4", "010-7174-5680", "20071117", "PRO" }
		};

		EXPECT_EQ(dataBase.size(), 0);
		addOper->operate(&searchedDataBase, FakeParserResult);
		EXPECT_EQ(dataBase.size(), 1);

		for (const auto& employee : dataBase) {
			EXPECT_EQ(employee.employeeNum, "01122329");
		}

		delOper->operate(&searchedDataBase, FakeParserResult);
		EXPECT_EQ(dataBase.size(), 0);

}


TEST(OPERATORTEST, ModifyOperatorTest) {
	std::vector<EmployeeInfo> dataBase;
	Operator* addOper = new AddOperator(&dataBase);
	Operator* ModOper = new ModifyOperator(&dataBase);

	std::vector<EmployeeInfo> searchedDataBase;
	searchedDataBase.emplace_back(EmployeeInfo{ "01122329", "DN WD", "CL4", "010-7174-5680", "20071117", "PRO" });
	searchedDataBase.emplace_back(EmployeeInfo{ "08108827", "RTAH VNUP", "CL3", "010-9031-2726", "19780417", "ADV" });
	searchedDataBase.emplace_back(EmployeeInfo{ "85125741", "FBAH RTIJ", "CL1", "010-8900-1478", "19780228", "ADV" });

	ParserResult FakeParserResult = { OPERATION_TYPE::ADD,
								OPTION1::NONE,
								OPTION2::NONE,
								OPTION3::NONE,
								std::string(),
								std::string(),
								"certi",
								"EX",
								EmployeeInfo{ "01122329", "DN WD", "CL4", "010-7174-5680", "20071117", "PRO" }
	};


	addOper->operate(&searchedDataBase, FakeParserResult);

	ModOper->operate(&searchedDataBase, FakeParserResult);


	for (const auto& employee : dataBase) {
		EXPECT_EQ(employee.certi, "EX");
	}


}



