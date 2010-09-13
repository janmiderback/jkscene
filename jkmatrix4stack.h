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

#ifndef JKMATRIX4STACK_H_
#define JKMATRIX4STACK_H_

#include "jkmath.h"
#include "jkstack.h"


typedef struct
{
    JKStack stack;
} JKMatrix4Stack;


/**
    @brief
    TODO
 */
void jkmatrix4stack_init( JKMatrix4Stack *pSelf,
                          unsigned long   preAllocCount );


/**
    @brief
    TODO
 */
void jkmatrix4stack_push( JKMatrix4Stack *pSelf );


/**
    @brief
    TODO
 */
void jkmatrix4stack_pop( JKMatrix4Stack *pSelf );


/**
    @brief
    TODO
 */
void jkmatrix4stack_loadIdentity( JKMatrix4Stack *pSelf );


/**
    @brief
    TODO
 */
void jkmatrix4stack_load( JKMatrix4Stack  *pSelf,
                          const JKMatrix4 *pMatrix );


/**
    @brief
    Right-multiplies current top matrix with a certain matrix.
    The result is stored in the current top matrix.
    (top = top * RHS)
 */
void jkmatrix4stack_mulRight( JKMatrix4Stack  *pSelf,
                              const JKMatrix4 *pRHSMatrix );


/**
    @brief
    Left-multiplies current top matrix with a certain matrix.
    The result is stored in the current top matrix.
    (top = LHS * top)
 */
void jkmatrix4stack_mulLeft( JKMatrix4Stack  *pSelf,
                             const JKMatrix4 *pLHSMatrix );



#endif //JKMATRIX4STACK_H_
