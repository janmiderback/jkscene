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

#ifndef JKSTACK_H_
#define JKSTACK_H_


typedef struct JKStackNode_ JKStackNode;

/**
    @brief
    Stack.
 */
typedef struct
{
    unsigned char *pBuf;
    unsigned char *pTop;
    size_t  elementSize;
    size_t  bufSize;
    unsigned long count;
    unsigned long allocCount;
} JKStack;


/*
 * Operations
 */

/**
    @brief
    Initializes the stack. Must be called before the stack can be
    used.
 */
void jkstack_init( JKStack       *pSelf,
                   size_t         elementSize,
                   unsigned long  preAllocCount );


/**
    @brief
    Deinitializes the stack. Must be called before the JKStack struct
    is deallocated.
 */
void jkstack_deinit( JKStack *pSelf );


/**
    @brief
    Deinitializes the stack. Must be called before the JKStack struct
    is deallocated.
 */
void jkstack_deinit( JKStack *pSelf );


/**
    @brief
    TODO
 */
void jkstack_push( JKStack *pSelf,
                   void    *pElement );


/**
    @brief
    TODO
 */
void* jkstack_pop( JKStack *pSelf );


/**
    @brief
    TODO
 */
void jkstack_popn( JKStack *pSelf, unsigned long count );


/**
    @brief
    TODO
 */
void* jkstack_top( JKStack *pSelf );


/**
    @brief
    TODO
 */
unsigned long jkstack_count( JKStack *pSelf );


/**
    @brief
    TODO
 */
int jkstack_empty( JKStack *pSelf );


/**
    @brief
    TODO
 */
void jkstack_clear( JKStack *pSelf );


#endif //JKSTACK_H_
