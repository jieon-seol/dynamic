#include "gtest/gtest.h"
#include "Searcher.h"

using namespace std;

bool compareEmployeeInfo(const EmployeeInfo& info1, const EmployeeInfo& info2) {
	if (info1.employeeNum != info2.employeeNum) return false;
	if (info1.name.compare(info2.name)) return false;
	if (info1.cl != info2.cl) return false;
	if (info1.phoneNum.compare(info2.phoneNum)) return false;
	if (info1.birthday.compare(info2.birthday)) return false;
	if (info1.certi != info2.certi) return false;

	return true;
}

TEST(EmployeeNumSearchTest, NoOptionTest) {
	map<string, EmployeeInfo> dataBase;
	dataBase["2018051224"] = EmployeeInfo({ "18051224", "YEONGCHUL CHO", "CL2" , "010-4198-8858", "19930116", "PRO" });
	dataBase["2017256132"] = EmployeeInfo({ "17256132", "JUNHYUCK SHIN", "CL2" , "010-2135-1546", "19910526", "EX" });
	dataBase["2020031242"] = EmployeeInfo({ "20031242", "JUNGHOON KONG", "CL2" , "010-4756-9871", "19930821", "PRO" });
	dataBase["2014321152"] = EmployeeInfo({ "14321152", "INSOO KIM", "CL2" , "010-1312-4356", "19910415", "ADV" });
	dataBase["2012035123"] = EmployeeInfo({ "12035123", "JONGWON KIM", "CL3" , "010-6855-9852", "19850720", "PRO" });
	dataBase["2008051231"] = EmployeeInfo({ "08051231", "SINHO OH", "CL4" , "010-5563-8744", "19800420", "PRO" });

	Searcher* pSearcher = new EmployeeNumSearcher(&dataBase);

	map<string, EmployeeInfo> result1 = pSearcher->search(ParserResult({ OPERATION_TYPE::SCH, OPTION1::NONE, OPTION2::NONE, OPTION3::NONE, "employeeNum", "18051224", "", "" }));
	EXPECT_EQ(1, result1.size());
	EXPECT_EQ(1, result1.count("2018051224"));
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "18051224", "YEONGCHUL CHO", "CL2" , "010-4198-8858", "19930116", "PRO" }), result1["2018051224"]));

	map<string, EmployeeInfo> result2 = pSearcher->search(ParserResult({ OPERATION_TYPE::SCH, OPTION1::NONE, OPTION2::NONE, OPTION3::NONE, "employeeNum", "17256132", "", "" }));
	EXPECT_EQ(1, result2.size());
	EXPECT_EQ(1, result2.count("2017256132"));
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "17256132", "JUNHYUCK SHIN", "CL2" , "010-2135-1546", "19910526", "EX" }), result2["2017256132"]));
	EXPECT_FALSE(compareEmployeeInfo(EmployeeInfo({ "20031242", "JUNGHOON KONG", "CL2" , "010-4756-9871", "19930821", "PRO" }), result2["2017256132"]));

	map<string, EmployeeInfo> result3 = pSearcher->search(ParserResult({ OPERATION_TYPE::SCH, OPTION1::NONE, OPTION2::NONE, OPTION3::NONE, "employeeNum", "08051231", "", "" }));
	EXPECT_EQ(1, result3.size());
	EXPECT_EQ(1, result3.count("2008051231"));
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "08051231", "SINHO OH", "CL4" , "010-5563-8744", "19800420", "PRO" }), result3["2008051231"]));

	delete pSearcher;
}

