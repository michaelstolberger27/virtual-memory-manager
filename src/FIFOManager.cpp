#include "FIFOManager.h"
#include <iostream>
#include <queue>
#include <unordered_set>

void FIFOManager::simulate(const std::vector<int> &referenceString, int numFrames)
{
    std::queue<int> fifoQueue;
    std::unordered_set<int> memory;

    int pageFaults = 0;

    for (int page : referenceString)
    {
        std::cout << "Accessing page " << page << " - ";

        if (memory.find(page) == memory.end())
        {
            // Page fault
            pageFaults++;
            std::cout << "Page Fault!" << std::endl;

            if ((int)memory.size() == numFrames)
            {
                int oldest = fifoQueue.front();
                fifoQueue.pop();
                memory.erase(oldest);
            }
            memory.insert(page);
            fifoQueue.push(page);
        }
        else
        {
            // Page hit
            std::cout << "Hit" << std::endl;
        }
    }

    std::cout << "Total memory accesses: " << referenceString.size() << std::endl;
    std::cout << "Total page faults: " << pageFaults << std::endl;
    std::cout << "Page fault rate: " << 100.0 * pageFaults / referenceString.size() << "%" << std::endl;
}
