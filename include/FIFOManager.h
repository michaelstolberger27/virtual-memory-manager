#ifndef FIFO_MANAGER_H
#define FIFO_MANAGER_H

#include "MemoryManager.h"

class FIFOManager : public MemoryManager
{
public:
    void simulate(const std::vector<int> &referenceString, int numFrames) override;
};

#endif
