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

#ifndef JKSCENENODE_H_
#define JKSCENENODE_H_

#include "jklist.h"

typedef struct
{
    int removeMe;
} JKSceneNode;

void jkscenenode_restore( JKSceneNode *pSelf );
void jkscenenode_preRender( JKSceneNode *pSelf );
void jkscenenode_render( JKSceneNode *pSelf );
void jkscenenode_renderChildren( JKSceneNode *pSelf );
void jkscenenode_postRender( JKSceneNode *pSelf );


#if 0

class JKSceneGraph;


////////////////////////////////////////////////////////////////////////////////
//
// Class JKSceneNode
//

/**
 * TODO
 */
class JKSceneNode 
{
public:
  explicit JKSceneNode();
  virtual ~JKSceneNode() = 0;

  virtual void Restore(JKSceneGraph& scene);
  virtual void PreRender(JKSceneGraph& scene);
  virtual void Render(JKSceneGraph& scene);
  virtual void RenderChildren(JKSceneGraph& scene);
  virtual void PostRender(JKSceneGraph& scene);

  void AddChild(JKSceneNode *pChild);
  
private:
  JKSceneNode(JKSceneNode&);
  JKSceneNode& operator=(JKSceneNode&);

public:
  JKSceneNodeList children_;
};

#endif //0

#endif //JKSCENENODE_H_
