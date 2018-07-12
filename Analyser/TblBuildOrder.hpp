
#ifndef TBL_BUILD_ORDER_HPP
#define TBL_BUILD_ORDER_HPP

#include "TblSQLite.hpp"

class TblBuildOrder : public TblSQLite
{
public:
    TblBuildOrder(std::string a_DBPath, std::string a_TableName = "BuildOrder"): TblSQLite(a_DBPath, a_TableName) {}
    ~TblBuildOrder() {}

    std::string GetSQLForSearchByChild(std::string a_Child) override;
};

#endif // !TBL_BUILD_ORDER_HPP


