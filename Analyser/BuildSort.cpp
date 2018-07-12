#include <iostream>
#include "BuildSort.hpp"
#include "TableFactory.hpp"
#include "TblBase.hpp"

typedef std::pair<std::string, short> BuildElement;

void BuildSort::Sort(std::list<std::string>& a_rSortedList)
{
    TblBase* l_pTblBuildOrder = TableFactory::GetTable(TableID::TBLID_Build_Order);
    std::list<BuildElement> l_SortedList;

    //Create list with elements contains its build order.
    for (std::string l_Proj : a_rSortedList)
    {
        std::list<std::string> l_Values = l_pTblBuildOrder->SearchByChild(l_Proj);
        if (l_Values.size() == 1)
        {
            BuildElement l_Element;
            l_Element.first = l_Proj;
            l_Element.second = std::stoi(l_Values.front());

            l_SortedList.push_back(l_Element);
        }
        else
        {
            std::cout << "Build Order Error for Project: " << l_Proj << std::endl;
        }
    }

    //Sort the list based on its order.The smaller order number is, the higher priority the projs is in.
    l_SortedList.sort([](const BuildElement& a_rElement1, const BuildElement& a_rElement2) { return a_rElement1.second > a_rElement2.second; });

    //Get the sorted project list.
    if (l_SortedList.size() > 0)
    {
        a_rSortedList.clear();

        for (BuildElement l_Element : l_SortedList)
        {
            a_rSortedList.push_back(l_Element.first);
        }
    }
}

