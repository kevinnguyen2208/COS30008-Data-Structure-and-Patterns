
// COS30008, Final Exam, 2020

#pragma once

#include <stdexcept>
#include "TreeVisitor.h"
    
#ifdef P3
#include "LinearVisitor.h"
#endif

template<class T>
class TTree
{
private:
    
    T fKey;
    TTree<T>* fLeft;
    TTree<T>* fMiddle;
    TTree<T>* fRight;
    
    TTree() : fKey()        // use default constructor to initialize fKey
    {
        fLeft = &NIL;       // loop-back: The sub-trees of a TTree object with
        fMiddle = &NIL;     //            no children point to NIL.
        fRight = &NIL;
    }
    
    void addSubTree( TTree<T>** aBranch, const TTree<T>& aTTree )
    {
        if ( *aBranch != &NIL )
        {
            delete *aBranch;
        }

        *aBranch = (TTree<T>*)&aTTree;
    }

    const TTree<T>& removeSubTree( TTree<T>** aBranch )
    {
        if ( *aBranch == &NIL)
        {
            throw std::domain_error("Empty TTree");
        }
        else
        {
            const TTree<T>& tree = **aBranch;
            *aBranch = &NIL;
            return tree;
        }
    }
    
public:

    static TTree<T> NIL;    // sentinel

    // TTree constructor (takes one argument)
    TTree( const T& aKey ) : fKey (aKey)
    {
        fLeft = &NIL;
        fMiddle = &NIL;
        fRight = &NIL;
    }
    
    // destructor (free sub-trees, must not free empty TTree)
    ~TTree()
    {
        if ( fLeft != &NIL )
        {
            delete fLeft;
        }
        if ( fMiddle != &NIL )
        {
            delete fMiddle;
        }
        if ( fRight != &NIL )
        {
            delete fRight;
        }
    }
    
    // copy constructor, must not copy empty TTree
    TTree( const TTree<T>& aOtherTTree )
    {
        if (&aOtherTTree == &NIL)
        {
            throw std::domain_error("Copying NIL.");
        }

        fKey = aOtherTTree.fKey;

        fLeft = aOtherTTree.fLeft->clone();
        fMiddle = aOtherTTree.fMiddle->clone();
        fRight = aOtherTTree.fRight->clone();

    }
    
    // assignment operator, must not copy empty TTree
    TTree<T>& operator=( const TTree<T>& aOtherTTree )
    {
        if (&aOtherTTree == &NIL)
        {
            throw std::domain_error("Copying NIL.");
        }
        if (this != &aOtherTTree)
        {
            fKey = aOtherTTree.fKey;

            if (!isEmpty())
            {
                delete fLeft;
                delete fMiddle;
                delete fRight;
            }
            fLeft = aOtherTTree.fLeft->clone();
            fMiddle = aOtherTTree.fMiddle->clone();
            fRight = aOtherTTree.fRight->clone();
        }
        return *this;
    }
    
    // clone TTree, must not copy empty TTree
    TTree<T>* clone() const
    {
        if ( this == &NIL )
        {
            return &NIL;
        }
        else
        {
            return new TTree( *this );
        }
    }

    // return key value, may throw domain_error if empty
    const T& getKey() const
    {
       if (isEmpty())
        {
            throw std::domain_error("Empty TTree encountered.");
        }
        else
        {
            return fKey;
        }
    }

    // returns true if this TTree is empty
    bool isEmpty() const
    {
        return this == &NIL;
    }
    
    // getters for subtrees
    const TTree<T>& getLeft() const
    {
         if (isEmpty())
         {
             throw std::domain_error("Empty TTree");
         }
         else
         {
             return *fLeft;
         }
    }
    
    const TTree<T>& getMiddle() const
    {
        if (isEmpty())
        {
            throw std::domain_error("Empty TTree");
        }
        else
        {
            return *fMiddle;
        }
    }
    
    const TTree<T>& getRight() const
    {
        if (isEmpty())
        {
            throw std::domain_error("Empty TTree");
        }
        else
        {
            return *fRight;
        }
    }

    // add a subtree
    void addLeft( const TTree<T>& aTTree )
    {
        addSubTree( &fLeft, aTTree );
    }
    
    void addMiddle( const TTree<T>& aTTree )
    {
        addSubTree( &fMiddle, aTTree );
    }
    
    void addRight( const TTree<T>& aTTree )
    {
        addSubTree( &fRight, aTTree );
    }
        
    // remove a subtree, may through a domain error
    const TTree<T>& removeLeft()
    {
        if (isEmpty())
        {
            throw std::domain_error("Error removing.");
        }
        else
        {
            return removeSubTree(&fLeft);
        }
    }
    
    const TTree<T>& removeMiddle()
    {
        if (isEmpty())
        {
            throw std::domain_error("Error removing.");
        }
        else
        {
            return removeSubTree(&fMiddle);
        }
    }
    
    const TTree<T>& removeRight()
    {
        if (isEmpty())
        {
            throw std::domain_error("Error removing.");
        }
        else
        {
            return removeSubTree(&fRight);
        }
    }
    
    void traverseDepthFirst( TreeVisitor<T>& aVisitor ) const
    {
        if(!isEmpty())
        {
            aVisitor.preVisit(getKey());

            getLeft().traverseDepthFirst(aVisitor);
            getMiddle().traverseDepthFirst(aVisitor);
            getRight().traverseDepthFirst(aVisitor);

            aVisitor.postVisit(getKey());
        }
        else
        {
            aVisitor.emitNIL();
        }
    }
    
};

template<class T>
TTree<T>  TTree<T>::NIL;
