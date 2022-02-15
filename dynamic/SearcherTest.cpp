#include "gtest/gtest.h"
#include "Searcher.h"

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
	g_DB.clear();
	g_DB.emplace_back(EmployeeInfo({ "18051224", "CHO YEONGCHUL", "CL2" , "010-4198-8858", "19930116", "PRO" }));
	g_DB.emplace_back(EmployeeInfo({ "17256132", "SHIN JUNHYUCK", "CL2" , "010-2135-1546", "19910526", "EX" }));
	g_DB.emplace_back(EmployeeInfo({ "20031242", "KONG JUNGHOON", "CL2" , "010-4756-9871", "19930821", "PRO" }));
	g_DB.emplace_back(EmployeeInfo({ "14321152", "KIM INSOO", "CL2" , "010-1312-4356", "19910415", "ADV" }));
	g_DB.emplace_back(EmployeeInfo({ "12035123", "KIM JONGWON", "CL3" , "010-6855-9852", "19850720", "PRO" }));
	g_DB.emplace_back(EmployeeInfo({ "08051231", "OH SINHO", "CL4" , "010-5563-8744", "19800420", "PRO" }));

	Searcher* pSearcher = new EmployeeNumSearcher();

	vector<EmployeeInfo> result1 = pSearcher->search(ParserResult({ OPERATION_TYPE::SCH, OPTION1::NONE, OPTION2::NONE, OPTION3::NONE, "employeeNum", "18051224", "", "" }));
	EXPECT_EQ(1, result1.size());
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "18051224", "CHO YEONGCHUL", "CL2" , "010-4198-8858", "19930116", "PRO" }), result1[0]));

	vector<EmployeeInfo> result2 = pSearcher->search(ParserResult({ OPERATION_TYPE::SCH, OPTION1::NONE, OPTION2::NONE, OPTION3::NONE, "employeeNum", "17256132", "", "" }));
	EXPECT_EQ(1, result2.size());
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "17256132", "SHIN JUNHYUCK", "CL2" , "010-2135-1546", "19910526", "EX" }), result2[0]));
	EXPECT_FALSE(compareEmployeeInfo(EmployeeInfo({ "20031242", "KONG JUNGHOON", "CL2" , "010-4756-9871", "19930821", "PRO" }), result2[0]));

	vector<EmployeeInfo> result3 = pSearcher->search(ParserResult({ OPERATION_TYPE::SCH, OPTION1::NONE, OPTION2::NONE, OPTION3::NONE, "employeeNum", "08051231", "", "" }));
	EXPECT_EQ(1, result3.size());
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "08051231", "OH SINHO", "CL4" , "010-5563-8744", "19800420", "PRO" }), result3[0]));
}

TEST(NameSearchTest, NoOptionTest) {
	g_DB.clear();
	g_DB.emplace_back(EmployeeInfo({ "18051224", "CHO YEONGCHUL", "CL2" , "010-4198-8858", "19930116", "PRO" }));
	g_DB.emplace_back(EmployeeInfo({ "17256132", "SHIN JUNHYUCK", "CL2" , "010-2135-1546", "19910526", "EX" }));
	g_DB.emplace_back(EmployeeInfo({ "20031242", "KONG JUNGHOON", "CL2" , "010-4756-9871", "19930821", "PRO" }));
	g_DB.emplace_back(EmployeeInfo({ "14321152", "KIM INSOO", "CL2" , "010-1312-4356", "19910415", "ADV" }));
	g_DB.emplace_back(EmployeeInfo({ "12035123", "KIM JONGWON", "CL3" , "010-6855-9852", "19850720", "PRO" }));
	g_DB.emplace_back(EmployeeInfo({ "08051231", "OH SINHO", "CL4" , "010-5563-8744", "19800420", "PRO" }));

	Searcher* pSearcher = new NameSearcher();

	vector<EmployeeInfo> result1 = pSearcher->search(ParserResult({ OPERATION_TYPE::SCH, OPTION1::NONE, OPTION2::NONE, OPTION3::NONE, "name", "SHIN JUNHYUCK", "", "" }));
	EXPECT_EQ(1, result1.size());
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "17256132", "SHIN JUNHYUCK", "CL2" , "010-2135-1546", "19910526", "EX" }), result1[0]));

	vector<EmployeeInfo> result2 = pSearcher->search(ParserResult({ OPERATION_TYPE::SCH, OPTION1::NONE, OPTION2::NONE, OPTION3::NONE, "name", "KIM INSU", "", "" }));
	EXPECT_EQ(0, result2.size());
}

TEST(NameSearchTest, OptionTest) {
	g_DB.clear();
	g_DB.emplace_back(EmployeeInfo({ "18051224", "CHO YEONGCHUL", "CL2" , "010-4198-8858", "19930116", "PRO" }));
	g_DB.emplace_back(EmployeeInfo({ "17256132", "SHIN JUNHYUCK", "CL2" , "010-2135-1546", "19910526", "EX" }));
	g_DB.emplace_back(EmployeeInfo({ "20031242", "KONG JUNGHOON", "CL2" , "010-4756-9871", "19930821", "PRO" }));
	g_DB.emplace_back(EmployeeInfo({ "14321152", "KIM INSOO", "CL2" , "010-1312-4356", "19910415", "ADV" }));
	g_DB.emplace_back(EmployeeInfo({ "12035123", "KIM JONGWON", "CL3" , "010-6855-9852", "19850720", "PRO" }));
	g_DB.emplace_back(EmployeeInfo({ "08051231", "OH SINHO", "CL4" , "010-5563-8744", "19800420", "PRO" }));

	Searcher* pSearcher = new NameSearcher();

	vector<EmployeeInfo> result1 = pSearcher->search(ParserResult({ OPERATION_TYPE::SCH, OPTION1::NONE, OPTION2::F, OPTION3::NONE, "name", "YEONGCHUL", "", "" }));
	EXPECT_EQ(1, result1.size());
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "18051224", "CHO YEONGCHUL", "CL2" , "010-4198-8858", "19930116", "PRO" }), result1[0]));

	vector<EmployeeInfo> result2 = pSearcher->search(ParserResult({ OPERATION_TYPE::SCH, OPTION1::NONE, OPTION2::L, OPTION3::NONE, "name", "KIM", "", "" }));
	EXPECT_EQ(2, result2.size());
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "14321152", "KIM INSOO", "CL2" , "010-1312-4356", "19910415", "ADV" }), result2[0]));
	EXPECT_TRUE(compareEmployeeInfo(EmployeeInfo({ "12035123", "KIM JONGWON", "CL3" , "010-6855-9852", "19850720", "PRO" }), result2[1]));

	vector<EmployeeInfo> result3 = pSearcher->search(ParserResult({ OPERATION_TYPE::SCH, OPTION1::NONE, OPTION2::F, OPTION3::NONE, "name", "CHO", "", "" }));
	EXPECT_EQ(0, result3.size());
}

