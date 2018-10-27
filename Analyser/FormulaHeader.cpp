#include "FormulaHeader.hpp"
#include "TableFactory.hpp"
#include "PointerHelper.hpp"
#include "SearcherFactory.hpp"

FormulaHeader::FormulaHeader()
{
    m_pHeaderFiles = new std::set<std::string>();
    m_pCPPFiles = new std::set<std::string>();
    m_pRCFiles = new std::set<std::string>();
}

FormulaHeader::~FormulaHeader()
{
    //if (NULL != m_pHeaderFiles)
    //{
    //    delete m_pHeaderFiles;
    //    m_pHeaderFiles = NULL;
    //}

    //if (NULL != m_pCPPFiles)
    //{
    //    delete m_pCPPFiles;
    //    m_pCPPFiles = NULL;
    //}

    DeleteObject<std::set<std::string>>(m_pHeaderFiles);
    DeleteObject<std::set<std::string>>(m_pCPPFiles);
    DeleteObject<std::set<std::string>>(m_pRCFiles);
}

void FormulaHeader::Calc(std::string a_FileName, std::set<std::string>& a_rList)
{
    ResetList();

    m_pHeaderFiles->insert(a_FileName);

    //Check the Header table to get all the parents
    //It's a tree, use wide first loop to get all the node.
    GetAllHeaderFiles(*m_pHeaderFiles);

    //get cpp and Rc files based on header file
    GetAllCPPFiles(*m_pHeaderFiles, *m_pCPPFiles);

    //Get all direct Rc file based on header files
    GetDirRcFiles(*m_pHeaderFiles, *m_pRCFiles);

    //Find all the Rc files
    GetAllRcFiles(*m_pRCFiles);

    //Include the Rc files
    m_pCPPFiles->insert(m_pRCFiles->begin(), m_pRCFiles->end());

    //get project file based on cpp file
    GetAllPROJFiles(*m_pCPPFiles, a_rList);
}

void FormulaHeader::GetAllHeaderFiles(std::set<std::string>& a_rHeaderFiles)
{
    //std::queue<std::string> l_FileQueue = {};

    ////This set must have contained the target header file.
    //if (a_rHeaderFiles.size() < 1)
    //{
    //    return;
    //}

    //TblBase* l_pTblHeader = TableFactory::GetTable(TableID::TBLID_Header);

    //l_FileQueue.push(*(a_rHeaderFiles.begin()));

    //std::string l_CurrHeader = "";
    //while (l_FileQueue.size() > 0)
    //{
    //    l_CurrHeader = l_FileQueue.front();
    //    l_FileQueue.pop();

    //    std::list<std::string> l_HeaderList = l_pTblHeader->SearchByChild(l_CurrHeader);

    //    for (std::string l_Header : l_HeaderList)
    //    {
    //        //If this header file is not included in the header file set, inset it to the set and queue.
    //        if (a_rHeaderFiles.find(l_Header) == a_rHeaderFiles.end())
    //        {
    //            l_FileQueue.push(l_Header);
    //            a_rHeaderFiles.insert(l_Header);
    //        }
    //    }
    //}

    BaseSearcher* l_pSearcher = SearcherFactory::GetSearcher(SearcherType::Recursive);
    l_pSearcher->Search(TableID::TBLID_Header, a_rHeaderFiles, a_rHeaderFiles);
}

void FormulaHeader::GetAllCPPFiles(std::set<std::string>& a_rHeaderFiles, std::set<std::string>& a_rFiles)
{
    //TblBase* l_pTblCPP = TableFactory::GetTable(TableID::TBLID_CPP);

    //for (std::string l_Header : a_rHeaderFiles)
    //{
    //    std::list<std::string> l_CPPList = l_pTblCPP->SearchByChild(l_Header);

    //    a_rFiles.insert(l_CPPList.begin(), l_CPPList.end());
    //}

    BaseSearcher* l_pSearcher = SearcherFactory::GetSearcher(SearcherType::Directly);
    l_pSearcher->Search(TableID::TBLID_CPP, a_rHeaderFiles, a_rFiles);
}

void FormulaHeader::GetAllPROJFiles(std::set<std::string>& a_rCPPFiles, std::set<std::string>& a_rProjFiles)
{
    //TblBase* l_pTblProj = TableFactory::GetTable(TableID::TBLID_Proj);
    //for (std::string l_CPP : a_rCPPFiles)
    //{
    //    std::list<std::string> l_ProjList = l_pTblProj->SearchByChild(l_CPP);

    //    a_rProjFiles.insert(l_ProjList.begin(), l_ProjList.end());
    //}

    BaseSearcher* l_pSearcher = SearcherFactory::GetSearcher(SearcherType::Directly);
    l_pSearcher->Search(TableID::TBLID_Proj, a_rCPPFiles, a_rProjFiles);
}

//Get direct RC files form HR_RC table.
void FormulaHeader::GetDirRcFiles(std::set<std::string>& a_rHeaderFiles, std::set<std::string>& a_rRCFiles /*output*/)
{
    //TblBase* l_pTblHRRC = TableFactory::GetTable(TableID::TBLID_HR_RC);

    //for (std::string l_Header : a_rHeaderFiles)
    //{
    //    std::list<std::string> l_CPPList = l_pTblHRRC->SearchByChild(l_Header);

    //    a_rRCFiles.insert(l_CPPList.begin(), l_CPPList.end());
    //}

    BaseSearcher* l_pSearcher = SearcherFactory::GetSearcher(SearcherType::Directly);
    l_pSearcher->Search(TableID::TBLID_HR_RC, a_rHeaderFiles, a_rRCFiles);
}

//Get all RC files from RC_RC table.
void FormulaHeader::GetAllRcFiles(std::set<std::string>& a_rRCFiles /* input and output*/)
{
    BaseSearcher* l_pSearcher = SearcherFactory::GetSearcher(SearcherType::Recursive);
    l_pSearcher->Search(TableID::TBLID_RC_RC, a_rRCFiles, a_rRCFiles);
}

void FormulaHeader::ResetList(void)
{
    m_pHeaderFiles->clear();
    m_pCPPFiles->clear();
    m_pRCFiles->clear();
}

