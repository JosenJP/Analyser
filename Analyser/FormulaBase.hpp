#ifndef FORMULA_BASE_HPP
#define FORMULA_BASE_HPP
#include <string>
#include <set>

class FormulaBase
{
public:
    virtual void Calc(std::string a_FileName, std::set<std::string>& a_rList) {}

};

#endif // !FORMULA_BASE_HPP


