#include "FormulaCPP.hpp"
#include "TableFactory.hpp"
#include "TblBase.hpp"

void FormulaCPP::Calc(std::string a_FileName, std::set<std::string>& a_rList)
{
    TblBase* l_pTblProj = TableFactory::GetTable(TableID::TBLID_Proj);

    std::list<std::string> l_ValueList = l_pTblProj->SearchByChild(a_FileName);

    a_rList.clear();
    if (l_ValueList.empty())
    {
        return;
    }

    a_rList.insert(l_ValueList.begin(), l_ValueList.end());
}