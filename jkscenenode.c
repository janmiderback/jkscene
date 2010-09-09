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

#include "jkscenenode.h"


void jkscenenode_restore( JKSceneNode *pSelf )
{
}

void jkscenenode_preRender( JKSceneNode *pSelf )
{
}

void jkscenenode_render( JKSceneNode *pSelf )
{
}

void jkscenenode_renderChildren( JKSceneNode *pSelf )
{
}

void jkscenenode_postRender( JKSceneNode *pSelf )
{
}


#if 0

////////////////////////////////////////////////////////////////////////////////

JKSceneNode::~JKSceneNode()
{ 
  JKSceneNodeList::iterator it = children_.begin();

  // TODO: How is the scene supposed to be deleted?
  // Major bug
  // Do not try this at home... childrens may allready have been killed...
  //while (it != children_.end())
  //{
  //  (*it)->SetParent(NULL);
  //  ++it;
  //}

  while (!children_.empty())
  {
    children_.pop_front();
  } 
}

////////////////////////////////////////////////////////////////////////////////

void JKSceneNode::Restore(JKSceneGraph& scene)
{
  JKSceneNodeList::iterator it;

  for (it = children_.begin(); it != children_.end(); ++it) {
    (*it)->Restore(scene);
  }
}

////////////////////////////////////////////////////////////////////////////////

void JKSceneNode::PreRender(JKSceneGraph& scene)
{
  // Empty
}

////////////////////////////////////////////////////////////////////////////////

void JKSceneNode::Render(JKSceneGraph& scene)
{
  // Empty
}

////////////////////////////////////////////////////////////////////////////////

void JKSceneNode::RenderChildren(JKSceneGraph& scene)
{
  JKSceneNodeList::iterator it = children_.begin();

  for (it = children_.begin(); it != children_.end(); ++it) {
    JKSceneNode *pChild = *it;
    pChild->PreRender(scene);
    pChild->Render(scene);
    pChild->RenderChildren(scene);
    pChild->PostRender(scene);
  }
}

////////////////////////////////////////////////////////////////////////////////

void JKSceneNode::PostRender(JKSceneGraph& scene)
{
  // Empty
}

////////////////////////////////////////////////////////////////////////////////

void JKSceneNode::AddChild(JKSceneNode *pChild)
{
  children_.push_back(pChild);
}

#endif //0
