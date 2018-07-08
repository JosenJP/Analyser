#include "TblSQLite.hpp"

int TblSQLite::Callback(void* a_pData, int a_Argc, char** a_pArgv, char** a_pColName)
{
    m_ValueList.push_back(a_pArgv[0]);
    return 0;
}

sqlite3* TblSQLite::m_pDB = NULL;
std::list<std::string> TblSQLite::m_ValueList = {};

TblSQLite::TblSQLite(std::string a_DBPath, std::string a_TableName) :TblBase(a_TableName), m_DBPath(a_DBPath)
{
    m_pCache = new std::map<std::string, std::list<std::string>>();
}

TblSQLite::~TblSQLite()
{
    if (NULL != m_pCache)
    {
        delete m_pCache;
        m_pCache = NULL;
    }
}

std::list<std::string> TblSQLite::SearchByChild(std::string a_Child)
{
    std::map<std::string, std::list<std::string>>::iterator l_It = m_pCache->find(a_Child);
    if (m_pCache->end() != l_It)
    {
        return l_It->second;
    }

    std::string l_SQL = "select Parent from " + m_TblName + " where Child = \'" + a_Child + "\'";

    if (0 == SQLExec(l_SQL.c_str()) && !m_ValueList.empty())
    {
        (*m_pCache)[a_Child] = m_ValueList;
    }

    return m_ValueList;
}


int TblSQLite::SQLExec(const char* a_pSQL)
{
    int l_Rc = SQLITE_OK;

    OpenDB();
    if (NULL != m_pDB)
    {
        char* l_pMsg = NULL;

        m_ValueList.clear();
        l_Rc = sqlite3_exec(m_pDB, a_pSQL, Callback, NULL, &l_pMsg);

        if (SQLITE_OK != l_Rc)
        {
            fprintf(stderr, "SQL error: %s\n", l_pMsg);
            sqlite3_free(l_pMsg);
            return 1;
        }
    }

    return 0;
}

int TblSQLite::OpenDB(void)
{
    int l_Rc = SQLITE_OK;
    if (NULL == m_pDB)
    {
        /* Open database */
        l_Rc = sqlite3_open(m_DBPath.c_str(), &m_pDB);

        if (SQLITE_OK != l_Rc)
        {
            fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(m_pDB));
            sqlite3_close(m_pDB);
            m_pDB = NULL;
        }
    }
    return 0;
}

void TblSQLite::FreeDB(void)
{
    if (NULL != m_pDB)
    {
        sqlite3_close(m_pDB);
    }
}

