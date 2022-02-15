#include <iostream>
#include <vector>
#include <string>
#include "Define.h"
#include "Searcher.h"

using namespace std;

vector<EmployeeInfo> g_DB;

vector<EmployeeInfo> EmployeeNumSearcher::search(const ParserResult& parserResult) {
	if (parserResult.searchColumn.compare("employeeNum")) { 
		// Error
	}

	vector<EmployeeInfo> result;
	for (auto info : g_DB) {
		if (parserResult.searchData.compare(info.employeeNum) == 0) {
			result.emplace_back(info);
			return result;
		}
	}
	return result;
}