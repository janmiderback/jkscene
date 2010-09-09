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

//#define WIN32_LEAN_AND_MEAN
//#include <windows.h>

#include "jkscenegraph.h"


    //TODO: Replace with an init func?
//JKSceneGraph::JKSceneGraph()
//: m_root(),
//  m_pActiveCamera(NULL)
//{
//  Matrix4 e;
//
//  //TMP
//  //printf("Creating scene graph: 0x%x\n", this);
//  
//  // Make sure there is always an identity transform on the top.
//  SetIdentity(e);
//  matrixStack_.push(e);
//  //printf("Pushing root on transform matrix stack. Size now: %d\n", matrixStack_.size());
//}

//JKSceneGraph::~JKSceneGraph()
//{
//  printf("Destroying scene graph: 0x%x\n", this);
//}


void jkscenegraph_render( JKSceneGraph *pSelf )
{
    assert( pSelf != NULL );
    jkscenenode_preRender( pSelf->pRootNode );
    jkscenenode_render( pSelf->pRootNode );
    jkscenenode_renderChildren( pSelf->pRootNode );
    jkscenenode_postRender( pSelf->pRootNode );
}


void jkscenegraph_restore( JKSceneGraph *pSelf )
{
    assert( pSelf != NULL );
    jkscenenode_restore( pSelf->pRootNode );
}


JKSceneNode* jkscenegraph_getRoot( JKSceneGraph *pSelf )
{
    assert( pSelf != NULL );
    return pSelf->pRootNode;
}


JKSceneNode* jkscenegraph_getActiveCamera( JKSceneGraph *pSelf )
{
    assert( pSelf != NULL );
    return pSelf->pActiveCameraNode;
}


void jkscenegraph_setActiveCamera( JKSceneGraph *pSelf, JKSceneNode *pCameraNode )
{
    assert( pSelf != NULL );
    pSelf->pActiveCameraNode = pCameraNode;
}


JKMatrix4Stack* jkscenegraph_getMatrixStack( JKSceneGraph *pSelf )
{

}
