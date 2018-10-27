#ifndef DIRECTLY_SEARCHER_HPP
#define DIRECTLY_SEARCHER_HPP

#include "BaseSearcher.hpp"

class DirectlySearcher : public BaseSearcher
{
public:
    DirectlySearcher() {};
    ~DirectlySearcher() {};

    void Search(TableID a_TBLID, std::set<std::string>& a_rInputSet, std::set<std::string>& a_rOutputSet /* output */) override;

private:

};

#endif // !DIRECTLY_SEARCHER_HPP


