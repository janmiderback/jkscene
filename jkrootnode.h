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

#ifndef JKROOTNODE_H_
#define JKROOTNODE_H_


#include "jkscenenode.h"

#if 0

class JKSceneGraph;


////////////////////////////////////////////////////////////////////////////////
//
// Class JKRootNode
//

class JKRootNode : public JKSceneNode
{
protected:
  // Not possible to create. You can only retrieve the root from JKSceneGraph.
  explicit JKRootNode();
  virtual ~JKRootNode();

private:
  JKRootNode(JKRootNode&);
  JKRootNode& operator=(JKRootNode&);

  // Only JKSceneGraph can create me.
  friend class JKSceneGraph;

};

#endif //0

#endif //JKROOTNODE_H_
