#include "FormulaRC.hpp"
#include "SearcherFactory.hpp"

void FormulaRC::Calc(std::string a_FileName, std::set<std::string>& a_rList)
{
    std::set<std::string> l_RCFileSet;
    l_RCFileSet.insert(a_FileName);

    GetAllRCFiles(l_RCFileSet);

    GetAllPROJFiles(l_RCFileSet, a_rList);
}

void FormulaRC::GetAllRCFiles(std::set<std::string>& a_rRCFiles)
{
    BaseSearcher* l_pSearcher = SearcherFactory::GetSearcher(SearcherType::Recursive);
    l_pSearcher->Search(TableID::TBLID_RC_RC, a_rRCFiles, a_rRCFiles);
}

void FormulaRC::GetAllPROJFiles(std::set<std::string>& a_rCPPFiles, std::set<std::string>& a_rProjFiles)
{
    BaseSearcher* l_pSearcher = SearcherFactory::GetSearcher(SearcherType::Directly);
    l_pSearcher->Search(TableID::TBLID_Proj, a_rCPPFiles, a_rProjFiles);
}

