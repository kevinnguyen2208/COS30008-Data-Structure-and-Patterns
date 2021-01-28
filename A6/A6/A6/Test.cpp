
#include <iostream>
#include "Test.h"
#include "Stack.h"
#include "DoublyLinkedNodeIterator.h"


using namespace std;
typedef DoublyLinkedNodeIterator<string> Iterator;


void resetStack(Stack<string> &aStack)
{
    aStack = Stack<string>();
    aStack.push("AAAA");
    aStack.push("BBBB");
    aStack.push("CCCC");
    aStack.push("DDDD");
}



void resetList(List<string> &aList)
{
    aList = List<string>();

    string s1("AAAA");
    string s2("BBBB");
    string s3("CCCC");
    string s4("DDDD");

    aList.push_front(s4);
    aList.push_front(s3);
    aList.push_front(s2);
    aList.push_front(s1);
}



//--------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------



void test()
{
    cout << "\n\n\n\n\n-----------------------------------------------------------------------------\nTESTING!!!!" << endl;

    cout << "\n\n-----------------------------------------------------------------------------" << endl;
    cout << "----------------         STARTING LIST TESTS             -------------------" << endl;
    cout << "-----------------------------------------------------------------------------\n" << endl;
    listTests();
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "-----------------         END OF LIST TESTS             --------------------" << endl;
    cout << "-----------------------------------------------------------------------------" << endl;

    cout << "\n\n-----------------------------------------------------------------------------" << endl;
    cout << "----------------         STARTING STACK TESTS             -------------------" << endl;
    cout << "-----------------------------------------------------------------------------\n" << endl;
    stackTests();
    cout << "-----------------------------------------------------------------------------" << endl;
    cout << "-----------------         END OF STACK TESTS             -------------------" << endl;
    cout << "-----------------------------------------------------------------------------" << endl;

    cout << "\n\n-----------------------------------------------------------------------------\n" << endl;
}







//--------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------




