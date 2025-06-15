#include <iostream>
#include <fstream>
#include <vector>
#include "MemoryManager.h"

int main()
{
    int numPages, numFrames;

    std::cout << "Enter number of virtual pages: ";
    std::cin >> numPages;

    std::cout << "Enter number of physical frames: ";
    std::cin >> numFrames;

    MemoryManager memManager(numPages, numFrames);

    std::cout << "Enter reference string length: ";
    int length;
    std::cin >> length;

    std::vector<int> referenceString(length);

    std::cout << "Enter reference string (space-separated page numbers): ";
    for (int i = 0; i < length; i++)
    {
        std::cin >> referenceString[i];
        if (referenceString[i] < 0 || referenceString[i] >= numPages)
        {
            std::cerr << "Invalid page number: " << referenceString[i] << std::endl;
            return 1;
        }
    }

    // Simulate accesses
    for (int page : referenceString)
    {
        bool fault = memManager.accessPage(page);
        std::cout << "Accessing page " << page << (fault ? " - Page Fault!" : " - Hit") << std::endl;
    }

    memManager.printStats();

    return 0;
}
