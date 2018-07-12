#ifndef TBL_SQLITE_HPP
#define TBL_SQLITE_HPP

#include <map>
#include <list>

#include "sqlite3.h"
#include "TblBase.hpp"

class TblSQLite : public TblBase
{
public:
    TblSQLite(std::string a_DBPath, std::string a_TableName);
    ~TblSQLite();

     std::list<std::string> SearchByChild(std::string a_Child) override;
     //std::string SearchByParent(std::string a_Parent) override;

     static void FreeDB(void);

protected:
     std::string GetSQLForSearchByChild(std::string a_Child) override;

private:
    int SQLExec(const char* a_pSQL);
    int OpenDB(void);

    static int Callback(void* a_pData, int a_Argc, char** a_pArgv, char** a_pColName);

    std::string m_DBPath;
    static std::list<std::string> m_ValueList;
    static sqlite3* m_pDB;

    std::map<std::string, std::list<std::string>>* m_pCache;
};

#endif // !TBL_SQLITE_HPP

