#include "TableFactory.hpp"
#include "TblSQLite.hpp"

const char* TBL_PROJECT     = "Project";
const char* TBL_CPP         = "CPP";
const char* TBL_HEADER      = "Header";

std::string TableFactory::s_DBPath = "";

TblBase* TableFactory::GetTable(TableID a_TableID)
{
    static TblSQLite s_TblCPP(s_DBPath, TBL_CPP);
    static TblSQLite s_TblHeader(s_DBPath, TBL_HEADER);
    static TblSQLite s_TblProj(s_DBPath, TBL_PROJECT);

    TblBase* l_pTbl = NULL;
    switch (a_TableID)
    {
    case TableID::TBLID_Header:
    {
        l_pTbl = &s_TblHeader;
        break;
    }
    case TableID::TBLID_CPP:
    {
        l_pTbl = &s_TblCPP;
        break;
    }
    case TableID::TBLID_Proj:
    {
        l_pTbl = &s_TblProj;
        break;
    }
    default:
    {
        break;
    }
    }

    return l_pTbl;
}

void TableFactory::SetDBPath(std::string a_DBPath)
{
    s_DBPath = a_DBPath;
}

