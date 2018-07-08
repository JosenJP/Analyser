#ifndef CALCULATOR_HPP
#define CALCULATOR_HPP
#include <string>
#include <set>
#include <list>

#include "FileType.hpp"

class TblBase;

class Calculator
{
public:
    std::set<std::string>& Process(std::list<std::string> a_FileList);

private:
    std::set<std::string>& ProcessOne(std::string a_File);

    std::set<std::string> m_ProjListForOne;
    std::set<std::string> m_ProjList;
};

#endif // !CALCULATOR_HPP


