
#include <queue>
#include <list>

#include "RecursiveSearcher.hpp"
#include "TableFactory.hpp"
#include "TblBase.hpp"

void RecursiveSearcher::Search(TableID a_TBLID, std::set<std::string>& a_rInputSet /* No use */, std::set<std::string>& a_rOutputSet /* output */)
{
    std::queue<std::string> l_FileQueue = {};

    //This set must have contained the target header file.
    if (a_rOutputSet.size() < 1)
    {
        return;
    }

    TblBase* l_pTbl = TableFactory::GetTable(a_TBLID);

    l_FileQueue.push(*(a_rOutputSet.begin()));

    std::string l_CurrFile = "";
    while (l_FileQueue.size() > 0)
    {
        l_CurrFile = l_FileQueue.front();
        l_FileQueue.pop();

        std::list<std::string> l_FileList = l_pTbl->SearchByChild(l_CurrFile);

        for (std::string l_File : l_FileList)
        {
            //If this header file is not included in the header file set, inset it to the set and queue.
            if (a_rOutputSet.find(l_File) == a_rOutputSet.end())
            {
                l_FileQueue.push(l_File);
                a_rOutputSet.insert(l_File);
            }
        }
    }
}