TEST(NameSearchTest, NoOptionTest) {
	map<string, EmployeeInfo> dataBase;
	dataBase["2018051224"] = EmployeeInfo({ "18051224", "YEONGCHUL CHO", "CL2" , "010-4198-8858", "19930116", "PRO" });
	dataBase["2017256132"] = EmployeeInfo({ "17256132", "JUNHYUCK SHIN", "CL2" , "010-2135-1546", "19910526", "EX" });
	dataBase["2020031242"] = EmployeeInfo({ "20031242", "JUNGHOON KONG", "CL2" , "010-4756-9871", "19930821", "PRO" });
	dataBase["2014321152"] = EmployeeInfo({ "14321152", "INSOO KIM", "CL2" , "010-1312-4356", "19910415", "ADV" });
	dataBase["2012035123"] = EmployeeInfo({ "12035123", "JONGWON KIM", "CL3" , "010-6855-9852", "19850720", "PRO" });
	dataBase["2008051231"] = EmployeeInfo({ "08051231", "SINHO OH", "CL4" , "010-5563-8744", "19800420", "PRO" });

	Searcher* pSearcher = new NameSearcher(&dataBase);

	map<string, EmployeeInfo> result1 = pSearcher->search(ParserResult({ OPERATION_TYPE::SCH, OPTION1::NONE, OPTION2::NONE, OPTION3::NONE, "name", "JUNHYUCK SHIN", "", "" }));
	EXPECT_EQ(1, result1.size());
	EXPECT_EQ(1, result1.count("2017256132"));
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "17256132", "JUNHYUCK SHIN", "CL2" , "010-2135-1546", "19910526", "EX" }), result1["2017256132"]));

	map<string, EmployeeInfo> result2 = pSearcher->search(ParserResult({ OPERATION_TYPE::SCH, OPTION1::NONE, OPTION2::NONE, OPTION3::NONE, "name", "KIM INSU", "", "" }));
	EXPECT_EQ(0, result2.size());

	delete pSearcher;
}

TEST(NameSearchTest, OptionTest) {
	map<string, EmployeeInfo> dataBase;
	dataBase["2018051224"] = EmployeeInfo({ "18051224", "YEONGCHUL CHO", "CL2" , "010-4198-8858", "19930116", "PRO" });
	dataBase["2017256132"] = EmployeeInfo({ "17256132", "JUNHYUCK SHIN", "CL2" , "010-2135-1546", "19910526", "EX" });
	dataBase["2020031242"] = EmployeeInfo({ "20031242", "JUNGHOON KONG", "CL2" , "010-4756-9871", "19930821", "PRO" });
	dataBase["2014321152"] = EmployeeInfo({ "14321152", "INSOO KIM", "CL2" , "010-1312-4356", "19910415", "ADV" });
	dataBase["2012035123"] = EmployeeInfo({ "12035123", "JONGWON KIM", "CL3" , "010-6855-9852", "19850720", "PRO" });
	dataBase["2008051231"] = EmployeeInfo({ "08051231", "SINHO OH", "CL4" , "010-5563-8744", "19800420", "PRO" });

	Searcher* pSearcher = new NameSearcher(&dataBase);

	map<string, EmployeeInfo> result1 = pSearcher->search(ParserResult({ OPERATION_TYPE::SCH, OPTION1::NONE, OPTION2::F, OPTION3::NONE, "name", "YEONGCHUL", "", "" }));
	EXPECT_EQ(1, result1.size());
	EXPECT_EQ(1, result1.count("2018051224"));
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "18051224", "YEONGCHUL CHO", "CL2" , "010-4198-8858", "19930116", "PRO" }), result1["2018051224"]));

	map<string, EmployeeInfo> result2 = pSearcher->search(ParserResult({ OPERATION_TYPE::SCH, OPTION1::NONE, OPTION2::L, OPTION3::NONE, "name", "KIM", "", "" }));
	EXPECT_EQ(2, result2.size());
	EXPECT_EQ(1, result2.count("2014321152"));
	EXPECT_EQ(1, result2.count("2012035123"));
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "14321152", "INSOO KIM", "CL2" , "010-1312-4356", "19910415", "ADV" }), result2["2014321152"]));
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "12035123", "JONGWON KIM", "CL3" , "010-6855-9852", "19850720", "PRO" }), result2["2012035123"]));

	map<string, EmployeeInfo> result3 = pSearcher->search(ParserResult({ OPERATION_TYPE::SCH, OPTION1::NONE, OPTION2::F, OPTION3::NONE, "name", "CHO", "", "" }));
	EXPECT_EQ(0, result3.size());

	delete pSearcher;
}

