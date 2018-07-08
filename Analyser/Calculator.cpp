#include <memory>
#include "Calculator.hpp"
#include "FormulaSelector.hpp"
#include "FormulaBase.hpp"

std::set<std::string>& Calculator::ProcessOne(std::string a_File)
{
    FileType l_FileType = FileType::UnKnow;
    l_FileType = FileChecker::Check(a_File.c_str());

    FormulaBase* l_pFormula = FormulaSelector::GetFormula(l_FileType);
    if (NULL != l_pFormula)
    {
        l_pFormula->Calc(a_File, m_ProjListForOne);
    }

    return m_ProjListForOne;
}

std::set<std::string>& Calculator::Process(std::list<std::string> a_FileList)
{
    m_ProjList.clear();
    for (std::string l_File : a_FileList)
    {
        ProcessOne(l_File);
        m_ProjList.insert(m_ProjListForOne.begin(), m_ProjListForOne.end());
    }

    return m_ProjList;
}
