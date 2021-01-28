#include "FibonacciSequenceIterator.h"
#include "FibonacciSequence.h"


FibonacciSequenceIterator::FibonacciSequenceIterator(FibonacciSequence& aSequenceObject, unsigned long aStart) : fSequenceObject(aSequenceObject), fIndex(aStart)
{}


const unsigned long& FibonacciSequenceIterator::operator*() const
{
    return fSequenceObject.current();
}


FibonacciSequenceIterator& FibonacciSequenceIterator::operator++()
{
    fSequenceObject.advance();
    fIndex++;
    return *this;
}


FibonacciSequenceIterator FibonacciSequenceIterator::operator++(int)
{
      FibonacciSequenceIterator temp = *this;
      fSequenceObject.advance();
      fIndex++;
      return temp;
}


bool FibonacciSequenceIterator::operator==(const FibonacciSequenceIterator& aOther) const
{
    return (fIndex == aOther.fIndex)
&& fSequenceObject.current() == aOther.fSequenceObject.current()
            && fSequenceObject.getLimit() == aOther.fSequenceObject.getLimit();
}


bool FibonacciSequenceIterator::operator!=(const FibonacciSequenceIterator& aOther) const
{
    return !(*this == aOther);
}


FibonacciSequenceIterator FibonacciSequenceIterator::begin() const
{
    return fSequenceObject.begin();
}


FibonacciSequenceIterator FibonacciSequenceIterator::end() const
{
    return fSequenceObject.end();
}