TEST(ClSearchTest, NoOptionTest) {
	map<string, EmployeeInfo> dataBase;
	dataBase["2018051224"] = EmployeeInfo({ "18051224", "YEONGCHUL CHO", "CL2" , "010-4198-8858", "19930116", "PRO" });
	dataBase["2017256132"] = EmployeeInfo({ "17256132", "JUNHYUCK SHIN", "CL2" , "010-2135-1546", "19910526", "EX" });
	dataBase["2020031242"] = EmployeeInfo({ "20031242", "JUNGHOON KONG", "CL2" , "010-4756-9871", "19930821", "PRO" });
	dataBase["2014321152"] = EmployeeInfo({ "14321152", "INSOO KIM", "CL2" , "010-1312-4356", "19910415", "ADV" });
	dataBase["2012035123"] = EmployeeInfo({ "12035123", "JONGWON KIM", "CL3" , "010-6855-9852", "19850720", "PRO" });
	dataBase["2008051231"] = EmployeeInfo({ "08051231", "SINHO OH", "CL4" , "010-5563-8744", "19800420", "PRO" });

	Searcher* pSearcher = new ClSearcher(&dataBase);

	map<string, EmployeeInfo> result1 = pSearcher->search(ParserResult({ OPERATION_TYPE::SCH, OPTION1::NONE, OPTION2::L, OPTION3::NONE, "cl", "CL2", "", "" }));
	EXPECT_EQ(4, result1.size());
	EXPECT_EQ(1, result1.count("2018051224"));
	EXPECT_EQ(1, result1.count("2017256132"));
	EXPECT_EQ(1, result1.count("2020031242"));
	EXPECT_EQ(1, result1.count("2014321152"));
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "18051224", "YEONGCHUL CHO", "CL2" , "010-4198-8858", "19930116", "PRO" }), result1["2018051224"]));
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "17256132", "JUNHYUCK SHIN", "CL2" , "010-2135-1546", "19910526", "EX" }), result1["2017256132"]));
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "20031242", "JUNGHOON KONG", "CL2" , "010-4756-9871", "19930821", "PRO" }), result1["2020031242"]));
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "14321152", "INSOO KIM", "CL2" , "010-1312-4356", "19910415", "ADV" }), result1["2014321152"]));

	map<string, EmployeeInfo> result2 = pSearcher->search(ParserResult({ OPERATION_TYPE::SCH, OPTION1::NONE, OPTION2::L, OPTION3::NONE, "cl", "CL3", "", "" }));
	EXPECT_EQ(1, result2.size());
	EXPECT_EQ(1, result2.count("2012035123"));
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "12035123", "JONGWON KIM", "CL3" , "010-6855-9852", "19850720", "PRO" }), result2["2012035123"]));

	map<string, EmployeeInfo> result3 = pSearcher->search(ParserResult({ OPERATION_TYPE::SCH, OPTION1::NONE, OPTION2::L, OPTION3::NONE, "cl", "CL4", "", "" }));
	EXPECT_EQ(1, result3.size());
	EXPECT_EQ(1, result3.count("2008051231"));
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "08051231", "SINHO OH", "CL4" , "010-5563-8744", "19800420", "PRO" }), result3["2008051231"]));

	delete pSearcher;
}

