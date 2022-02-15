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
	virtual vector<EmployeeInfo> search(const ParserResult& parserResult) override {};
};

class NameSearcher : public Searcher {
public:
	virtual vector<EmployeeInfo> search(const ParserResult& parserResult) override {};
};

class ClSearcher : public Searcher {
public:
	virtual vector<EmployeeInfo> search(const ParserResult& parserResult) override {};
};

class PhoneNumberSearcher : public Searcher {
public:
	virtual vector<EmployeeInfo> search(const ParserResult& parserResult) override {};
};

class BirthdaySearcher : public Searcher {
public:
	virtual vector<EmployeeInfo> search(const ParserResult& parserResult) override {};
};

class CertiSearcher : public Searcher {
public:
	virtual vector<EmployeeInfo> search(const ParserResult& parserResult) override {};
};