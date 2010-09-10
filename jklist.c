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
#include "jklist.h"


void jklist_init( JKList *pSelf )
{
    assert( pSelf != NULL );

    pSelf->pNIL = malloc( sizeof( JKListNode ) );
    assert( pSelf->pNIL != NULL );
    pSelf->pNIL->pPrev = pSelf->pNIL;
    pSelf->pNIL->pNext = pSelf->pNIL;
    pSelf->count = 0;
}


void jklist_insertFirst( JKList *pSelf, void *pElement )
{
    JKListNode *pNewNode;

    assert( pSelf != NULL );
    pNewNode = malloc( sizeof( JKListNode ) );
    assert( pNewNode != NULL );
    pNewNode->pElement = pElement;
    
    pNewNode->pPrev = pSelf->pNIL;
    pNewNode->pNext = pSelf->pNIL->pNext;
    pSelf->pNIL->pNext->pPrev = pNewNode;
    pSelf->pNIL->pNext = pNewNode;
    
    pSelf->count++;
}


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


void* jklist_removeFirst( JKList *pSelf )
{
    void *pRetVal = 0;
    JKListNode *pFirstNode;

    assert( pSelf != NULL );

    if( pSelf->count != 0 )
    {
        pFirstNode = pSelf->pNIL->pNext;
        pRetVal = pFirstNode->pElement;

        pFirstNode->pNext->pPrev = pFirstNode->pPrev;
        pSelf->pNIL->pNext = pFirstNode->pNext;
        
        free( pFirstNode );
        pSelf->count--;
    }

    return pRetVal;
}


void* jklist_removeLast( JKList *pSelf )
{
    return NULL;
}


JKListNode* jklist_first( JKList *pSelf )
{
    return NULL;
}

JKListNode* jklist_last( JKList *pSelf )
{
    return NULL;
}


JKListNode* jklist_next( JKListNode *pNode )
{
    return NULL;
}


JKListNode* jklist_prev( JKListNode *pNode )
{
    return NULL;
}


void* jklist_remove( JKListNode *pNode )
{
    return NULL;
}


unsigned long jklist_count( JKList *pSelf )
{
    assert( pSelf != NULL );
    return pSelf->count;
}


int jklist_empty( JKList *pSelf )
{
    assert( pSelf != NULL );
    return pSelf->count == 0;
}