TEST(PhoneNumberSearchTest, NoOptionTest) {
	map<string, EmployeeInfo> dataBase;
	dataBase["2018051224"] = EmployeeInfo({ "18051224", "YEONGCHUL CHO", "CL2" , "010-4198-8858", "19930116", "PRO" });
	dataBase["2017256132"] = EmployeeInfo({ "17256132", "JUNHYUCK SHIN", "CL2" , "010-2135-1546", "19910526", "EX" });
	dataBase["2020031242"] = EmployeeInfo({ "20031242", "JUNGHOON KONG", "CL2" , "010-4756-9871", "19930821", "PRO" });
	dataBase["2014321152"] = EmployeeInfo({ "14321152", "INSOO KIM", "CL2" , "010-1312-4356", "19910415", "ADV" });
	dataBase["2012035123"] = EmployeeInfo({ "12035123", "JONGWON KIM", "CL3" , "010-6855-9852", "19850720", "PRO" });
	dataBase["2008051231"] = EmployeeInfo({ "08051231", "SINHO OH", "CL4" , "010-5563-8744", "19800420", "PRO" });

	Searcher* pSearcher = new PhoneNumberSearcher(&dataBase);

	map<string, EmployeeInfo> result1 = pSearcher->search(ParserResult({ OPERATION_TYPE::SCH, OPTION1::NONE, OPTION2::NONE, OPTION3::NONE, "phoneNum", "010-6855-9852", "", "" }));
	EXPECT_EQ(1, result1.size());
	EXPECT_EQ(1, result1.count("2012035123"));
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "12035123", "JONGWON KIM", "CL3" , "010-6855-9852", "19850720", "PRO" }), result1["2012035123"]));

	map<string, EmployeeInfo> result2 = pSearcher->search(ParserResult({ OPERATION_TYPE::SCH, OPTION1::NONE, OPTION2::NONE, OPTION3::NONE, "phoneNum", "010-2135-1546", "", "" }));
	EXPECT_EQ(1, result2.size());
	EXPECT_EQ(1, result2.count("2017256132"));
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "17256132", "JUNHYUCK SHIN", "CL2" , "010-2135-1546", "19910526", "EX" }), result2["2017256132"]));

	delete pSearcher;
}

TEST(PhoneNumberSearchTest, OptionTest) {
	map<string, EmployeeInfo> dataBase;
	dataBase["2018051224"] = EmployeeInfo({ "18051224", "YEONGCHUL CHO", "CL2" , "010-4198-8858", "19930116", "PRO" });
	dataBase["2017256132"] = EmployeeInfo({ "17256132", "JUNHYUCK SHIN", "CL2" , "010-2135-1546", "19910526", "EX" });
	dataBase["2020031242"] = EmployeeInfo({ "20031242", "JUNGHOON KONG", "CL2" , "010-4756-9871", "19930821", "PRO" });
	dataBase["2014321152"] = EmployeeInfo({ "14321152", "INSOO KIM", "CL2" , "010-1312-4356", "19910415", "ADV" });
	dataBase["2012035123"] = EmployeeInfo({ "12035123", "JONGWON KIM", "CL3" , "010-6855-9852", "19850720", "PRO" });
	dataBase["2008051231"] = EmployeeInfo({ "08051231", "SINHO OH", "CL4" , "010-5563-8744", "19800420", "PRO" });

	Searcher* pSearcher = new PhoneNumberSearcher(&dataBase);

	map<string, EmployeeInfo> result1 = pSearcher->search(ParserResult({ OPERATION_TYPE::SCH, OPTION1::NONE, OPTION2::M, OPTION3::NONE, "phoneNum", "4756", "", "" }));
	EXPECT_EQ(1, result1.size());
	EXPECT_EQ(1, result1.count("2020031242"));
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "20031242", "JUNGHOON KONG", "CL2" , "010-4756-9871", "19930821", "PRO" }), result1["2020031242"]));

	map<string, EmployeeInfo> result2 = pSearcher->search(ParserResult({ OPERATION_TYPE::SCH, OPTION1::NONE, OPTION2::L, OPTION3::NONE, "phoneNum", "9852", "", "" }));
	EXPECT_EQ(1, result2.size());
	EXPECT_EQ(1, result2.count("2012035123"));
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "12035123", "JONGWON KIM", "CL3" , "010-6855-9852", "19850720", "PRO" }), result2["2012035123"]));

	delete pSearcher;
}

