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
    void GetAllHeaderFiles(std::set<std::string>& a_rHeaderFiles);
    void GetAllCPPFiles(std::set<std::string>& a_rHeaderFiles, std::set<std::string>& a_rCPPFiles);
    void GetAllPROJFiles(std::set<std::string>& a_rCPPFiles, std::set<std::string>& a_rProjFiles);
    void ResetList(void);

    std::set<std::string>* m_pHeaderFiles;
    std::set<std::string>* m_pCPPFiles;
};

#endif

