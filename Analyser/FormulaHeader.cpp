#include <queue>
#include <set>
#include <list>

#include "FormulaHeader.hpp"
#include "TableFactory.hpp"
#include "TblBase.hpp"

FormulaHeader::FormulaHeader()
{
    m_pHeaderFiles = new std::set<std::string>();
    m_pCPPFiles = new std::set<std::string>();
}

FormulaHeader::~FormulaHeader()
{
    if (NULL != m_pHeaderFiles)
    {
        delete m_pHeaderFiles;
        m_pHeaderFiles = NULL;
    }

    if (NULL != m_pCPPFiles)
    {
        delete m_pCPPFiles;
        m_pCPPFiles = NULL;
    }
}

void FormulaHeader::Calc(std::string a_FileName, std::set<std::string>& a_rList)
{
    //Reset project List
    a_rList.clear();
    ResetList();

    m_pHeaderFiles->insert(a_FileName);

    //Check the Header table to get all the parents
    //It's a tree, use wide first loop to get all the node.
    GetAllHeaderFiles(*m_pHeaderFiles);

    //get cpp based on header file
    GetAllCPPFiles(*m_pHeaderFiles, *m_pCPPFiles);

    //get project file based on cpp file
    GetAllPROJFiles(*m_pCPPFiles, a_rList);
}

void FormulaHeader::GetAllHeaderFiles(std::set<std::string>& a_rHeaderFiles)
{
    std::queue<std::string> l_FileQueue = {};

    //This set must have contained the target header file.
    if (a_rHeaderFiles.size() < 1)
    {
        return;
    }

    TblBase* l_pTblHeader = TableFactory::GetTable(TableID::TBLID_Header);

    l_FileQueue.push(*(a_rHeaderFiles.begin()));

    std::string l_CurrHeader = "";
    while (l_FileQueue.size() > 0)
    {
        l_CurrHeader = l_FileQueue.front();
        l_FileQueue.pop();

        std::list<std::string> l_HeaderList = l_pTblHeader->SearchByChild(l_CurrHeader);

        for (std::string l_Header : l_HeaderList)
        {
            //If this header file is not included in the header file set, inset it to the set and queue.
            if (a_rHeaderFiles.find(l_Header) == a_rHeaderFiles.end())
            {
                l_FileQueue.push(l_Header);
                a_rHeaderFiles.insert(l_Header);
            }
        }
    }
}

void FormulaHeader::GetAllCPPFiles(std::set<std::string>& a_rHeaderFiles, std::set<std::string>& a_rCPPFiles)
{
    TblBase* l_pTblCPP = TableFactory::GetTable(TableID::TBLID_CPP);

    for (std::string l_Header : a_rHeaderFiles)
    {
        std::list<std::string> l_CPPList = l_pTblCPP->SearchByChild(l_Header);

        a_rCPPFiles.insert(l_CPPList.begin(), l_CPPList.end());
    }
}

void FormulaHeader::GetAllPROJFiles(std::set<std::string>& a_rCPPFiles, std::set<std::string>& a_rProjFiles)
{
    TblBase* l_pTblProj = TableFactory::GetTable(TableID::TBLID_Proj);
    for (std::string l_CPP : a_rCPPFiles)
    {
        std::list<std::string> l_ProjList = l_pTblProj->SearchByChild(l_CPP);

        a_rProjFiles.insert(l_ProjList.begin(), l_ProjList.end());
    }
}

void FormulaHeader::ResetList(void)
{
    m_pHeaderFiles->clear();
    m_pCPPFiles->clear();
}

