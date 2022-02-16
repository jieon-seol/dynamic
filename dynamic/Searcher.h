#pragma once
#include <vector>
#include "Define.h"

class Searcher {
public:
	virtual ~Searcher() {}
	Searcher(std::vector<EmployeeInfo>* pDataBase) : pDataBase_(pDataBase) {}
	virtual std::vector<EmployeeInfo> search(const ParserResult& parserResult) const = 0;

protected:
	std::vector<EmployeeInfo>* pDataBase_;
};

class EmployeeNumSearcher : public Searcher {
public:
	EmployeeNumSearcher(std::vector<EmployeeInfo>* pDataBase) : Searcher(pDataBase) {}

private:
	virtual std::vector<EmployeeInfo> search(const ParserResult& parserResult) const override;
};

class NameSearcher : public Searcher {
public:
	NameSearcher(std::vector<EmployeeInfo>* pDataBase) : Searcher(pDataBase) {}

private:
	virtual std::vector<EmployeeInfo> search(const ParserResult& parserResult) const override;
	std::string filterData(const std::string& name, const OPTION2 option) const;
};

class ClSearcher : public Searcher {
public:
	ClSearcher(std::vector<EmployeeInfo>* pDataBase) : Searcher(pDataBase) {}

private:
	virtual std::vector<EmployeeInfo> search(const ParserResult& parserResult) const override;
};

class PhoneNumberSearcher : public Searcher {
public:
	PhoneNumberSearcher(std::vector<EmployeeInfo>* pDataBase) : Searcher(pDataBase) {}

private:
	virtual std::vector<EmployeeInfo> search(const ParserResult& parserResult) const override;
	std::string filterData(const std::string& phoneNumber, const OPTION2 numberOption) const;
};

class BirthdaySearcher : public Searcher {
public:
	BirthdaySearcher(std::vector<EmployeeInfo>* pDataBase) : Searcher(pDataBase) {}

private:
	virtual std::vector<EmployeeInfo> search(const ParserResult& parserResult) const override;
	std::string filterData(const std::string& birthDay, const OPTION2 birthOption) const;
};

class CertiSearcher : public Searcher {
public:
	CertiSearcher(std::vector<EmployeeInfo>* pDataBase) : Searcher(pDataBase) {}

private:
	virtual std::vector<EmployeeInfo> search(const ParserResult& parserResult) const override;
};

class IFactorySearcher {
public:
	virtual ~IFactorySearcher() {}
	virtual Searcher* getSearcher(const ParserResult& parserResult) const = 0;
};

class FactorySearcher : public IFactorySearcher {
public:
	FactorySearcher(std::vector<EmployeeInfo>* pDataBase) {
		pEmployeeNumSearcher_ = new EmployeeNumSearcher(pDataBase);
		pNameSearcher_ = new NameSearcher(pDataBase);
		pClSearcher_ = new ClSearcher(pDataBase);
		pPhoneNumSearcher_ = new PhoneNumberSearcher(pDataBase);
		pBirthdaySearcher_ = new BirthdaySearcher(pDataBase);
		pCertiSearcher_ = new CertiSearcher(pDataBase);
	}
	~FactorySearcher() {
		delete pEmployeeNumSearcher_;
		delete pNameSearcher_;
		delete pClSearcher_;
		delete pPhoneNumSearcher_;
		delete pBirthdaySearcher_;
		delete pCertiSearcher_;
	}

private:
	virtual Searcher* getSearcher(const ParserResult& parserResult) const override;

private:
	Searcher* pEmployeeNumSearcher_;
	Searcher* pNameSearcher_;
	Searcher* pClSearcher_;
	Searcher* pPhoneNumSearcher_;
	Searcher* pBirthdaySearcher_;
	Searcher* pCertiSearcher_;
};