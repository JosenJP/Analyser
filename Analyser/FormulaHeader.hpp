#ifndef FORMULA_HEADER_HPP
#define FORMULA_HEADER_HPP

#include "FormulaBase.hpp"

class FormulaHeader : public FormulaBase
{
public:
    void Calc(std::string a_FileName, std::set<std::string>& a_rList) override;

};

#endif

