#ifndef BASE_SEARCHER_HPP
#define BASE_SEARCHER_HPP

#include <set>
#include "TableFactory.hpp"

class BaseSearcher
{
public:
    BaseSearcher() {};
    virtual ~BaseSearcher() {};
    virtual void Search(TableID a_TBLID, std::set<std::string>& a_rInputSet, std::set<std::string>& a_rOutputSet /* output */) = 0;

private:

};

#endif // !BASE_SEARCHER_HPP


