#include "FormulaSelector.hpp"
#include "FormulaHeader.hpp"
#include "FormulaCPP.hpp"

FormulaBase* FormulaSelector::GetFormula(FileType a_FileType)
{
    static FormulaHeader s_FormulaHeader;
    static FormulaCPP s_FormulaCPP;

    FormulaBase* l_pFormula = NULL;

    switch (a_FileType)
    {
    case FileType::Header:
    {
        l_pFormula = &s_FormulaHeader;
        break;
    }
    case FileType::CPP:
        //Fall Through
    case FileType::UnKnow:
    {
        l_pFormula = &s_FormulaCPP;
        break;
    }
    default:
        break;
    }


    return l_pFormula;
}

