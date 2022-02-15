#pragma once
#include <iostream>
#include <vector>
#include "Define.h"

using namespace std;

extern vector<EmployeeInfo> g_DB;

class Searcher {
public:
	virtual vector<EmployeeInfo> search(const ParserResult& parserResult) = 0;
};

class EmployeeNumSearcher : public Searcher {
public:
	virtual vector<EmployeeInfo> search(const ParserResult& parserResult) override;
};

class NameSearcher : public Searcher {
public:
	string getNameByOption(string name, OPTION2 option);
	virtual vector<EmployeeInfo> search(const ParserResult& parserResult) override;
};

class ClSearcher : public Searcher {
public:
	virtual vector<EmployeeInfo> search(const ParserResult& parserResult) override;
};

class PhoneNumberSearcher : public Searcher {
public:
	string getNumberByOption(string phoneNumber, OPTION2 numberOption);
	virtual vector<EmployeeInfo> search(const ParserResult& parserResult) override { return vector<EmployeeInfo>(); };
};

class BirthdaySearcher : public Searcher {
public:
	string getBirthDayByOption(string birthDay, OPTION2 birthOption);
	virtual vector<EmployeeInfo> search(const ParserResult& parserResult) override { return vector<EmployeeInfo>(); };
};

class CertiSearcher : public Searcher {
public:
	virtual vector<EmployeeInfo> search(const ParserResult& parserResult) override { return vector<EmployeeInfo>(); };
};