TEST(BirthdaySearchTest, NoOptionTest) {
	map<string, EmployeeInfo> dataBase;
	dataBase["2018051224"] = EmployeeInfo({ "18051224", "YEONGCHUL CHO", "CL2" , "010-4198-8858", "19930116", "PRO" });
	dataBase["2017256132"] = EmployeeInfo({ "17256132", "JUNHYUCK SHIN", "CL2" , "010-2135-1546", "19910526", "EX" });
	dataBase["2020031242"] = EmployeeInfo({ "20031242", "JUNGHOON KONG", "CL2" , "010-4756-9871", "19930821", "PRO" });
	dataBase["2014321152"] = EmployeeInfo({ "14321152", "INSOO KIM", "CL2" , "010-1312-4356", "19910415", "ADV" });
	dataBase["2012035123"] = EmployeeInfo({ "12035123", "JONGWON KIM", "CL3" , "010-6855-9852", "19850720", "PRO" });
	dataBase["2008051231"] = EmployeeInfo({ "08051231", "SINHO OH", "CL4" , "010-5563-8744", "19800420", "PRO" });

	Searcher* pSearcher = new BirthdaySearcher(&dataBase);

	map<string, EmployeeInfo> result1 = pSearcher->search(ParserResult({ OPERATION_TYPE::SCH, OPTION1::NONE, OPTION2::NONE, OPTION3::NONE, "birthday", "19910415", "", "" }));
	EXPECT_EQ(1, result1.size());
	EXPECT_EQ(1, result1.count("2014321152"));
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "14321152", "INSOO KIM", "CL2" , "010-1312-4356", "19910415", "ADV" }), result1["2014321152"]));

	map<string, EmployeeInfo> result2 = pSearcher->search(ParserResult({ OPERATION_TYPE::SCH, OPTION1::NONE, OPTION2::NONE, OPTION3::NONE, "birthday", "19930821", "", "" }));
	EXPECT_EQ(1, result2.size());
	EXPECT_EQ(1, result2.count("2020031242"));
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "20031242", "JUNGHOON KONG", "CL2" , "010-4756-9871", "19930821", "PRO" }), result2["2020031242"]));

	delete pSearcher;
}

TEST(BirthdaySearchTest, OptionTest) {
	map<string, EmployeeInfo> dataBase;
	dataBase["2018051224"] = EmployeeInfo({ "18051224", "YEONGCHUL CHO", "CL2" , "010-4198-8858", "19930116", "PRO" });
	dataBase["2017256132"] = EmployeeInfo({ "17256132", "JUNHYUCK SHIN", "CL2" , "010-2135-1546", "19910526", "EX" });
	dataBase["2020031242"] = EmployeeInfo({ "20031242", "JUNGHOON KONG", "CL2" , "010-4756-9871", "19930821", "PRO" });
	dataBase["2014321152"] = EmployeeInfo({ "14321152", "INSOO KIM", "CL2" , "010-1312-4356", "19910415", "ADV" });
	dataBase["2012035123"] = EmployeeInfo({ "12035123", "JONGWON KIM", "CL3" , "010-6855-9852", "19850720", "PRO" });
	dataBase["2008051231"] = EmployeeInfo({ "08051231", "SINHO OH", "CL4" , "010-5563-8744", "19800420", "PRO" });

	Searcher* pSearcher = new BirthdaySearcher(&dataBase);

	map<string, EmployeeInfo> result1 = pSearcher->search(ParserResult({ OPERATION_TYPE::SCH, OPTION1::NONE, OPTION2::Y, OPTION3::NONE, "birthday", "1991", "", "" }));
	EXPECT_EQ(2, result1.size());
	EXPECT_EQ(1, result1.count("2017256132"));
	EXPECT_EQ(1, result1.count("2014321152"));
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "17256132", "JUNHYUCK SHIN", "CL2" , "010-2135-1546", "19910526", "EX" }), result1["2017256132"]));
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "14321152", "INSOO KIM", "CL2" , "010-1312-4356", "19910415", "ADV" }), result1["2014321152"]));

	map<string, EmployeeInfo> result2 = pSearcher->search(ParserResult({ OPERATION_TYPE::SCH, OPTION1::NONE, OPTION2::M, OPTION3::NONE, "birthday", "01", "", "" }));
	EXPECT_EQ(1, result2.size());
	EXPECT_EQ(1, result2.count("2018051224"));
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "18051224", "YEONGCHUL CHO", "CL2" , "010-4198-8858", "19930116", "PRO" }), result2["2018051224"]));

	map<string, EmployeeInfo> result3 = pSearcher->search(ParserResult({ OPERATION_TYPE::SCH, OPTION1::NONE, OPTION2::D, OPTION3::NONE, "birthday", "20", "", "" }));
	EXPECT_EQ(2, result3.size());
	EXPECT_EQ(1, result3.count("2012035123"));
	EXPECT_EQ(1, result3.count("2008051231"));
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "12035123", "JONGWON KIM", "CL3" , "010-6855-9852", "19850720", "PRO" }), result3["2012035123"]));
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "08051231", "SINHO OH", "CL4" , "010-5563-8744", "19800420", "PRO" }), result3["2008051231"]));

	delete pSearcher;
}

