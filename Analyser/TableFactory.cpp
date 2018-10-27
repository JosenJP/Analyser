#include "TableFactory.hpp"
#include "TblSQLite.hpp"
#include "TblBuildOrder.hpp"

const char* TBL_PROJECT     = "Project";
const char* TBL_CPP         = "CPP";
const char* TBL_HEADER      = "Header";
const char* TBL_LIB         = "Lib";
const char* TBL_LIB_NAME    = "LibName";
const char* TBL_HR_RC       = "HrRc";
const char* TBL_RC_RC       = "RcRc";

std::string TableFactory::s_DBPath = "";

TblBase* TableFactory::GetTable(TableID a_TableID)
{
    static TblSQLite s_TblCPP(s_DBPath, TBL_CPP);
    static TblSQLite s_TblHeader(s_DBPath, TBL_HEADER);
    static TblSQLite s_TblProj(s_DBPath, TBL_PROJECT);
    static TblSQLite s_TblLib(s_DBPath, TBL_LIB);
    static TblSQLite s_TblLibName(s_DBPath, TBL_LIB_NAME);
    static TblSQLite s_TblHrRc(s_DBPath, TBL_HR_RC);
    static TblSQLite s_TblRcRc(s_DBPath, TBL_RC_RC);
    static TblBuildOrder s_TblBuildOrder(s_DBPath);

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
    case TableID::TBLID_Lib:
    {
        l_pTbl = &s_TblLib;
        break;
    }
    case TableID::TBLID_Lib_Name:
    {
        l_pTbl = &s_TblLibName;
        break;
    }
    case TableID::TBLID_Build_Order:
    {
        l_pTbl = &s_TblBuildOrder;
        break;
    }
    case TableID::TBLID_HR_RC:
    {
        l_pTbl = &s_TblHrRc;
        break;
    }
    case TableID::TBLID_RC_RC:
    {
        l_pTbl = &s_TblRcRc;
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

