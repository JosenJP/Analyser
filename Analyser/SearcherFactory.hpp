#ifndef SEARCHER_FACTORY_HPP
#define SEARCHER_FACTORY_HPP

#include "BaseSearcher.hpp"

enum SearcherType
{
    SearcherType_UnKnown     = 0,
    Directly    = 1,
    Recursive   = 2
};

class SearcherFactory
{
public:
    SearcherFactory() {};
    ~SearcherFactory() {};

    static BaseSearcher* GetSearcher(SearcherType a_SearcherType);

private:

};


#endif // !SEARCHER_FACTORY_HPP