TEST(CertiSearchTest, NoOptionTest) {
	map<string, EmployeeInfo> dataBase;
	dataBase["2018051224"] = EmployeeInfo({ "18051224", "YEONGCHUL CHO", "CL2" , "010-4198-8858", "19930116", "PRO" });
	dataBase["2017256132"] = EmployeeInfo({ "17256132", "JUNHYUCK SHIN", "CL2" , "010-2135-1546", "19910526", "EX" });
	dataBase["2020031242"] = EmployeeInfo({ "20031242", "JUNGHOON KONG", "CL2" , "010-4756-9871", "19930821", "PRO" });
	dataBase["2014321152"] = EmployeeInfo({ "14321152", "INSOO KIM", "CL2" , "010-1312-4356", "19910415", "ADV" });
	dataBase["2012035123"] = EmployeeInfo({ "12035123", "JONGWON KIM", "CL3" , "010-6855-9852", "19850720", "PRO" });
	dataBase["2008051231"] = EmployeeInfo({ "08051231", "SINHO OH", "CL4" , "010-5563-8744", "19800420", "PRO" });

	Searcher* pSearcher = new CertiSearcher(&dataBase);

	map<string, EmployeeInfo> result1 = pSearcher->search(ParserResult({ OPERATION_TYPE::SCH, OPTION1::NONE, OPTION2::Y, OPTION3::NONE, "certi", "PRO", "", "" }));
	EXPECT_EQ(4, result1.size());
	EXPECT_EQ(1, result1.count("2018051224"));
	EXPECT_EQ(1, result1.count("2020031242"));
	EXPECT_EQ(1, result1.count("2012035123"));
	EXPECT_EQ(1, result1.count("2008051231"));
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "18051224", "YEONGCHUL CHO", "CL2" , "010-4198-8858", "19930116", "PRO" }), result1["2018051224"]));
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "20031242", "JUNGHOON KONG", "CL2" , "010-4756-9871", "19930821", "PRO" }), result1["2020031242"]));
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "12035123", "JONGWON KIM", "CL3" , "010-6855-9852", "19850720", "PRO" }), result1["2012035123"]));
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "08051231", "SINHO OH", "CL4" , "010-5563-8744", "19800420", "PRO" }), result1["2008051231"]));

	delete pSearcher;
}

