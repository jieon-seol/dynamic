#pragma once
#include <map>
#include <string>
#include "Define.h"

class Searcher {
public:
	virtual ~Searcher() {}
	Searcher(std::map<int, EmployeeInfo>* pDataBase) : pDataBase_(pDataBase) {}
	virtual std::map<int, EmployeeInfo> search(const ParserResult& parserResult) const = 0;

protected:
	std::map<int, EmployeeInfo>* pDataBase_;
};

class EmployeeNumSearcher : public Searcher {
public:
	EmployeeNumSearcher(std::map<int, EmployeeInfo>* pDataBase) : Searcher(pDataBase) {}

private:
	virtual std::map<int, EmployeeInfo> search(const ParserResult& parserResult) const override;
};

class NameSearcher : public Searcher {
public:
	NameSearcher(std::map<int, EmployeeInfo>* pDataBase) : Searcher(pDataBase) {}

private:
	virtual std::map<int, EmployeeInfo> search(const ParserResult& parserResult) const override;
	std::string filterData(const std::string& name, const OPTION2 option) const;

private:
	static constexpr int MAX_SUB_NAME_COUNT = 2;
	static constexpr int LAST_NAME_INDEX = 0;
	static constexpr int FIRST_NAME_INDEX = 1;	
};

class ClSearcher : public Searcher {
public:
	ClSearcher(std::map<int, EmployeeInfo>* pDataBase) : Searcher(pDataBase) {}

private:
	virtual std::map<int, EmployeeInfo> search(const ParserResult& parserResult) const override;
};

class PhoneNumberSearcher : public Searcher {
public:
	PhoneNumberSearcher(std::map<int, EmployeeInfo>* pDataBase) : Searcher(pDataBase) {}

private:
	virtual std::map<int, EmployeeInfo> search(const ParserResult& parserResult) const override;
	std::string filterData(const std::string& phoneNumber, const OPTION2 numberOption) const;

private:
	static constexpr int MAX_SUB_PHONE_NUM_COUNT = 3;
	static constexpr int MIDDLE_PHONE_NUM_INDEX = 1;
	static constexpr int LAST_PHONE_NUM_INDEX = 2;
};

class BirthdaySearcher : public Searcher {
public:
	BirthdaySearcher(std::map<int, EmployeeInfo>* pDataBase) : Searcher(pDataBase) {}

private:
	virtual std::map<int, EmployeeInfo> search(const ParserResult& parserResult) const override;
	std::string filterData(const std::string& birthDay, const OPTION2 birthOption) const;

private:
	static constexpr int YEAR_START_INDEX = 0;
	static constexpr int YEAR_NUM_COUNT = 4;
	static constexpr int MONTH_START_INDEX = YEAR_START_INDEX + YEAR_NUM_COUNT;
	static constexpr int MONTH_NUM_COUNT = 2;
	static constexpr int DAY_START_INDEX = MONTH_START_INDEX + MONTH_NUM_COUNT;
	static constexpr int DAY_NUM_COUNT = 2;
};

class CertiSearcher : public Searcher {
public:
	CertiSearcher(std::map<int, EmployeeInfo>* pDataBase) : Searcher(pDataBase) {}

private:
	virtual std::map<int, EmployeeInfo> search(const ParserResult& parserResult) const override;
};

class IFactorySearcher {
public:
	virtual ~IFactorySearcher() {}
	virtual Searcher* getSearcher(const ParserResult& parserResult) const = 0;
};

class FactorySearcher : public IFactorySearcher {
public:
	FactorySearcher(std::map<int, EmployeeInfo>* pDataBase) {
		pEmployeeNumSearcher_ = new EmployeeNumSearcher(pDataBase);
		pNameSearcher_ = new NameSearcher(pDataBase);
		pClSearcher_ = new ClSearcher(pDataBase);
		pPhoneNumSearcher_ = new PhoneNumberSearcher(pDataBase);
		pBirthdaySearcher_ = new BirthdaySearcher(pDataBase);
		pCertiSearcher_ = new CertiSearcher(pDataBase);
	}
	~FactorySearcher() {
		if (pEmployeeNumSearcher_) delete pEmployeeNumSearcher_;
		if (pNameSearcher_) delete pNameSearcher_;
		if (pClSearcher_) delete pClSearcher_;
		if (pPhoneNumSearcher_) delete pPhoneNumSearcher_;
		if (pBirthdaySearcher_) delete pBirthdaySearcher_;
		if (pCertiSearcher_) delete pCertiSearcher_;
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