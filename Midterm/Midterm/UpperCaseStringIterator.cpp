//
//  UpperCaseStringIterator.cpp
//  Midterm
//
//  Created by Kevin Nguyen on 6/5/20.
//  Copyright © 2020 Kevin Nguyen. All rights reserved.
//

#include "UpperCaseStringIterator.h"
#include "UpperCaseString.h"

UpperCaseStringIterator::UpperCaseStringIterator( const UpperCaseString& aString, int aStart) : fString(aString)
{
    fIndex = aStart;
}

const char UpperCaseStringIterator::operator*() const
{
    return fString[fIndex];
}

UpperCaseStringIterator UpperCaseStringIterator::operator--()
{
    fIndex--;
    return *this;
}

UpperCaseStringIterator UpperCaseStringIterator::operator++(int)
{
      UpperCaseStringIterator result = *this;
      fIndex++;
      return result;
}

bool UpperCaseStringIterator::operator==(const UpperCaseStringIterator& aOther) const
{
    bool result = true;

    for (int i = 0; i < fString.size(); i++)
    {
        if (operator*() != aOther.operator*())
        {
            result = false;
        }
    }
    return result;
}

bool UpperCaseStringIterator::operator!=( const UpperCaseStringIterator& aOther) const
{
    return (!operator==(aOther));
}

UpperCaseStringIterator UpperCaseStringIterator::begin() const
{
    return fString.begin();
}

UpperCaseStringIterator UpperCaseStringIterator::end() const
{
    return fString.end();
}

UpperCaseStringIterator UpperCaseStringIterator::rbegin() const
{
    return fString.rbegin();
}

UpperCaseStringIterator UpperCaseStringIterator::rend() const
{
    return fString.rend();
}