TEST(FactorySearcherTest, NoOptionTest) {
	map<string, EmployeeInfo> dataBase;
	dataBase["2018051224"] = EmployeeInfo({ "18051224", "YEONGCHUL CHO", "CL2" , "010-4198-8858", "19930116", "PRO" });
	dataBase["2017256132"] = EmployeeInfo({ "17256132", "JUNHYUCK SHIN", "CL2" , "010-2135-1546", "19910526", "EX" });
	dataBase["2020031242"] = EmployeeInfo({ "20031242", "JUNGHOON KONG", "CL2" , "010-4756-9871", "19930821", "PRO" });
	dataBase["2014321152"] = EmployeeInfo({ "14321152", "INSOO KIM", "CL2" , "010-1312-4356", "19910415", "ADV" });
	dataBase["2012035123"] = EmployeeInfo({ "12035123", "JONGWON KIM", "CL3" , "010-6855-9852", "19850720", "PRO" });
	dataBase["2008051231"] = EmployeeInfo({ "08051231", "SINHO OH", "CL4" , "010-5563-8744", "19800420", "PRO" });

	IFactorySearcher* pFactorySearcher = new FactorySearcher(&dataBase);
	Searcher* pSearcher = pFactorySearcher->getSearcher(ParserResult({ OPERATION_TYPE::SCH, OPTION1::NONE, OPTION2::Y, OPTION3::NONE, "certi", "PRO", "", "" }));
	map<string, EmployeeInfo> result1 = pSearcher->search(ParserResult({ OPERATION_TYPE::SCH, OPTION1::NONE, OPTION2::Y, OPTION3::NONE, "certi", "PRO", "", "" }));
	EXPECT_EQ(4, result1.size());
	EXPECT_EQ(1, result1.count("2018051224"));
	EXPECT_EQ(1, result1.count("2020031242"));
	EXPECT_EQ(1, result1.count("2012035123"));
	EXPECT_EQ(1, result1.count("2008051231"));
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "18051224", "YEONGCHUL CHO", "CL2" , "010-4198-8858", "19930116", "PRO" }), result1["2018051224"]));
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "20031242", "JUNGHOON KONG", "CL2" , "010-4756-9871", "19930821", "PRO" }), result1["2020031242"]));
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "12035123", "JONGWON KIM", "CL3" , "010-6855-9852", "19850720", "PRO" }), result1["2012035123"]));
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "08051231", "SINHO OH", "CL4" , "010-5563-8744", "19800420", "PRO" }), result1["2008051231"]));

	pSearcher = pFactorySearcher->getSearcher(ParserResult({ OPERATION_TYPE::SCH, OPTION1::NONE, OPTION2::NONE, OPTION3::NONE, "employeeNum", "20031242", "", "" }));
	map<string, EmployeeInfo> result2 = pSearcher->search(ParserResult({ OPERATION_TYPE::SCH, OPTION1::NONE, OPTION2::NONE, OPTION3::NONE, "employeeNum", "20031242", "", "" }));
	EXPECT_EQ(1, result2.size());
	EXPECT_EQ(1, result2.count("2020031242"));
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "20031242", "JUNGHOON KONG", "CL2" , "010-4756-9871", "19930821", "PRO" }), result2["2020031242"]));

	pSearcher = pFactorySearcher->getSearcher(ParserResult({ OPERATION_TYPE::SCH, OPTION1::NONE, OPTION2::NONE, OPTION3::NONE, "phoneNum", "010-6855-9852", "", "" }));
	map<string, EmployeeInfo> result4 = pSearcher->search(ParserResult({ OPERATION_TYPE::SCH, OPTION1::NONE, OPTION2::NONE, OPTION3::NONE, "phoneNum", "010-6855-9852", "", "" }));
	EXPECT_EQ(1, result4.size());
	EXPECT_EQ(1, result4.count("2012035123"));
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "12035123", "JONGWON KIM", "CL3" , "010-6855-9852", "19850720", "PRO" }), result4["2012035123"]));

	pSearcher = pFactorySearcher->getSearcher(ParserResult({ OPERATION_TYPE::SCH, OPTION1::NONE, OPTION2::NONE, OPTION3::NONE, "birthday", "19910415", "", "" }));
	map<string, EmployeeInfo> result5 = pSearcher->search(ParserResult({ OPERATION_TYPE::SCH, OPTION1::NONE, OPTION2::NONE, OPTION3::NONE, "birthday", "19910415", "", "" }));
	EXPECT_EQ(1, result5.size());
	EXPECT_EQ(1, result5.count("2014321152"));
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "14321152", "INSOO KIM", "CL2" , "010-1312-4356", "19910415", "ADV" }), result5["2014321152"]));

	delete pFactorySearcher;
}