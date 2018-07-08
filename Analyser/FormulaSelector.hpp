#ifndef FORMULA_SELECTOR_HPP
#define FORMULA_SELECTOR_HPP
#include "FileType.hpp"

class FormulaBase;

class FormulaSelector
{
public:
    static FormulaBase* GetFormula(FileType a_FileType);

};

#endif
