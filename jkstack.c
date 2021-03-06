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
#include "jkstack.h"

////////////////////////////////////////////////////////////////////////////////

static void grow( JKStack *pSelf );

////////////////////////////////////////////////////////////////////////////////

void jkstack_init( JKStack       *pSelf,
                   size_t         elementSize,
                   unsigned long  preAllocCount )
{
    assert( pSelf != NULL );
    
    pSelf->elementSize = elementSize;

    pSelf->bufSize = elementSize * (preAllocCount + 1);
    assert( pSelf->bufSize != 0 );
    
    pSelf->pBuf = malloc( pSelf->bufSize );
    assert( pSelf->pBuf != NULL );

    pSelf->pTop = pSelf->pBuf;
    pSelf->count = 0;
    pSelf->allocCount = preAllocCount;
}

////////////////////////////////////////////////////////////////////////////////

void jkstack_deinit( JKStack *pSelf )
{
    if( pSelf != NULL )
    {
        free( pSelf->pBuf );
    }
}

////////////////////////////////////////////////////////////////////////////////

void jkstack_push( JKStack    *pSelf,
                   const void *pElement )
{
    assert( pSelf != NULL );
    assert( pElement != NULL );

    if( pSelf->count == pSelf->allocCount )
    {
        grow( pSelf );
    }

    pSelf->pTop += pSelf->elementSize;
    memcpy( pSelf->pTop, pElement, pSelf->elementSize );
    pSelf->count++;
}

////////////////////////////////////////////////////////////////////////////////

void* jkstack_pop( JKStack *pSelf )
{
    void *pRetVal = NULL;

    assert( pSelf != NULL );

    if( pSelf->count > 0 )
    {
        pRetVal = pSelf->pTop;
        pSelf->pTop -= pSelf->elementSize;
        pSelf->count--;
    }

    return pRetVal;
}

////////////////////////////////////////////////////////////////////////////////

void jkstack_popn( JKStack *pSelf, unsigned long n )
{
    assert( pSelf != NULL );

    if( n > pSelf->count ) n = pSelf->count;

    pSelf->pTop -= pSelf->elementSize * n;
    pSelf->count -= n;
}

////////////////////////////////////////////////////////////////////////////////

void* jkstack_top( JKStack *pSelf )
{
    assert( pSelf != NULL );

    if( pSelf->count == 0 ) return NULL;

    return pSelf->pTop;
}

////////////////////////////////////////////////////////////////////////////////

unsigned long jkstack_count( const JKStack *pSelf )
{
    assert( pSelf != NULL );

    return pSelf->count;
}

////////////////////////////////////////////////////////////////////////////////

int jkstack_empty( const JKStack *pSelf )
{
    assert( pSelf != NULL );

    return pSelf->count == 0;
}

////////////////////////////////////////////////////////////////////////////////

void jkstack_clear( JKStack *pSelf )
{
    assert( pSelf != NULL );

    pSelf->pTop = pSelf->pBuf;
    pSelf->count = 0;
}

////////////////////////////////////////////////////////////////////////////////

static void grow( JKStack *pSelf )
{
    assert( pSelf != NULL );

    // Double the buffer size
    pSelf->bufSize *= 2;
    
    pSelf->pBuf = realloc( pSelf->pBuf, pSelf->bufSize );
    pSelf->pTop = pSelf->pBuf + (pSelf->elementSize * pSelf->count);
}
