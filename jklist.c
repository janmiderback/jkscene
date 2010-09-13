/*
Copyright (c) 2010 Jan Miderbaeck and Karim Benchemsi

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
*/

#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "jklist.h"

////////////////////////////////////////////////////////////////////////////////

void jklist_init( JKList *pSelf, size_t elementSize )
{
    assert( pSelf != NULL );

    pSelf->elementSize = elementSize;
    pSelf->pNIL = malloc( sizeof( JKListNode ) );
    assert( pSelf->pNIL != NULL );
    pSelf->pNIL->pPrev = pSelf->pNIL;
    pSelf->pNIL->pNext = pSelf->pNIL;
    pSelf->pNIL->pElement = NULL;
    pSelf->count = 0;
}

////////////////////////////////////////////////////////////////////////////////

void jklist_deinit( JKList *pSelf )
{
    if( pSelf != NULL )
    {
        jklist_clear( pSelf );
        free( pSelf->pNIL );
    }
}

////////////////////////////////////////////////////////////////////////////////

void jklist_insertFirst( JKList *pSelf, void *pElement )
{
    JKListNode *pNewNode;

    assert( pSelf != NULL );

    pNewNode = malloc( sizeof( JKListNode ) );
    assert( pNewNode != NULL );

    pNewNode->pElement = malloc( pSelf->elementSize );
    assert( pNewNode->pElement != NULL );

    memcpy( pNewNode->pElement, pElement, pSelf->elementSize );
    
    pNewNode->pPrev = pSelf->pNIL;
    pNewNode->pNext = pSelf->pNIL->pNext;
    pSelf->pNIL->pNext->pPrev = pNewNode;
    pSelf->pNIL->pNext = pNewNode;
    
    pSelf->count++;
}

////////////////////////////////////////////////////////////////////////////////

void jklist_insertLast( JKList *pSelf, void *pElement )
{
    JKListNode *pNewNode;

    assert( pSelf != NULL );

    pNewNode = malloc( sizeof( JKListNode ) );
    assert( pNewNode != NULL );
    pNewNode->pElement = pElement;

    pNewNode->pPrev = pSelf->pNIL->pPrev;
    pNewNode->pNext = pSelf->pNIL;
    pSelf->pNIL->pPrev->pNext = pNewNode;
    pSelf->pNIL->pPrev = pNewNode;
    
    pSelf->count++;
}

////////////////////////////////////////////////////////////////////////////////

void jklist_removeFirst( JKList *pSelf )
{
    JKListNode *pFirstNode;

    assert( pSelf != NULL );

    if( pSelf->count != 0 )
    {
        pFirstNode = pSelf->pNIL->pNext;
        pFirstNode->pNext->pPrev = pFirstNode->pPrev;
        pSelf->pNIL->pNext = pFirstNode->pNext;
        
        free( pFirstNode->pElement );
        free( pFirstNode );
        pSelf->count--;
    }
}

////////////////////////////////////////////////////////////////////////////////

void jklist_removeLast( JKList *pSelf )
{
    JKListNode *pLastNode;

    assert( pSelf != NULL );

    if( pSelf->count != 0 )
    {
        pLastNode = pSelf->pNIL->pPrev;
        pLastNode->pPrev->pNext = pLastNode->pNext;
        pSelf->pNIL->pPrev = pLastNode->pPrev;
        
        free( pLastNode->pElement );
        free( pLastNode );
        pSelf->count--;
    }    
}

////////////////////////////////////////////////////////////////////////////////

//int jklist_remove( JKList *pSelf, void *pElement )
//{
//    JKListNode *pNode;
//
//    assert( pElement != NULL );
//
//    pNode = pSelf->pNIL->pNext;
//
//    while( pNode != pSelf->pNIL )
//    {
//        if( pNode->pElement == pElement )
//        {
//            pNode->pNext->pPrev = pNode->pPrev;
//            pNode->pPrev->pNext = pNode->pNext;
//        
//            free( pNode );
//            pSelf->count--;
//            return 1;
//        }
//
//        pNode = pNode->pNext;
//    }
//
//    return 0;
//}

////////////////////////////////////////////////////////////////////////////////

JKListNode* jklist_first( JKList *pSelf )
{
    assert( pSelf != NULL );
    
    if( pSelf->count == 0 ) return NULL;

    return pSelf->pNIL->pNext;
}

////////////////////////////////////////////////////////////////////////////////

JKListNode* jklist_last( JKList *pSelf )
{
    assert( pSelf != NULL );

    if( pSelf->count == 0 ) return NULL;

    return pSelf->pNIL->pPrev;
}

////////////////////////////////////////////////////////////////////////////////

JKListNode* jklist_next( JKList *pSelf, JKListNode *pNode )
{
    assert( pSelf != NULL );
    assert( pNode != NULL );

    if( pNode->pNext == pSelf->pNIL ) return NULL;

    return pNode->pNext;
}

////////////////////////////////////////////////////////////////////////////////

JKListNode* jklist_prev( JKList *pSelf, JKListNode *pNode )
{
    assert( pSelf != NULL );
    assert( pNode != NULL );

    if( pNode->pPrev == pSelf->pNIL ) return NULL;

    return pNode->pPrev;
}

////////////////////////////////////////////////////////////////////////////////

unsigned long jklist_count( JKList *pSelf )
{
    assert( pSelf != NULL );
    return pSelf->count;
}

////////////////////////////////////////////////////////////////////////////////

int jklist_empty( JKList *pSelf )
{
    assert( pSelf != NULL );
    return pSelf->count == 0;
}

////////////////////////////////////////////////////////////////////////////////

void jklist_clear( JKList *pSelf )
{
    assert( pSelf != NULL );

    while( pSelf->count != 0 )
    {
        jklist_removeFirst( pSelf );
    }
}