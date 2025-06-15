#ifndef OPTIMAL_MANAGER_H
#define OPTIMAL_MANAGER_H

#include "MemoryManager.h"

class OptimalManager : public MemoryManager
{
public:
    void simulate(const std::vector<int> &referenceString, int numFrames) override;
};

#endif
