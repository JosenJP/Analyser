#ifndef FORMULA_HEADER_HPP
#define FORMULA_HEADER_HPP

#include "FormulaBase.hpp"

class FormulaHeader : public FormulaBase
{
public:
    FormulaHeader();
    ~FormulaHeader();

    void Calc(std::string a_FileName, std::set<std::string>& a_rList) override;

private:
    void GetAllHeaderFiles(std::set<std::string>& a_rHeaderFiles /*input and output*/);
    void GetAllCPPFiles(std::set<std::string>& a_rHeaderFiles, std::set<std::string>& a_rFiles /*output*/);
    void GetAllPROJFiles(std::set<std::string>& a_rCPPFiles, std::set<std::string>& a_rProjFiles /*output*/);
    void GetDirRcFiles(std::set<std::string>& a_rHeaderFiles, std::set<std::string>& a_rRCFiles /*output*/);
    void GetAllRcFiles(std::set<std::string>& a_rRCFiles /*input and output*/);
    void ResetList(void);

    std::set<std::string>* m_pHeaderFiles;
    std::set<std::string>* m_pCPPFiles;
    std::set<std::string>* m_pRCFiles;
};

#endif

