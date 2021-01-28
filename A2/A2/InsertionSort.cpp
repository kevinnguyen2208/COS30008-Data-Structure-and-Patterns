#include "InsertionSort.h"
using namespace std;

InsertionSort::InsertionSort(int aArrayOfNumbers[], unsigned int aArraySize) : ArraySorter::ArraySorter(aArrayOfNumbers, aArraySize)
{
    
}


void InsertionSort::sort(std::ostream& aOStream)
{
    for (unsigned int i = 0; i < getRange()-1; i++)
    {
        for (unsigned int b = i+1; b > 0; b--)
        {
            if (at(b) < at(b-1))
            {
                swapElements(b, b-1);
            }
        }
        stepCompleted(aOStream);
        }
    }

