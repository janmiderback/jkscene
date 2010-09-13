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

#include "jkmatrix4stack.h"

////////////////////////////////////////////////////////////////////////////////

void jkmatrix4stack_init( JKMatrix4Stack *pSelf,
                          unsigned long   preAllocCount )
{
    assert( pSelf != NULL );

    //jkstack_init( pSelf->
}

////////////////////////////////////////////////////////////////////////////////

void jkmatrix4stack_push( JKMatrix4Stack *pSelf )
{
}

////////////////////////////////////////////////////////////////////////////////

void jkmatrix4stack_pop( JKMatrix4Stack *pSelf )
{
}

////////////////////////////////////////////////////////////////////////////////

void jkmatrix4stack_loadIdentity( JKMatrix4Stack *pSelf )
{
}

////////////////////////////////////////////////////////////////////////////////

void jkmatrix4stack_load( JKMatrix4Stack  *pSelf,
                          const JKMatrix4 *pMatrix )
{
}

////////////////////////////////////////////////////////////////////////////////

void jkmatrix4stack_mulRight( JKMatrix4Stack  *pSelf,
                              const JKMatrix4 *pRHSMatrix )
{
}

////////////////////////////////////////////////////////////////////////////////

void jkmatrix4stack_mulLeft( JKMatrix4Stack  *pSelf,
                             const JKMatrix4 *pLHSMatrix )
{
}
