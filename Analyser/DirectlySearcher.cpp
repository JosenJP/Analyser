
#include "DirectlySearcher.hpp"
#include "TableFactory.hpp"
#include "TblBase.hpp"

void DirectlySearcher::Search(TableID a_TBLID, std::set<std::string>& a_rInputSet, std::set<std::string>& a_rOutputSet /* output */)
{
    TblBase* l_pTbl = TableFactory::GetTable(a_TBLID);

    for (std::string l_File: a_rInputSet)
    {
        std::list<std::string> l_FileList = l_pTbl->SearchByChild(l_File);

        if (!l_FileList.empty())
        {
            a_rOutputSet.insert(l_FileList.begin(), l_FileList.end());
        }
    }
}
