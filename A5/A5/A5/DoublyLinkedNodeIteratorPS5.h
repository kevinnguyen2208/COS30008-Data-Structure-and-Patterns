#pragma once

#include "DoublyLinkedNode.h"

template< class DataType >
class DoublyLinkedNodeIterator {
private:
    enum IteratorStates {
        BEFORE, DATA, AFTER
    };

    IteratorStates fState;

    typedef DoublyLinkedNode< DataType > Node;

    const Node *fLeftmost;
    const Node *fRightmost;
    const Node *fCurrent;

public:
    typedef DoublyLinkedNodeIterator< DataType > Iterator;

    DoublyLinkedNodeIterator(const Node &aList)
    {
        fLeftmost = &aList;
        while (&fLeftmost->getPrevious() != &Node::NIL)
            fLeftmost = &fLeftmost->getPrevious();
        fCurrent = fLeftmost;
        fRightmost = &aList;
        while (&fRightmost->getNext() != &Node::NIL)
            fRightmost = &fRightmost->getNext();

        fState = (fCurrent != &Node::NIL) ? DATA : AFTER;

    }

    const DataType &operator*() const    // dereference
    {
        return fCurrent->getValue();
    }

    Iterator &operator++()                // prefix increment
    {
        if (fState == BEFORE)
            fCurrent = fLeftmost;
        else if (fState == DATA)
            fCurrent = &fCurrent->getNext();
        if (fCurrent == &Node::NIL)
            fState = AFTER;
        else
            fState = DATA;
        return *this;
    }

    Iterator operator++(int)            // postfix increment
    {
        Iterator lTemp = *this;
        ++*this;
        return lTemp;
    }

    Iterator &operator--()                // prefix decrement
    {
        if (fState == AFTER)
            fCurrent = fRightmost;
        else if (fState == DATA)
            fCurrent = &fCurrent->getPrevious();
        if (fCurrent == &Node::NIL)
            fState = BEFORE;
        else
            fState = DATA;
        return *this;
    }

    Iterator operator--(int)            // postfix decrement
    {
        Iterator lTemp = *this;
        --*this;
        return lTemp;
    }


    bool operator==(const Iterator &aOtherIter) const
    {
        return (fCurrent == aOtherIter.fCurrent) &&
            (fLeftmost == aOtherIter.fLeftmost) &&
            (fRightmost == aOtherIter.fRightmost) &&
            (fState == aOtherIter.fState);
    }

    bool operator!=(const Iterator &aOtherIter) const
    {
        return !(*this == aOtherIter);
    }

    Iterator begin() const
    {
        Iterator lBegin = rend();
        ++lBegin;
        return lBegin;
    }

    Iterator end() const
    {
        Iterator lEnd = *this;
        lEnd.fCurrent = &Node::NIL;
        lEnd.fState = AFTER;
        return lEnd;
    }

    Iterator rbegin() const
    {
        Iterator lRBegin = end();
        lRBegin--;
        return lRBegin;
    }

    Iterator rend() const
    {
        Iterator lREnd = *this;
        lREnd.fState = BEFORE;
        lREnd.fCurrent = &Node::NIL;
        return lREnd;
    }
};
