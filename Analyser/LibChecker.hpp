#ifndef LIB_CHECKER_HPP
#define LIB_CHECKER_HPP
#include <set>
#include <list>
#include <string>

class LibChecker
{
public:
    void Process(std::list<std::string>& a_rProjList);

private:
    void CheckProjType(std::list<std::string>& a_rProjList,
                       std::set<std::string>& a_rLibProjList,
                       std::set<std::string>& a_rNonLibProjList,
                       std::set<std::string>& a_rLibList);
};

#endif // !LIB_CHECKER_HPP


