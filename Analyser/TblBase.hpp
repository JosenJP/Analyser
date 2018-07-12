#ifndef TBL_BASE_HPP
#define TBL_BASE_HPP

#include <string>
#include <list>

class TblBase
{
public:
    TblBase(std::string a_TableName) { m_TblName = a_TableName; }
    virtual ~TblBase() {}

    virtual std::list<std::string> SearchByChild(std::string a_Child) = 0;

protected:
    virtual std::string GetSQLForSearchByChild(std::string a_Child) = 0;
    //virtual std::string SearchByParent(std::string a_Parent) = 0;

    std::string m_TblName;
};

#endif // !TBL_BASE_HPP
