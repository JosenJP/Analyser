#ifndef TABLE_FACTORY_HPP
#define TABLE_FACTORY_HPP

#include <string>
#include "FileType.hpp"

enum TableID
{
    TBlID_UnKnow  = 0,
    TBLID_Header  = 1,
    TBLID_CPP     = 2,
    TBLID_Proj    = 3,
    TBLID_Lib     = 4,
    TBLID_Lib_Name = 5
};

class TblBase;

class TableFactory
{
public:
    static TblBase* GetTable(TableID a_TableID);
    static void SetDBPath(std::string a_DBPath);

private:
    static std::string s_DBPath;
};

#endif // !TABLE_FACTORY_HPP

