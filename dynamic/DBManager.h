#include "Define.h"
#include "Operator.h"
#include "Searcher.h"
#include <vector>

class DBManager
{
public:
    DBManager():database_(){
        pOperatorFactory = new FactoryOperator(&database_);
        pSearcherFactory = new FactorySearcher(&database_);
    }
    ~DBManager() {
        if(pOperatorFactory) delete pOperatorFactory;
        if(pSearcherFactory) delete pSearcherFactory;
    }

    std::string query(const std::string& queryString);

private:
    std::map<std::string, EmployeeInfo> database_;
    IFactoryOperator *pOperatorFactory;
    IFactorySearcher *pSearcherFactory;
};