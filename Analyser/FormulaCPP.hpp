#ifndef FORMULA_CPP_HPP
#define FORMULA_CPP_HPP
#include "FormulaBase.hpp"


class FormulaCPP : public FormulaBase
{
public:
    void Calc(std::string a_FileName, std::set<std::string>& a_rList) override;

};

#endif // !FORMULA_CPP_HPP


