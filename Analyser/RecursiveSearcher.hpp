#ifndef RECURSIVE_SEARCHER_HPP
#define RECURSIVE_SEARCHER_HPP

#include "BaseSearcher.hpp"

class RecursiveSearcher : public BaseSearcher
{
public:
    RecursiveSearcher() {};
    ~RecursiveSearcher() {};
    
    void Search(TableID a_TBLID, std::set<std::string>& a_rInputSet, std::set<std::string>& a_rOutputSet /* output */) override;

private:

};

#endif // !RECURSIVE_SEARCHER_HPP

