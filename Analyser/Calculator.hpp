#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP
#include <string>
#include <set>
#include <list>
#include <memory>

#include "FileType.hpp"
#include "LibChecker.hpp"

class TblBase;

class Calculator
{
public:
    std::list<std::string>& Process(std::list<std::string> a_FileList);

private:
    std::set<std::string>& ProcessOne(std::string a_File);

    std::set<std::string> m_ProjListForOne;
    std::set<std::string> m_ProjList;
    std::list<std::string> m_SortedProjList;
    std::unique_ptr<LibChecker> m_pLibChecker;
};

#endif // !CALCULATOR_HPP


