#include "DBManager.h"
#include "Printer.h"
#include "Parser.h"

std::string DBManager::query(const std::string& queryString)
{
    if (queryString.empty()) {
        return std::string();
    }
    
    ParserResult parseResult;
    Parser parser;
    parseResult = parser.parse(queryString);
    Operator* pOperator = pOperatorFactory->getOperator(parseResult);
    Searcher* pSearcher = pSearcherFactory->getSearcher(parseResult);

    std::map<std::string, EmployeeInfo> lists = pSearcher->search(parseResult);
    pOperator->operate(&lists, parseResult);

    return Printer::getPrintString(parseResult, lists);
}