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

#include "jkstack.h"

int jkstack_test( void );

typedef struct
{
    float x;
    float y;
    int   n;
} TestData;

////////////////////////////////////////////////////////////////////////////////

int jkstack_test( void )
{
    int testOk = 1;
    JKStack stack;
    TestData *pData;
    unsigned long count;
    int empty;
    int i;

    jkstack_init( &stack, sizeof( TestData ), 10 );

    count = jkstack_count( &stack );
    empty = jkstack_empty( &stack );
    testOk = count == 0 &&
             empty &&
             testOk;

    // Push 10 items
    for( i = 0; i < 10; i++ )
    {
        const TestData data = { (float)i, (float)i, i };

        jkstack_push( &stack, &data );
    }

    count = jkstack_count( &stack );
    empty = jkstack_empty( &stack );
    testOk = count == 10 &&
             !empty &&
             testOk;

    // Pop one element
    pData = jkstack_pop( &stack );
    count = jkstack_count( &stack );
    testOk = count == 9 &&
             pData->x == 9.0 &&
             pData->y == 9.0 &&
             pData->n == 9 &&
             testOk;

    // Pop three elements
    jkstack_popn( &stack, 3 );
    pData = jkstack_top( &stack );
    count = jkstack_count( &stack );
    testOk == count == 6 &&
              pData->x == 5.0 &&
              pData->y == 5.0 &&
              pData->n == 5 &&
              testOk;

    // Pop all elements
    jkstack_popn( &stack, 6 );
    pData = jkstack_top( &stack );
    count = jkstack_count( &stack );
    empty = jkstack_empty( &stack );
    testOk == count == 0 &&
              empty &&
              pData == NULL &&
              testOk;
              
    // Pop more
    jkstack_pop( &stack );
    jkstack_popn( &stack, 2 );
    count = jkstack_count( &stack );
    empty = jkstack_empty( &stack );
    testOk == count == 0 &&
              empty &&
              testOk;

    // Push 15 elements
    for( i = 0; i < 15; i++ )
    {
        const TestData data = { (float)i, (float)i, i };
        jkstack_push( &stack, &data );
    }

    count = jkstack_count( &stack );
    pData = jkstack_top( &stack );
    testOk == count == 15 &&
              pData->x == 14.0 &&
              pData->y == 14.0 &&
              pData->n == 14 &&
              testOk;

    // Clear
    jkstack_clear( &stack );
    count = jkstack_count( &stack );
    empty = jkstack_empty( &stack );
    testOk == count == 0 &&
              empty &&
              testOk;

    jkstack_deinit( &stack );

    return testOk;
}
