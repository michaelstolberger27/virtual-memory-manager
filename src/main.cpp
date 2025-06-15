#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <stdexcept>

#include "MemoryManager.h"
#include "FIFOManager.h"
#include "LRUManager.h"
#include "OptimalManager.h"

std::unique_ptr<MemoryManager> createManager(const std::string &algo)
{
    if (algo == "fifo")
        return std::make_unique<FIFOManager>();
    if (algo == "lru")
        return std::make_unique<LRUManager>();
    if (algo == "optimal")
        return std::make_unique<OptimalManager>();
    throw std::runtime_error("Unknown algorithm: " + algo);
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cerr << "Usage: ./vmm_simulator <algorithm> < input.txt\n";
        std::cerr << "Available algorithms: fifo, lru, optimal" << std::endl;
        return 1;
    }

    std::string algo = argv[1];
    std::unique_ptr<MemoryManager> manager;

    try
    {
        manager = createManager(algo);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << std::endl;
        return 1;
    }

    int numPages, numFrames, refLength;
    std::cin >> numPages >> numFrames >> refLength;

    if (!std::cin)
    {
        std::cerr << "Invalid input format." << std::endl;
        return 1;
    }

    std::vector<int> referenceString(refLength);
    for (int i = 0; i < refLength; ++i)
    {
        std::cin >> referenceString[i];
        if (!std::cin)
        {
            std::cerr << "Invalid reference string input." << std::endl;
            return 1;
        }
    }

    manager->simulate(referenceString, numFrames);

    return 0;
}