void stackTests()
{
    Stack<string> lStack;
    Stack<string> lStack2;
    bool lFailed;


    //----------------------------------------------------------------------------
    cout << "Test 1\nChecking if count is correct" << endl;

    resetStack(lStack);
    lFailed = false;

    if (lStack.size() != 4 && !lFailed)
    {
        cout << "--- Error: size is '" << lStack.size() << "' instead of '4'" << endl;
        lFailed = true;
    }

    lStack.pop();
    if (lStack.size() != 3 && !lFailed)
    {
        cout << "--- Error: size is '" << lStack.size() << "' instead of '3'" << endl;
        lFailed = false;
    }

    lStack.pop();
    if (lStack.size() != 2 && !lFailed)
    {
        cout << "--- Error: size is '" << lStack.size() << "' instead of '2'" << endl;
        lFailed = true;
    }

    lStack.pop();
    if (lStack.size() != 1 && !lFailed)
    {
        cout << "--- Error: size is '" << lStack.size() << "' instead of '1'" << endl;
        lFailed = true;
    }

    lStack.pop();
    if (lStack.size() != 0 && !lFailed)
    {
        cout << "--- Error: size is '" << lStack.size() << "' instead of '0'" << endl;
        lFailed = true;
    }

    cout << "Result: " << (lFailed ? "Failed!" : "Successful!") << "\n\n" << endl;

    //----------------------------------------------------------------------------

    cout << "Test 2\nChecking if empty is correct" << endl;

    resetStack(lStack);


    lFailed = false;

    if (lStack.isEmpty())
    {
        cout << "--- Error: Stack is returning true for empty when '4' nodes should be in stack" << endl;
        lFailed = true;
    }

    lStack.pop();
    if (lStack.isEmpty() && !lFailed)
    {
        cout << "--- Error: Stack is returning true for empty when '3' nodes should be in stack" << endl;
        lFailed = true;
    }

    lStack.pop();
    if (lStack.isEmpty() && !lFailed)
    {
        cout << "--- Error: Stack is returning true for empty when '2' nodes should be in stack" << endl;
        lFailed = true;
    }

    lStack.pop();
    if (lStack.isEmpty() && !lFailed)
    {
        cout << "--- Error: Stack is returning true for empty when '1' nodes should be in stack" << endl;
        lFailed = true;
    }

    lStack.pop();
    if (!lStack.isEmpty() && !lFailed)
    {
        cout << "--- Error: Stack is returning flase for empty when '0' nodes should be in stack" << endl;
        lFailed = true;
    }


    cout << "Result: " << (lFailed ? "Failed!" : "Successful!") << "\n\n" << endl;

    //----------------------------------------------------------------------------

    cout << "Test 3\nChecking if = operation is correct" << endl;

    resetStack(lStack);

    lFailed = false;
    lStack2 = lStack;

    if (lStack.size() != lStack2.size())
    {
        cout << "--- Error: Stack copy is not the same size as original stack" << endl;
        lFailed = true;
    }

    lStack.pop();
    lStack.pop();

    if (lStack.size() == lStack2.size() && !lFailed)
    {
        cout << "--- Error: Stack copy is the same size as original stack when it should have 4 nodes, while the original has 2" << endl;
        lFailed = true;
    }


    lStack.pop();
    lStack.pop();


    if (lStack.size() == lStack2.size() && !lFailed)
    {
        cout << "--- Error: Stack copy is the same size as original stack when it should have 4 nodes, while the original has 0" << endl;
        lFailed = true;
    }


    try
    {
        string test = lStack2[3];

        if (test != "AAAA")
        {
            cout << "--- Error: Stack copy contains '" << test << "' instead of 'AAAA' in the 4th node" << endl;
            lFailed = true;
        }

        test = lStack2[2];

        if (test != "BBBB")
        {
            cout << "--- Error: Stack copy contains '" << test << "' instead of 'BBBB' in the 3rd node" << endl;
            lFailed = true;
        }

        test = lStack2[1];

        if (test != "CCCC")
        {
            cout << "--- Error: Stack copy contains '" << test << "' instead of 'CCCC' in the 2nd node" << endl;
            lFailed = true;
        }

        test = lStack2[0];

        if (test != "DDDD")
        {
            cout << "--- Error: Stack copy contains '" << test << "' instead of 'DDDD' in the 1st node" << endl;
            lFailed = true;
        }

    }
    catch (const std::exception& ex)
    {
        cout << "--- Error: Stack copy contains crashed in the try" << endl;
        cout << "---- Error Details: " << ex.what() << endl;
        lFailed = true;
    }


    cout << "Result: " << (lFailed ? "Failed!" : "Successful!") << "\n\n" << endl;


    //----------------------------------------------------------------------------

    cout << "Test 4\nChecking if [] operator is correct" << endl;

    resetStack(lStack);

    lFailed = false;


    try
    {
        string test = lStack[0];
        test = lStack[1];
        test = lStack[2];
        test = lStack[3];
    }
    catch (const exception& ex)
    {
        cout << "--- Error: Accessing index 0 to 3 failed, this should work fine" << endl;
        cout << "---- Error Details: " << ex.what() << endl;
        lFailed = true;
    }


    try
    {
        string test = lStack[-1];

        cout << "--- Error: Accessing index -1 should fail" << endl;
        lFailed = true;
    }
    catch (const exception& ex)
    {
    }


    try
    {
        string test = lStack[4];

        cout << "--- Error: Accessing index 5 should fail" << endl;
        lFailed = true;
    }
    catch (const exception& ex)
    {
    }

    cout << "Result: " << (lFailed ? "Failed!" : "Successful!") << "\n\n" << endl;
    //----------------------------------------------------------------------------


    cout << "Test 5\nChecking begin, end and revers versions are correct" << endl;

    resetStack(lStack);
    lFailed = false;

    Iterator lIterator = lStack.begin();

    if (*lIterator != "DDDD")
    {
        cout << "--- Error: Begin should start at 'DDDD', recived '" << *lIterator << "'" << endl;
        lFailed = true;
    }

    lIterator++;
    if (*lIterator != "CCCC" && !lFailed)
    {
        cout << "--- Error: Begin should start at 'CCCC', recived '" << *lIterator << "'" << endl;
        lFailed = true;
    }

    lIterator++;
    if (*lIterator != "BBBB" && !lFailed)
    {
        cout << "--- Error: Begin should start at 'BBBB', recived '" << *lIterator << "'" << endl;
        lFailed = true;
    }

    lIterator++;
    if (*lIterator != "AAAA" && !lFailed)
    {
        cout << "--- Error: Begin should start at 'AAAA', recived '" << *lIterator << "'" << endl;
        lFailed = true;
    }

    lIterator++;
    if (*lIterator != "" && !lFailed)
    {
        cout << "--- Error: Begin should start at '', recived '" << *lIterator << "'" << endl;
        lFailed = true;
    }



    lIterator = lStack.end();
    if (*lIterator != "" && !lFailed)
    {
        cout << "--- Error: End should start at '', recived '" << *lIterator << "'" << endl;
        lFailed = true;
    }

    lIterator--;
    if (*lIterator != "AAAA" && !lFailed)
    {
        cout << "--- Error: End should start at 'AAAA', recived '" << *lIterator << "'" << endl;
        lFailed = true;
    }


    lIterator = lStack.rbegin();
    if (*lIterator != "AAAA" && !lFailed)
    {
        cout << "--- Error: rBegin should start at 'AAAA', recived '" << *lIterator << "'" << endl;
        lFailed = true;
    }

    lIterator--;
    if (*lIterator != "BBBB" && !lFailed)
    {
        cout << "--- Error: rBegin should start at 'BBBB', recived '" << *lIterator << "'" << endl;
        lFailed = true;
    }

    lIterator--;
    if (*lIterator != "CCCC" && !lFailed)
    {
        cout << "--- Error: rBegin should start at 'CCCC', recived '" << *lIterator << "'" << endl;
        lFailed = true;
    }

    lIterator--;
    if (*lIterator != "DDDD" && !lFailed)
    {
        cout << "--- Error: rBegin should start at 'DDDD', recived '" << *lIterator << "'" << endl;
        lFailed = true;
    }


    lIterator--;
    if (*lIterator != "" && !lFailed)
    {
        cout << "--- Error: rBegin should start at '', recived '" << *lIterator << "'" << endl;
        lFailed = true;
    }



    lIterator = lStack.rend();
    if (*lIterator != "" && !lFailed)
    {
        cout << "--- Error: rEnd should start at '', recived '" << *lIterator << "'" << endl;
        lFailed = true;
    }

    lIterator++;
    if (*lIterator != "DDDD" && !lFailed)
    {
        cout << "--- Error: rEnd should start at 'DDDD', recived '" << *lIterator << "'" << endl;
        lFailed = true;
    }

    cout << "Result: " << (lFailed ? "Failed!" : "Successful!") << "\n\n" << endl;
    //----------------------------------------------------------------------------


    cout << "Test 6\nChecking pop is correct" << endl;

    resetStack(lStack);
    lFailed = false;

    lStack.pop();
    lStack.pop();
    lStack.pop();
    lStack.pop();

    try
    {
        lStack.pop();
        cout << "--- Error: pop function should fail here and throw an error'" << endl;
        lFailed = true;
    }
    catch (const exception& ex)
    {

    }

    cout << "Result: " << (lFailed ? "Failed!" : "Successful!") << "\n\n" << endl;
    //----------------------------------------------------------------------------



    cout << "Test 7\nChecking push is correct" << endl;

    resetStack(lStack);
    lFailed = false;

    lStack.pop();
    
    lStack.push("ZZZZ");
    if (lStack.top() != "ZZZZ")
    {
        cout << "--- Error: 'ZZZZ' should be ontop of the stack" << endl;
        lFailed = true;
    }

    lStack.pop();
    if (lStack.top() != "CCCC" && !lFailed)
    {
        cout << "--- Error: 'CCCC' should be ontop of the stack" << endl;
        lFailed = true;
    }

    cout << "Result: " << (lFailed ? "Failed!" : "Successful!") << "\n\n" << endl;
    //----------------------------------------------------------------------------
}







