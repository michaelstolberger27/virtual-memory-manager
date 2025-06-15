#include "OptimalManager.h"
#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <climits>

void OptimalManager::simulate(const std::vector<int> &ref, int frames)
{
    std::set<int> memory;
    int pageFaults = 0;

    for (size_t i = 0; i < ref.size(); ++i)
    {
        int page = ref[i];
        std::cout << "Accessing page " << page << " - ";

        if (memory.find(page) != memory.end())
        {
            std::cout << "Hit" << std::endl;
            continue;
        }

        // Page fault
        pageFaults++;
        std::cout << "Page Fault!" << std::endl;

        if ((int)memory.size() < frames)
        {
            memory.insert(page);
        }
        else
        {
            // Find the page in memory that is used farthest in the future or not at all
            std::unordered_map<int, int> nextUse;
            for (int p : memory)
                nextUse[p] = INT_MAX;

            for (size_t j = i + 1; j < ref.size(); ++j)
            {
                if (nextUse.find(ref[j]) != nextUse.end() && nextUse[ref[j]] == INT_MAX)
                {
                    nextUse[ref[j]] = j;
                }
            }

            int toRemove = -1;
            int farthest = -1;
            for (auto &pair : nextUse)
            {
                if (pair.second > farthest)
                {
                    farthest = pair.second;
                    toRemove = pair.first;
                }
            }

            memory.erase(toRemove);
            memory.insert(page);
        }
    }

    std::cout << "Total memory accesses: " << ref.size() << std::endl;
    std::cout << "Total page faults: " << pageFaults << std::endl;
    std::cout << "Page fault rate: " << 100.0 * pageFaults / ref.size() << "%" << std::endl;
}
