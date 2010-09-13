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

#ifndef JKLIST_H_
#define JKLIST_H_

#include <stdlib.h>

typedef struct JKListNode_ JKListNode;

/**
    @brief
    Linked list.
 */
typedef struct
{
    size_t elementSize;
    JKListNode *pNIL;
    unsigned long count;
} JKList;


/**
    @brief
    List node of linked list. Contains pointers to next node in list,
    together with a pointer to the actual element data.
 */
struct JKListNode_
{
    struct JKListNode_ *pPrev;
    struct JKListNode_ *pNext;
    void *pElement;
};



/*
 * Operations
 */

/**
    @brief
    Initializes the list. Must be called before the list can be
    used.
 */
void jklist_init( JKList *pSelf, size_t elementSize );


/**
    @brief
    Deinitializes the list. Must be called before the JKList struct
    is deallocated.
 */
void jklist_deinit( JKList *pSelf );


/**
    @brief
    TODO
 */
void jklist_insertFirst( JKList *pSelf,
                         const void *pElement );


/**
    @brief
    TODO
 */
void jklist_insertLast( JKList *pSelf,
                        const void *pElement );


/**
    @brief
    TODO
 */
void jklist_removeFirst( JKList *pSelf );


/**
    @brief
    TODO
 */
void jklist_removeLast( JKList *pSelf );


/**
    @brief
    TODO
 */
//int jklist_remove( JKList *pSelf, void *pElement );


/**
    @brief
    TODO
 */
JKListNode* jklist_first( JKList *pSelf );


/**
    @brief
    TODO
 */
JKListNode* jklist_last( JKList *pSelf );


/**
    @brief
    TODO
 */
JKListNode* jklist_next( JKList *pSelf, JKListNode *pNode );


/**
    @brief
    TODO
 */
JKListNode* jklist_prev( JKList *pSelf, JKListNode *pNode );


/**
    @brief
    TODO
 */
unsigned long jklist_count( JKList *pSelf );


/**
    @brief
    TODO
 */
int jklist_empty( JKList *pSelf );


/**
    @brief
    TODO
 */
void jklist_clear( JKList *pSelf );


#endif //JKLIST_H_
