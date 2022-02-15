#include "Define.h"
#include "Operator.h"
#include "Searcher.h"
#include <vector>

class DBManager
{
public:
    DBManager():database_(){
        opFactory = new FactoryOperator(&database_);
        scFactory = new FactorySearcher(&database_);
    }
    ~DBManager() {
        delete opFactory;
        delete scFactory;
    }

    std::string Query(std::string queryString);

private:
    std::vector<EmployeeInfo> database_;
    IFactoryOperator *opFactory;
    IFactorySearcher *scFactory;
};