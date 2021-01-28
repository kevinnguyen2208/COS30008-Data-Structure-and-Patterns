
// COS30008, Tutorial 11, 2020

#pragma once

#include <stdexcept>

#include "TreeVistor.h"

#include "Stages.h"

template<class T, int N>
class NTree
{
private:
    T fKey;                   		// T() for empty NTree
    NTree<T,N>* fNodes[N];          // N subtrees of degree N

    NTree() : fKey(T())                        // sentinel constructor
    {
        for (int i = 0; i < N; i++)
        {
            fNodes[i] = &NIL;
        }
    }
    
public:
    static NTree<T,N> NIL;          // sentinel
    
    NTree(const T& aKey) : fKey(aKey)         // a simple NTree with key and N subtrees
    {
        for (int i = 0; i < N; i++)
        {
            fNodes[i] = &NIL;
        }
    }

    virtual ~NTree()                               // destructor
    {
        for (int i = 0; i < N; i++)
        {
            if (fNodes[i] != &NIL)
            {
                delete fNodes[i];
            }
        }
    }


    NTree(const NTree& aOtherNTree)              // copy constructor
    {
        if (&aOtherNTree == &NIL)
        { std::domain_error("Copy of NIL requested.");
        }

        throw
        fKey = aOtherNTree.fKey;

        for (int i = 0; i < N; i++)
        {
            fNodes[i] = aOtherNTree.fNodes[i]->clone();
        }
    }

    NTree& operator=(const NTree& aOtherNTree)   // assignment operator
    {
        if (&aOtherNTree == &NIL)
        {
            throw std::domain_error("Copy of NIL requested.");
        }

        if (this != &aOtherNTree)
        {
            fKey = aOtherNTree.fKey;

            for (int i = 0; i < N; i++)
            {
                if (fNodes[i] != &NIL)
                {
                    delete fNodes[i];
                }

                fNodes[i] = aOtherNTree.fNodes[i]->clone();
            }
        }

        return *this;
    }

    virtual NTree* clone()                         // clone a tree
    {
        if (!isEmpty())
        {
            return new NTree(*this);
        }
        else
        {
            return this;
        }
    }

    bool isEmpty() const       // is tree empty
    {
        return this == &NIL;
    }

    const T& key() const       // get key (node value)
    {
        return fKey;
    }
    
    // indexer (allow for result modification by client - no const in result)
    NTree& operator[](size_t aIndex) const
    {
        if (isEmpty())
        {
            throw std::domain_error( "NIL encountered." );
        }

        if (aIndex < N)
        {
            return *fNodes[aIndex];
        }
        else
        {
            throw std::out_of_range( "aIndex out-of-bounds." );
        }
    }
    
    // tree manipulators (using constant references)
    void attachNTree(unsigned int aIndex, const NTree<T, N>& aNTree)
    {
        if (isEmpty())
        {
            throw std::domain_error("NIL encountered.");
        }

        if (aIndex < N)
        {
            if (fNodes[aIndex] == &NIL)
            {
                fNodes[aIndex] = (NTree*)&aNTree;
            }
            else
            {
                throw std::domain_error( "Non-empty slot encountered." );
            }
        }
        else
        {
            throw std::out_of_range("aIndex out-of-bounds.");
        }
    }

    const NTree& detachNTree(unsigned int aIndex)
    {
        if (isEmpty())
        {
            throw std::domain_error("NIL encountered.");
        }

        if (aIndex < N)
        {
            if (fNodes[aIndex] != &NIL)
            {
                const NTree& lNTree = *fNodes[aIndex];

                fNodes[aIndex] = &NIL;

                return lNTree;
            }
            else
            {
                throw std::domain_error("Non-empty slot encountered.");
            }
        }
        else
        {
            throw std::out_of_range("aIndex out-of-bounds.");
        }
    }
      
#if P>=2
    // depth-first traversal
    void traverseDepthFirst( const TreeVisitor<T>& aVisitor ) const
    {
        // visit every subtree (no invisit)
        if ( !isEmpty() )
        {
            aVisitor.preVisit( key() );
            for ( unsigned int i = 0; i < N; i++ )
            {
                fNodes[i]->traverseDepthFirst( aVisitor );
            }
            aVisitor.postVisit( key() );
        }
    }
#endif
    
#if P>=3
    // breadth-first traversal
    void traverseBreadthFirst( const TreeVisitor<T>& aVisitor ) const;
#endif
};

template<class T, int N>
NTree<T,N> NTree<T, N>::NIL;
