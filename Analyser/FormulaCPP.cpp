#include "FormulaCPP.hpp"
//#include "TableFactory.hpp"
//#include "TblBase.hpp"
#include "SearcherFactory.hpp"

void FormulaCPP::Calc(std::string a_FileName, std::set<std::string>& a_rList)
{
    std::set<std::string> l_FileSet;
    l_FileSet.insert(a_FileName);

    BaseSearcher* l_pSearcher = SearcherFactory::GetSearcher(SearcherType::Directly);
    l_pSearcher->Search(TableID::TBLID_Proj, l_FileSet, a_rList);

    //TblBase* l_pTblProj = TableFactory::GetTable(TableID::TBLID_Proj);

    //std::list<std::string> l_ValueList = l_pTblProj->SearchByChild(a_FileName);

    //if (l_ValueList.empty())
    //{
    //    return;
    //}

    //a_rList.insert(l_ValueList.begin(), l_ValueList.end());
}