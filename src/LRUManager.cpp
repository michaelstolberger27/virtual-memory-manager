#include "LRUManager.h"
#include <iostream>
#include <list>
#include <unordered_map>

void LRUManager::simulate(const std::vector<int> &referenceString, int numFrames)
{
    std::list<int> lruList;
    std::unordered_map<int, std::list<int>::iterator> pageMap;

    int pageFaults = 0;

    for (int page : referenceString)
    {
        std::cout << "Accessing page " << page << " - ";

        if (pageMap.find(page) == pageMap.end())
        {
            // Page fault
            pageFaults++;
            std::cout << "Page Fault!" << std::endl;

            if ((int)lruList.size() == numFrames)
            {
                int lruPage = lruList.back();
                lruList.pop_back();
                pageMap.erase(lruPage);
            }
        }
        else
        {
            // Page hit: move page to front
            lruList.erase(pageMap[page]);
            std::cout << "Hit" << std::endl;
        }

        lruList.push_front(page);
        pageMap[page] = lruList.begin();
    }

    std::cout << "Total memory accesses: " << referenceString.size() << std::endl;
    std::cout << "Total page faults: " << pageFaults << std::endl;
    std::cout << "Page fault rate: " << 100.0 * pageFaults / referenceString.size() << "%" << std::endl;
}
