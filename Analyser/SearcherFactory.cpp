#include "SearcherFactory.hpp"
#include "DirectlySearcher.hpp"
#include "RecursiveSearcher.hpp"

BaseSearcher* SearcherFactory::GetSearcher(SearcherType a_SearcherType)
{
    static DirectlySearcher s_DirectlySearcher;
    static RecursiveSearcher s_RecursiveSearcher;

    BaseSearcher* l_pSearcher = NULL;

    switch (a_SearcherType)
    {
    case SearcherType::Directly:
    {
        l_pSearcher = &s_DirectlySearcher;
        break;
    }
    case SearcherType::Recursive:
    {
        l_pSearcher = &s_RecursiveSearcher;
        break;
    }
    case SearcherType::SearcherType_UnKnown:
    default:

        break;
    }

    return l_pSearcher;
}

