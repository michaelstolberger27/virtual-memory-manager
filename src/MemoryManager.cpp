#include "MemoryManager.h"
#include <iostream>

MemoryManager::MemoryManager(int numPages, int numFrames)
    : numPages(numPages), numFrames(numFrames), pageFaults(0), accesses(0)
{
    pageTable.resize(numPages, -1);
    frameUsed.resize(numFrames, false);
}

int MemoryManager::findFreeFrame()
{
    for (int i = 0; i < numFrames; i++)
    {
        if (!frameUsed[i])
            return i;
    }
    return -1; // no free frame
}

int MemoryManager::evictFrameFIFO()
{
    int victimPage = fifoQueue.front();
    fifoQueue.pop();

    int frame = pageTable[victimPage];
    pageTable[victimPage] = -1; // invalidate victim's page table entry

    return frame;
}

bool MemoryManager::accessPage(int pageNumber)
{
    accesses++;

    if (pageTable[pageNumber] != -1)
    {
        // Page is in memory — no page fault
        return false;
    }

    // Page fault occurs
    pageFaults++;

    int frame = findFreeFrame();

    if (frame == -1)
    {
        // No free frame, evict using FIFO
        frame = evictFrameFIFO();
    }

    // Load the page into the frame
    pageTable[pageNumber] = frame;
    frameUsed[frame] = true;

    fifoQueue.push(pageNumber);

    return true;
}

void MemoryManager::printStats() const
{
    std::cout << "Total memory accesses: " << accesses << "\n";
    std::cout << "Total page faults: " << pageFaults << "\n";
    std::cout << "Page fault rate: " << ((double)pageFaults / accesses) * 100 << "%\n";
}
