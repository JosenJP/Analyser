#include <set>
#include <queue>

#include "LibChecker.hpp"
#include "TableFactory.hpp"
#include "TblBase.hpp"

void LibChecker::Process(std::list<std::string>& a_rProjList)
{
    //TblBase* l_pTblLibName = TableFactory::GetTable(TableID::TBLID_Lib_Name);
    TblBase* l_pTblLib = TableFactory::GetTable(TableID::TBLID_Lib);

    std::set<std::string> l_ProjLib = {};
    std::set<std::string> l_ProjNonLib = {};
    std::set<std::string> l_Libs = {};

    std::set<std::string> l_TempProjLib = {};
    std::set<std::string> l_TempProjNonLib = {};
    std::set<std::string> l_TempLibs = {};

    std::set<std::string>   l_AllLib = {};
    std::queue<std::string> l_LibQue = {};

    CheckProjType(a_rProjList,
                  l_TempProjLib,
                  l_TempProjNonLib,
                  l_Libs);

    l_ProjNonLib.insert(l_TempProjNonLib.begin(), l_TempProjNonLib.end());
    l_ProjLib.insert(l_TempProjLib.begin(), l_TempProjLib.end());

    for (std::string l_Lib : l_Libs)
    {
        //Process One Lib
        l_AllLib.clear();
        l_AllLib.insert(l_Lib);
        l_LibQue.push(l_Lib);

        std::string l_CurrLib = "";
        while (l_LibQue.size() > 0)
        {
            l_CurrLib = l_LibQue.front();
            l_LibQue.pop();

            std::list<std::string> l_ProjList = l_pTblLib->SearchByChild(l_CurrLib);

            //Reset the lists
            l_TempProjLib.clear();
            l_TempProjNonLib.clear();
            l_TempLibs.clear();

            CheckProjType(l_ProjList,
                          l_TempProjLib,
                          l_TempProjNonLib,
                          l_TempLibs);

            l_ProjNonLib.insert(l_TempProjNonLib.begin(), l_TempProjNonLib.end());
            l_ProjLib.insert(l_TempProjLib.begin(), l_TempProjLib.end());

            for (std::string l_Lib : l_TempLibs)
            {
                if (l_AllLib.end() == l_AllLib.find(l_Lib))
                {
                    l_LibQue.push(l_Lib);
                    l_AllLib.insert(l_Lib);
                }
            }
        }
    }

    //Put the lib list in the front, then the non lib list.
    a_rProjList.clear();
    a_rProjList.insert(a_rProjList.begin(), l_ProjLib.begin(), l_ProjLib.end());
    a_rProjList.insert(a_rProjList.end(), l_ProjNonLib.begin(), l_ProjNonLib.end());
}

void LibChecker::CheckProjType(std::list<std::string>& a_rProjList,
                               std::set<std::string>& a_rLibProjList,
                               std::set<std::string>& a_rNonLibProjList,
                               std::set<std::string>& a_rLibList)
{
    TblBase* l_pTblLibName = TableFactory::GetTable(TableID::TBLID_Lib_Name);

    for (std::string l_Proj : a_rProjList)
    {
        //Check the project is a static library or not.
        std::list<std::string> l_LibName = l_pTblLibName->SearchByChild(l_Proj);
        if (l_LibName.size() == 1)
        {
            //Lib
            a_rLibList.insert(l_LibName.front());
            a_rLibProjList.insert(l_Proj);
        }
        else
        {
            a_rNonLibProjList.insert(l_Proj);
        }
    }
}
