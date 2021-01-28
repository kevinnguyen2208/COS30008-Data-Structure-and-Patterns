#include "SelectionSort.h"

using namespace std;


SelectionSort::SelectionSort(int aArrayOfNumbers[], unsigned int aArraySize): ArraySorter::ArraySorter(aArrayOfNumbers, aArraySize)
{
    
}

void SelectionSort::sort(std::ostream& aOStream)
{
    for (unsigned int i = 0; i < getRange() - 1; i++)
    {
        unsigned int b = i;
        for (unsigned int a = i + 1; a < getRange(); a++)
        {
            if (at(a) < at(b))
            {
                b = a;
            }
        }
         swapElements(i, b);
         stepCompleted(aOStream);
    }
}