TEST(ClSearchTest, NoOptionTest) {
	g_DB.clear();
	g_DB.emplace_back(EmployeeInfo({ "18051224", "CHO YEONGCHUL", "CL2" , "010-4198-8858", "19930116", "PRO" }));
	g_DB.emplace_back(EmployeeInfo({ "17256132", "SHIN JUNHYUCK", "CL2" , "010-2135-1546", "19910526", "EX" }));
	g_DB.emplace_back(EmployeeInfo({ "20031242", "KONG JUNGHOON", "CL2" , "010-4756-9871", "19930821", "PRO" }));
	g_DB.emplace_back(EmployeeInfo({ "14321152", "KIM INSOO", "CL2" , "010-1312-4356", "19910415", "ADV" }));
	g_DB.emplace_back(EmployeeInfo({ "12035123", "KIM JONGWON", "CL3" , "010-6855-9852", "19850720", "PRO" }));
	g_DB.emplace_back(EmployeeInfo({ "08051231", "OH SINHO", "CL4" , "010-5563-8744", "19800420", "PRO" }));

	Searcher* pSearcher = new ClSearcher();
}

TEST(PhoneNumberSearchTest, NoOptionTest) {
	g_DB.clear();
	g_DB.emplace_back(EmployeeInfo({ "18051224", "CHO YEONGCHUL", "CL2" , "010-4198-8858", "19930116", "PRO" }));
	g_DB.emplace_back(EmployeeInfo({ "17256132", "SHIN JUNHYUCK", "CL2" , "010-2135-1546", "19910526", "EX" }));
	g_DB.emplace_back(EmployeeInfo({ "20031242", "KONG JUNGHOON", "CL2" , "010-4756-9871", "19930821", "PRO" }));
	g_DB.emplace_back(EmployeeInfo({ "14321152", "KIM INSOO", "CL2" , "010-1312-4356", "19910415", "ADV" }));
	g_DB.emplace_back(EmployeeInfo({ "12035123", "KIM JONGWON", "CL3" , "010-6855-9852", "19850720", "PRO" }));
	g_DB.emplace_back(EmployeeInfo({ "08051231", "OH SINHO", "CL4" , "010-5563-8744", "19800420", "PRO" }));

	Searcher* pSearcher = new PhoneNumberSearcher();
}

TEST(BirthdaySearchTest, NoOptionTest) {
	g_DB.clear();
	g_DB.emplace_back(EmployeeInfo({ "18051224", "CHO YEONGCHUL", "CL2" , "010-4198-8858", "19930116", "PRO" }));
	g_DB.emplace_back(EmployeeInfo({ "17256132", "SHIN JUNHYUCK", "CL2" , "010-2135-1546", "19910526", "EX" }));
	g_DB.emplace_back(EmployeeInfo({ "20031242", "KONG JUNGHOON", "CL2" , "010-4756-9871", "19930821", "PRO" }));
	g_DB.emplace_back(EmployeeInfo({ "14321152", "KIM INSOO", "CL2" , "010-1312-4356", "19910415", "ADV" }));
	g_DB.emplace_back(EmployeeInfo({ "12035123", "KIM JONGWON", "CL3" , "010-6855-9852", "19850720", "PRO" }));
	g_DB.emplace_back(EmployeeInfo({ "08051231", "OH SINHO", "CL4" , "010-5563-8744", "19800420", "PRO" }));

	Searcher* pSearcher = new BirthdaySearcher();
}

TEST(CertiSearchTest, NoOptionTest) {
	g_DB.clear();
	g_DB.emplace_back(EmployeeInfo({ "18051224", "CHO YEONGCHUL", "CL2" , "010-4198-8858", "19930116", "PRO" }));
	g_DB.emplace_back(EmployeeInfo({ "17256132", "SHIN JUNHYUCK", "CL2" , "010-2135-1546", "19910526", "EX" }));
	g_DB.emplace_back(EmployeeInfo({ "20031242", "KONG JUNGHOON", "CL2" , "010-4756-9871", "19930821", "PRO" }));
	g_DB.emplace_back(EmployeeInfo({ "14321152", "KIM INSOO", "CL2" , "010-1312-4356", "19910415", "ADV" }));
	g_DB.emplace_back(EmployeeInfo({ "12035123", "KIM JONGWON", "CL3" , "010-6855-9852", "19850720", "PRO" }));
	g_DB.emplace_back(EmployeeInfo({ "08051231", "OH SINHO", "CL4" , "010-5563-8744", "19800420", "PRO" }));

	Searcher* pSearcher = new CertiSearcher();
}