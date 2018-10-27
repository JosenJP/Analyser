#ifndef FORMULA_RC_HPP
#define FORMULA_RC_HPP

#include "FormulaBase.hpp"

class FormulaRC : public FormulaBase
{
public:
    FormulaRC() {};
    ~FormulaRC() {};

    void Calc(std::string a_FileName, std::set<std::string>& a_rList) override;

private:
    void GetAllRCFiles(std::set<std::string>& a_rRCFiles);
    void GetAllPROJFiles(std::set<std::string>& a_rCPPFiles, std::set<std::string>& a_rProjFiles);

};

#endif // !FORMULA_RC_HPP

