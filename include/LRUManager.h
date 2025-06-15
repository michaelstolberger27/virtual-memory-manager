#ifndef LRU_MANAGER_H
#define LRU_MANAGER_H

#include "MemoryManager.h"

class LRUManager : public MemoryManager
{
public:
    void simulate(const std::vector<int> &referenceString, int numFrames) override;
};

#endif
