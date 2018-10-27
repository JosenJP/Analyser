#include <memory>
#include "Calculator.hpp"
#include "FormulaSelector.hpp"
#include "FormulaBase.hpp"

std::set<std::string>& Calculator::ProcessOne(std::string a_File)
{
    FileType l_FileType = FileType::UnKnown;
    l_FileType = FileChecker::Check(a_File.c_str());

    FormulaBase* l_pFormula = FormulaSelector::GetFormula(l_FileType);
    if (NULL != l_pFormula)
    {
        m_ProjListForOne.clear();
        l_pFormula->Calc(a_File, m_ProjListForOne);
    }

    return m_ProjListForOne;
}

std::list<std::string>& Calculator::Process(std::list<std::string> a_FileList)
{
    m_ProjList.clear();
    for (std::string l_File : a_FileList)
    {
        ProcessOne(l_File);
        m_ProjList.insert(m_ProjListForOne.begin(), m_ProjListForOne.end());
    }

    m_SortedProjList.insert(m_SortedProjList.begin(), m_ProjList.begin(), m_ProjList.end());

    //Find all the project contain one of the libs.
    if (!m_pLibChecker)
    {
        m_pLibChecker = std::unique_ptr<LibChecker>(new LibChecker());
    }
    m_pLibChecker->Process(m_SortedProjList);

    //Sort the list base on Build Order.
    if (!m_pBuildSort)
    {
        m_pBuildSort = std::unique_ptr<BuildSort>(new BuildSort());
    }
    //m_pBuildSort->Sort(m_SortedProjList);

    return m_SortedProjList;
}
