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


#include "jklist.h"

////////////////////////////////////////////////////////////////////////////////

int jklist_test( void );

typedef struct
{
    float x;
    float y;
    int   n;
} TestData;

////////////////////////////////////////////////////////////////////////////////

int jklist_test( void )
{
    int testOk = 1;
    JKList list;
    JKListNode *pNode;
    const TestData data1 = { 1.0, 2.0, 3 };
    const TestData data2 = { 4.0, 5.0, 6 };
    const TestData data3 = { 7.0, 8.0, 9 };
    TestData *pData;
    unsigned long count;
    int empty;

    jklist_init( &list, sizeof( TestData ) );
    count = jklist_count( &list );
    empty = jklist_empty( &list );
    testOk = count == 0 &&
             empty &&
             testOk;

    jklist_insertFirst( &list, &data1 );
    
    // Make sure count increases
    count = jklist_count( &list );
    empty = jklist_empty( &list );
    testOk = count == 1 &&
             !empty &&
             testOk;

    jklist_insertFirst( &list, &data2 );
    jklist_insertFirst( &list, &data3 );
    
    count = jklist_count( &list );
    testOk = count == 3 && testOk;

    // Iterate from start to end
    pNode = jklist_first( &list );
    pData = (TestData*)(pNode->pElement);
    testOk = pData->x == data3.x &&
             pData->y == data3.y &&
             pData->n == data3.n && testOk;

    pNode = jklist_next( &list, pNode );
    pData = (TestData*)(pNode->pElement);
    testOk = pData->x == data2.x &&
             pData->y == data2.y &&
             pData->n == data2.n && testOk;

    pNode = jklist_next( &list, pNode );
    pData = (TestData*)(pNode->pElement);
    testOk = pData->x == data1.x &&
             pData->y == data1.y &&
             pData->n == data1.n && testOk;

    pNode = jklist_next( &list, pNode );
    testOk = pNode == NULL && testOk;

    // Iterate from end to start
    pNode = jklist_last( &list );
    pData = (TestData*)(pNode->pElement);
    testOk = pData->x == data1.x &&
             pData->y == data1.y &&
             pData->n == data1.n && testOk;

    pNode = jklist_prev( &list, pNode );
    pData = (TestData*)(pNode->pElement);
    testOk = pData->x == data2.x &&
             pData->y == data2.y &&
             pData->n == data2.n && testOk;

    pNode = jklist_prev( &list, pNode );
    pData = (TestData*)(pNode->pElement);
    testOk = pData->x == data3.x &&
             pData->y == data3.y &&
             pData->n == data3.n && testOk;

    pNode = jklist_prev( &list, pNode );
    testOk = pNode == NULL && testOk;

    // Remove first
    jklist_removeFirst( &list );
    count = jklist_count( &list );
    testOk = count == 2 && testOk;

    pNode = jklist_first( &list );
    pData = (TestData*)(pNode->pElement);
    testOk = pData->x == data2.x &&
             pData->y == data2.y &&
             pData->n == data2.n && testOk;

    // Remove last
    jklist_removeLast( &list );
    count = jklist_count( &list );
    testOk = count == 1 && testOk;

    pNode = jklist_last( &list );
    pData = (TestData*)(pNode->pElement);
    testOk = pData->x == data2.x &&
             pData->y == data2.y &&
             pData->n == data2.n && testOk;

    // Clear list
    jklist_insertFirst( &list, &data2 );
    jklist_insertFirst( &list, &data3 );
    count = jklist_count( &list );
    testOk = count == 3 && testOk;

    jklist_clear( &list );
    count = jklist_count( &list );
    empty = jklist_empty( &list );
    testOk = count == 0 &&
             empty &&
             testOk;

    jklist_deinit( &list );

    return testOk;
}
