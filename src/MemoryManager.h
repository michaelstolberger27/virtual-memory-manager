#ifndef MEMORYMANAGER_H
#define MEMORYMANAGER_H

#include <vector>
#include <queue>
#include <unordered_map>

class MemoryManager
{
public:
    MemoryManager(int numPages, int numFrames);

    bool accessPage(int pageNumber); // returns true if page fault occurred
    void printStats() const;

private:
    int numPages;  // virtual pages
    int numFrames; // physical frames

    std::vector<int> pageTable;  // stores frame number or -1 if not loaded
    std::queue<int> fifoQueue;   // for FIFO replacement
    std::vector<bool> frameUsed; // which frames are occupied

    int pageFaults;
    int accesses;

    int findFreeFrame();
    int evictFrameFIFO();
};

#endif
