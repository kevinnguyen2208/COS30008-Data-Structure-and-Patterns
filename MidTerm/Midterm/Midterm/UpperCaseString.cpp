
// COS30008, Midterm, 2020

#include "UpperCaseString.h"
#include "UpperCaseStringIterator.h"

#include <cctype>
#include <stdexcept>

using namespace std;

UpperCaseString::UpperCaseString( const char* aInitialValue )
{
    // a C-string contains at least one character: '\0'.
    size_t lLength = 1;
    
    // compute the length + 1 of aInitialValue
    for ( int i = 0; aInitialValue[i] != '\0'; i++ )
    {
        lLength++;
    }

    // allocate memory
    fValue = new char[lLength];
    
    // copy aInitialValue to fValue and make it upper case
    for ( int i = 0; i < lLength; i++ )
    {
        fValue[i] = toupper( aInitialValue[i] );
    }
}

UpperCaseString::~UpperCaseString()
{
    delete[] fValue;
}

int UpperCaseString::size() const
{
    int lSize = 0;
    for (int i=0; fValue[i] != '\0'; i++)
    {
        lSize++;
    }
    return lSize;
}

const char UpperCaseString::operator[](int aIndex) const
{
    return fValue[aIndex];
}


UpperCaseStringIterator UpperCaseString::begin() const
{
    return UpperCaseStringIterator(*this, 0);
}

UpperCaseStringIterator UpperCaseString::end() const
{
    return UpperCaseStringIterator(*this, size());
}

UpperCaseStringIterator UpperCaseString::rbegin() const
{
    return UpperCaseStringIterator(*this, size() - 1);
}

UpperCaseStringIterator UpperCaseString::rend() const
{
    return UpperCaseStringIterator(*this, -1);
}

std::ostream& operator<<(std::ostream& aOStream, const UpperCaseString& aString)
{
    for (int i=0; aString.fValue[i] != '\0'; i++ )
    {  
        aOStream << aString.fValue[i];
    }
    return aOStream;
}
