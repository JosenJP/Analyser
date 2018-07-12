#include "TblBuildOrder.hpp"

std::string TblBuildOrder::GetSQLForSearchByChild(std::string a_Child)
{
    return "select OrderNumber from " + m_TblName + " where Proj = \'" + a_Child + "\'";
}

