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
	g_DB.emplace_back(EmployeeInfo({ "18051224", "Á¶ ¿µÃ¶", "CL2" , "010-4198-8858", "19930116", "PRO" }));
	g_DB.emplace_back(EmployeeInfo({ "17256132", "½Å ÁØÇõ", "CL2" , "010-2135-1546", "19910526", "EX" }));
	g_DB.emplace_back(EmployeeInfo({ "20031242", "°ø Á¤ÈÆ", "CL2" , "010-4756-9871", "19930821", "PRO" }));
	g_DB.emplace_back(EmployeeInfo({ "14321152", "±è ÀÎ¼ö", "CL2" , "010-1312-4356", "19910415", "ADV" }));
	g_DB.emplace_back(EmployeeInfo({ "12035123", "±è Á¾¿ø", "CL3" , "010-6855-9852", "19850720", "PRO" }));
	g_DB.emplace_back(EmployeeInfo({ "08051231", "¿À ½ÅÈ£", "CL4" , "010-5563-8744", "19800420", "PRO" }));

	Searcher* pSearcher = new EmployeeNumSearcher();
}

TEST(NameSearchTest, NoOptionTest) {
	g_DB.clear();
	g_DB.emplace_back(EmployeeInfo({ "18051224", "Á¶ ¿µÃ¶", "CL2" , "010-4198-8858", "19930116", "PRO" }));
	g_DB.emplace_back(EmployeeInfo({ "17256132", "½Å ÁØÇõ", "CL2" , "010-2135-1546", "19910526", "EX" }));
	g_DB.emplace_back(EmployeeInfo({ "20031242", "°ø Á¤ÈÆ", "CL2" , "010-4756-9871", "19930821", "PRO" }));
	g_DB.emplace_back(EmployeeInfo({ "14321152", "±è ÀÎ¼ö", "CL2" , "010-1312-4356", "19910415", "ADV" }));
	g_DB.emplace_back(EmployeeInfo({ "12035123", "±è Á¾¿ø", "CL3" , "010-6855-9852", "19850720", "PRO" }));
	g_DB.emplace_back(EmployeeInfo({ "08051231", "¿À ½ÅÈ£", "CL4" , "010-5563-8744", "19800420", "PRO" }));

	Searcher* pSearcher = new NameSearcher();
}

TEST(ClSearchTest, NoOptionTest) {
	g_DB.clear();
	g_DB.emplace_back(EmployeeInfo({ "18051224", "Á¶ ¿µÃ¶", "CL2" , "010-4198-8858", "19930116", "PRO" }));
	g_DB.emplace_back(EmployeeInfo({ "17256132", "½Å ÁØÇõ", "CL2" , "010-2135-1546", "19910526", "EX" }));
	g_DB.emplace_back(EmployeeInfo({ "20031242", "°ø Á¤ÈÆ", "CL2" , "010-4756-9871", "19930821", "PRO" }));
	g_DB.emplace_back(EmployeeInfo({ "14321152", "±è ÀÎ¼ö", "CL2" , "010-1312-4356", "19910415", "ADV" }));
	g_DB.emplace_back(EmployeeInfo({ "12035123", "±è Á¾¿ø", "CL3" , "010-6855-9852", "19850720", "PRO" }));
	g_DB.emplace_back(EmployeeInfo({ "08051231", "¿À ½ÅÈ£", "CL4" , "010-5563-8744", "19800420", "PRO" }));

	Searcher* pSearcher = new ClSearcher();
}

TEST(PhoneNumberSearchTest, NoOptionTest) {
	g_DB.clear();
	g_DB.emplace_back(EmployeeInfo({ "18051224", "Á¶ ¿µÃ¶", "CL2" , "010-4198-8858", "19930116", "PRO" }));
	g_DB.emplace_back(EmployeeInfo({ "17256132", "½Å ÁØÇõ", "CL2" , "010-2135-1546", "19910526", "EX" }));
	g_DB.emplace_back(EmployeeInfo({ "20031242", "°ø Á¤ÈÆ", "CL2" , "010-4756-9871", "19930821", "PRO" }));
	g_DB.emplace_back(EmployeeInfo({ "14321152", "±è ÀÎ¼ö", "CL2" , "010-1312-4356", "19910415", "ADV" }));
	g_DB.emplace_back(EmployeeInfo({ "12035123", "±è Á¾¿ø", "CL3" , "010-6855-9852", "19850720", "PRO" }));
	g_DB.emplace_back(EmployeeInfo({ "08051231", "¿À ½ÅÈ£", "CL4" , "010-5563-8744", "19800420", "PRO" }));

	Searcher* pSearcher = new PhoneNumberSearcher();
}

TEST(BirthdaySearchTest, NoOptionTest) {
	g_DB.clear();
	g_DB.emplace_back(EmployeeInfo({ "18051224", "Á¶ ¿µÃ¶", "CL2" , "010-4198-8858", "19930116", "PRO" }));
	g_DB.emplace_back(EmployeeInfo({ "17256132", "½Å ÁØÇõ", "CL2" , "010-2135-1546", "19910526", "EX" }));
	g_DB.emplace_back(EmployeeInfo({ "20031242", "°ø Á¤ÈÆ", "CL2" , "010-4756-9871", "19930821", "PRO" }));
	g_DB.emplace_back(EmployeeInfo({ "14321152", "±è ÀÎ¼ö", "CL2" , "010-1312-4356", "19910415", "ADV" }));
	g_DB.emplace_back(EmployeeInfo({ "12035123", "±è Á¾¿ø", "CL3" , "010-6855-9852", "19850720", "PRO" }));
	g_DB.emplace_back(EmployeeInfo({ "08051231", "¿À ½ÅÈ£", "CL4" , "010-5563-8744", "19800420", "PRO" }));

	Searcher* pSearcher = new BirthdaySearcher();
}

TEST(CertiSearchTest, NoOptionTest) {
	g_DB.clear();
	g_DB.emplace_back(EmployeeInfo({ "18051224", "Á¶ ¿µÃ¶", "CL2" , "010-4198-8858", "19930116", "PRO" }));
	g_DB.emplace_back(EmployeeInfo({ "17256132", "½Å ÁØÇõ", "CL2" , "010-2135-1546", "19910526", "EX" }));
	g_DB.emplace_back(EmployeeInfo({ "20031242", "°ø Á¤ÈÆ", "CL2" , "010-4756-9871", "19930821", "PRO" }));
	g_DB.emplace_back(EmployeeInfo({ "14321152", "±è ÀÎ¼ö", "CL2" , "010-1312-4356", "19910415", "ADV" }));
	g_DB.emplace_back(EmployeeInfo({ "12035123", "±è Á¾¿ø", "CL3" , "010-6855-9852", "19850720", "PRO" }));
	g_DB.emplace_back(EmployeeInfo({ "08051231", "¿À ½ÅÈ£", "CL4" , "010-5563-8744", "19800420", "PRO" }));

	Searcher* pSearcher = new CertiSearcher();
}