//--------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------------------------------------------------------------------------------------------------------------



void listTests()
{
    List<string> lList;
    List<string> lList2;
    string s1 = "XXXX";
    string s2 = "YYYY";
    string s3 = "ZZZZ";
    bool lFailed;


    //----------------------------------------------------------------------------
    cout << "Test 1\nChecking if pushing front and back works correct" << endl;

    lFailed = false;

    lList.push_front(s3);
    lList.push_front(s2);
    lList.push_front(s1);
    
    if (lList[0] != s1)
    {
        cout << "--- Error: List index 0 is '" << lList[0] << "' instead of '" << s1 << "' in push front" << endl;
        lFailed = true;
    }

    if (lList[1] != s2 && !lFailed)
    {
        cout << "--- Error: List index 1 is '" << lList[1] << "' instead of '" << s2 << "' in push front" << endl;
        lFailed = true;
    }

    if (lList[2] != s3 && !lFailed)
    {
        cout << "--- Error: List index 2 is '" << lList[2] << "' instead of '" << s3 << "' in push front" << endl;
        lFailed = true;
    }

    lList = List<string>();

    lList.push_back(s3);
    lList.push_back(s2);
    lList.push_back(s1);


    if (lList[0] != s3)
    {
        cout << "--- Error: List index 0 is '" << lList[0] << "' instead of '" << s3 << "' in push back" << endl;
        lFailed = true;
    }

    if (lList[1] != s2 && !lFailed)
    {
        cout << "--- Error: List index 1 is '" << lList[1] << "' instead of '" << s2 << "' in push back" << endl;
        lFailed = true;
    }

    if (lList[2] != s1 && !lFailed)
    {
        cout << "--- Error: List index 2 is '" << lList[2] << "' instead of '" << s1 << "' in push back" << endl;
        lFailed = true;
    }

    cout << "Result: " << (lFailed ? "Failed!" : "Successful!") << "\n\n" << endl;


    //----------------------------------------------------------------------------
    cout << "Test 2\nChecking if list is removing correctly" << endl;

    lFailed = false;

    resetList(lList);

    lList.remove("AAAA");
    if (lList[0] != "BBBB" && lList.size() != 3)
    {
        cout << "--- Error: List remove issue, index 0 contains '" << lList[0] << "' instead of 'BBBB' - size is: '" << lList.size() << "' when should be '3'" << endl;
        lFailed = true;
    }


    lList.remove("AAAA");
    if (lList[0] != "BBBB" || lList.size() != 3)
    {
        cout << "--- Error: List remove issue, removing previously (AAAA) removed string has changes something? - size is: '" << lList.size() << "' when should be '3'" << endl;
        lFailed = true;
    }


    lList.remove("ZZZZZ");
    if (lList[0] != "BBBB" || lList.size() != 3)
    {
        cout << "--- Error: List remove issue, removing item not in list (ZZZZZ) has changed something? - size is: '" << lList.size() << "' when should be '3'" << endl;
        lFailed = true;
    }


    lList.remove("BBBB");
    if (lList[0] != "CCCC" || lList.size() != 2)
    {
        cout << "--- Error: List remove issue, index 0 contains '" << lList[0] << "' instead of 'CCCC' - size is: '" << lList.size() << "' when should be '2'" << endl;
        lFailed = true;
    }


    lList.remove("DDDD");
    if (lList[0] != "CCCC" || lList.size() != 1)
    {
        cout << "--- Error: List remove issue, index 0 contains '" << lList[0] << "' instead of 'CCCC' - size is: '" << lList.size() << "' when should be '1'" << endl;
        lFailed = true;
    }


    lList.remove("CCCC");
    if (lList.size() != 0)
    {
        cout << "--- Error: List remove issue, size is: '" << lList.size() << "' when should be '0'" << endl;
        lFailed = true;
    }


    cout << "Result: " << (lFailed ? "Failed!" : "Successful!") << "\n\n" << endl;


    //----------------------------------------------------------------------------
    cout << "Test 3\nChecking if list isEmpty return correctly" << endl;

    lFailed = false;

    resetList(lList);


    if (lList.isEmpty())
    {
        cout << "--- Error: List isEmpty returning true when should be false, there should be '4' in list" << endl;
        lFailed = true;
    }

    lList.remove("AAAA");
    if (lList.isEmpty() && !lFailed)
    {
        cout << "--- Error: List isEmpty returning true when should be false, there should be '3' in list" << endl;
        lFailed = true;
    }

    lList.remove("DDDD");
    if (lList.isEmpty() && !lFailed)
    {
        cout << "--- Error: List isEmpty returning true when should be false, there should be '2' in list" << endl;
        lFailed = true;
    }

    lList.remove("CCCC");
    if (lList.isEmpty() && !lFailed)
    {
        cout << "--- Error: List isEmpty returning true when should be false, there should be '1' in list" << endl;
        lFailed = true;
    }

    lList.remove("BBBB");
    if (!lList.isEmpty() && !lFailed)
    {
        cout << "--- Error: List isEmpty returning false when should be true, there should be '0' in list" << endl;
        lFailed = true;
    }

    cout << "Result: " << (lFailed ? "Failed!" : "Successful!") << "\n\n" << endl;
    

    //----------------------------------------------------------------------------

    cout << "Test 4\nChecking if = operation is correct" << endl;

    resetList(lList);

    lFailed = false;
    lList2 = lList;

    if (lList2.size() != lList.size())
    {
        cout << "--- Error: List = operator did not work correctly, copied list is not the same size as the original list" << endl;
        lFailed = true;
    }

    lList.remove("AAAA");
    lList.remove("CCCC");
    lList.remove("DDDD");
    lList.remove("BBBB");

    if (lList.size() == lList2.size() && !lFailed)
    {
        cout << "--- Error: List = operator did not work correctly, copied list is the same size as the original list after removing nodes" << endl;
        lFailed = true;
    }


    try
    {
        string test = lList2[0];

        if (test != "AAAA")
        {
            cout << "--- Error: List copy contains '" << test << "' instead of 'AAAA' in the 1st node" << endl;
            lFailed = true;
        }

        test = lList2[1];

        if (test != "BBBB")
        {
            cout << "--- Error: List copy contains '" << test << "' instead of 'BBBB' in the 2nd node" << endl;
            lFailed = true;
        }

        test = lList2[2];

        if (test != "CCCC")
        {
            cout << "--- Error: List copy contains '" << test << "' instead of 'CCCC' in the 3rd node" << endl;
            lFailed = true;
        }

        test = lList2[3];

        if (test != "DDDD")
        {
            cout << "--- Error: List copy contains '" << test << "' instead of 'DDDD' in the 4th node" << endl;
            lFailed = true;
        }

    }
    catch (const std::exception& ex)
    {
        cout << "--- Error: List copy contains crashed in the try" << endl;
        cout << "---- Error Details: " << ex.what() << endl;
        lFailed = true;
    }


    cout << "Result: " << (lFailed ? "Failed!" : "Successful!") << "\n\n" << endl;


    //----------------------------------------------------------------------------


    cout << "Test 5\nChecking if [] operator is correct" << endl;

    resetList(lList);
    lFailed = false;


    try
    {
        string test = lList[0];
        test = lList[1];
        test = lList[2];
        test = lList[3];
    }
    catch (const exception& ex)
    {
        cout << "--- Error: Accessing index 0 to 3 failed, this should work fine" << endl;
        cout << "---- Error Details: " << ex.what() << endl;
        lFailed = true;
    }


    try
    {
        string test = lList[-1];

        cout << "--- Error: Accessing index -1 should fail" << endl;
        lFailed = true;
    }
    catch (const exception& ex)
    {
    }


    try
    {
        string test = lList[4];

        cout << "--- Error: Accessing index 5 should fail" << endl;
        lFailed = true;
    }
    catch (const exception& ex)
    {
    }

    cout << "Result: " << (lFailed ? "Failed!" : "Successful!") << "\n\n" << endl;
    //----------------------------------------------------------------------------


    cout << "Test 6\nChecking begin, end and revers versions are correct" << endl;

    resetList(lList);
    lFailed = false;

    Iterator lIterator = lList.begin();

    if (*lIterator != "AAAA")
    {
        cout << "--- Error: Begin should start at 'AAAA', recived '" << *lIterator << "'" << endl;
        lFailed = true;
    }

    lIterator++;
    if (*lIterator != "BBBB" && !lFailed)
    {
        cout << "--- Error: Begin should start at 'BBBB', recived '" << *lIterator << "'" << endl;
        lFailed = true;
    }

    lIterator++;
    if (*lIterator != "CCCC" && !lFailed)
    {
        cout << "--- Error: Begin should start at 'CCCC', recived '" << *lIterator << "'" << endl;
        lFailed = true;
    }

    lIterator++;
    if (*lIterator != "DDDD" && !lFailed)
    {
        cout << "--- Error: Begin should start at 'DDDD', recived '" << *lIterator << "'" << endl;
        lFailed = true;
    }

    lIterator++;
    if (*lIterator != "" && !lFailed)
    {
        cout << "--- Error: Begin should start at '', recived '" << *lIterator << "'" << endl;
        lFailed = true;
    }



    lIterator = lList.end();
    if (*lIterator != "" && !lFailed)
    {
        cout << "--- Error: End should start at '', recived '" << *lIterator << "'" << endl;
        lFailed = true;
    }

    lIterator--;
    if (*lIterator != "DDDD" && !lFailed)
    {
        cout << "--- Error: End should start at 'DDDD', recived '" << *lIterator << "'" << endl;
        lFailed = true;
    }


    lIterator = lList.rbegin();
    if (*lIterator != "DDDD" && !lFailed)
    {
        cout << "--- Error: rBegin should start at 'DDDD', recived '" << *lIterator << "'" << endl;
        lFailed = true;
    }

    lIterator--;
    if (*lIterator != "CCCC" && !lFailed)
    {
        cout << "--- Error: rBegin should start at 'CCCC', recived '" << *lIterator << "'" << endl;
        lFailed = true;
    }

    lIterator--;
    if (*lIterator != "BBBB" && !lFailed)
    {
        cout << "--- Error: rBegin should start at 'BBBB', recived '" << *lIterator << "'" << endl;
        lFailed = true;
    }

    lIterator--;
    if (*lIterator != "AAAA" && !lFailed)
    {
        cout << "--- Error: rBegin should start at 'AAAA', recived '" << *lIterator << "'" << endl;
        lFailed = true;
    }


    lIterator--;
    if (*lIterator != "" && !lFailed)
    {
        cout << "--- Error: rBegin should start at '', recived '" << *lIterator << "'" << endl;
        lFailed = true;
    }



    lIterator = lList.rend();
    if (*lIterator != "" && !lFailed)
    {
        cout << "--- Error: rEnd should start at '', recived '" << *lIterator << "'" << endl;
        lFailed = true;
    }

    lIterator++;
    if (*lIterator != "AAAA" && !lFailed)
    {
        cout << "--- Error: rEnd should start at 'AAAA', recived '" << *lIterator << "'" << endl;
        lFailed = true;
    }

    cout << "Result: " << (lFailed ? "Failed!" : "Successful!") << "\n\n" << endl;
    //----------------------------------------------------------------------------
}
