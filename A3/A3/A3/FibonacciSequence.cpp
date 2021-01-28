#include "FibonacciSequence.h"
#include "FibonacciSequenceIterator.h"
#include <stdexcept>  


FibonacciSequence::FibonacciSequence(unsigned long aLimit)
{
    fLimit = aLimit;
    fPrevious = 0;
    fCurrent = 1;
    fPosition = 1;
}


const unsigned long& FibonacciSequence::current() const
{
    return fCurrent;
}


void FibonacciSequence::advance()
{
    unsigned long next = fCurrent + fPrevious;
    fPrevious = fCurrent;
    fCurrent = next;
    if (fLimit < fPosition)
    {
        throw std::out_of_range("Limit exceeded, please try again");
    }
    fPosition++;
}


const unsigned long& FibonacciSequence::getLimit() const
{
    return fLimit;
}


FibonacciSequenceIterator FibonacciSequence::begin()
{
    *this = FibonacciSequence(getLimit());
    return FibonacciSequenceIterator(*this, 1);
}


FibonacciSequenceIterator FibonacciSequence::end()
{
    return FibonacciSequenceIterator(*this, getLimit()+1);
}
