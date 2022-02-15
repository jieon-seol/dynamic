#pragma once
#include <iostream>
#include <vector>
#include "Define.h"

using namespace std;

class Searcher {
public:
	Searcher(vector<EmployeeInfo>* pDb) : pDb_(pDb) {}
	virtual vector<EmployeeInfo> search(const ParserResult& parserResult) = 0;
protected:
	vector<EmployeeInfo>* pDb_;
};

class EmployeeNumSearcher : public Searcher {
public:
	EmployeeNumSearcher(vector<EmployeeInfo>* pDb) : Searcher(pDb) {}
	virtual vector<EmployeeInfo> search(const ParserResult& parserResult) override;
};

class NameSearcher : public Searcher {
public:
	NameSearcher(vector<EmployeeInfo>* pDb) : Searcher(pDb) {}
	string getNameByOption(const string& name, const OPTION2 option);
	virtual vector<EmployeeInfo> search(const ParserResult& parserResult) override;
};

class ClSearcher : public Searcher {
public:
	ClSearcher(vector<EmployeeInfo>* pDb) : Searcher(pDb) {}
	virtual vector<EmployeeInfo> search(const ParserResult& parserResult) override;
};

class PhoneNumberSearcher : public Searcher {
public:
	PhoneNumberSearcher(vector<EmployeeInfo>* pDb) : Searcher(pDb) {}
	string getNumberByOption(const string& phoneNumber, const OPTION2 numberOption);
	virtual vector<EmployeeInfo> search(const ParserResult& parserResult) override;
};

class BirthdaySearcher : public Searcher {
public:
	BirthdaySearcher(vector<EmployeeInfo>* pDb) : Searcher(pDb) {}
	string getBirthDayByOption(const string& birthDay, const OPTION2 birthOption);
	virtual vector<EmployeeInfo> search(const ParserResult& parserResult) override;
};

class CertiSearcher : public Searcher {
public:
	CertiSearcher(vector<EmployeeInfo>* pDb) : Searcher(pDb) {}
	virtual vector<EmployeeInfo> search(const ParserResult& parserResult) override;
};