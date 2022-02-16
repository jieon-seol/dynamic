#include "DBManager.h"
#include "Printer.h"
#include "Parser.h"

std::string DBManager::Query(std::string queryString)
{
    // TODO: invalid�� queryString �˻��߰�
    if (queryString.empty()) {
        return std::string();
    }

    Parser parser;
    ParserResult parseResult = parser.parse(queryString);
    Operator* op = opFactory->getOperator(parseResult);
    Searcher* sc = scFactory->getSearcher(parseResult);


    std::vector<EmployeeInfo> lists = sc->search(parseResult);
    op->operate(&lists, parseResult);
    std::string queryResult = Printer::GetPrintString(parseResult, lists);

    return queryResult;
}