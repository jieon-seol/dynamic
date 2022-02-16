#include <iostream>
#include <fstream>
#include "DBManager.h"

using namespace std;

namespace {
	vector<string> getAllFileLines(const string& inputFileName) {
		ifstream inputFile(inputFileName);
		if (!inputFile.is_open()) {
			cerr << "Could not open the file - '"
				<< inputFileName << "'" << endl;
			return vector<string>();
		}

		vector<string> result;
		string line;
		while (getline(inputFile, line)) {
			result.push_back(line);
		}
		inputFile.close();
		
		return result;
	}

	vector<string> getAllQueryResults(const vector<string>& queryStrings) {
		DBManager manager;
		vector<string> queryResults;
		for (const auto& queryString : queryStrings) {
			auto result = manager.query(queryString);
			queryResults.push_back(result);
		}
		return queryResults;
	}

	void printStringsToFile(const string& outputFileName, const vector<string> stringLines) {
		ofstream outputFile(outputFileName);
		if (!outputFile.is_open()) {
			cerr << "Could not open the file - '"
				<< outputFileName << "'" << endl;
			return;
		}

		for (const auto& line : stringLines) {
			outputFile << line;
		}
		outputFile.close();
	}
}

int main(int argc, char *argv[]) {
	if(argc != 3){
		cerr << argv[0] << " [input file] [output file]" << endl;
		return EXIT_FAILURE;
	}

	vector<string> queryStrings = getAllFileLines(argv[1]);
	vector<string> queryResults = getAllQueryResults(queryStrings);
	printStringsToFile(argv[2], queryResults);
}