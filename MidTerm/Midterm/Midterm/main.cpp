
// COS30008, Midterm, 2020

#include "UpperCaseString.h"
#include "UpperCaseStringIterator.h"

using namespace std;

int main()
{
    UpperCaseString s( "Able was I I saw Elba" );

    cout << "The string: \"" << s << "\" with size: " << s.size() << endl;

    bool lPalindrome = true;
    
    UpperCaseStringIterator move_to_right = s.begin();
    UpperCaseStringIterator move_to_left  = s.rbegin();
    UpperCaseStringIterator past_left     = s.end();

    while (lPalindrome && move_to_left != past_left)
    {
        if (move_to_right++ != move_to_left)
        {
            lPalindrome = false;
            
        }
        --move_to_left;
    }

    if ( lPalindrome )
        cout << "We have found a palindrome!" << endl;
    else
        cout << "Oops, no palindrome." << endl;

    return 0;
}
