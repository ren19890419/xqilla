/*
 * Copyright (c) 2001, 2008,
 *     DecisionSoft Limited. All rights reserved.
 * Copyright (c) 2004, 2011,
 *     Oracle and/or its affiliates. All rights reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef _URENAME_HPP
#define _URENAME_HPP

#include <xqilla/framework/XQillaExport.hpp>
#include <xqilla/ast/ASTNodeImpl.hpp>

class XQILLA_CLASS URename : public ASTNodeImpl
{
public:
  URename(ASTNode *target, ASTNode *name, XPath2MemoryManager* memMgr);

  virtual ASTNode *staticResolution(StaticContext *context);
  virtual ASTNode *staticTypingImpl(StaticContext *context);
  virtual Result createResult(DynamicContext* context, int flags=0) const;
  virtual PendingUpdateList createUpdateList(DynamicContext *context) const;

  ASTNode *getTarget() const { return target_; }
  void setTarget(ASTNode *target) { target_ = target; }

  ASTNode *getName() const { return name_; }
  void setName(ASTNode *name) { name_ = name; }

protected:
  ASTNode *target_;
  ASTNode *name_;
};

#endif
