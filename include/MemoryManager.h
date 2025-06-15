#ifndef MEMORY_MANAGER_H
#define MEMORY_MANAGER_H

#include <vector>

class MemoryManager
{
public:
    virtual void simulate(const std::vector<int> &referenceString, int numFrames) = 0;
    virtual ~MemoryManager() {}
};

#endif
