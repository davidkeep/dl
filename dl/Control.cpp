//
//  Control.cpp
//  Created by David on 5/28/16.
//

#include "Control.h"

If* If::Clone() const
{
    auto r = new If(condition->Clone());
    r->thenBlock = *thenBlock.Clone();
    r->elseBlock = *elseBlock.Clone();
    r->clone = true;
    return r;
}

void If::Scope(Block *parent)
{
    assert(parent);
    Node::Scope(parent);
    thenBlock.Scope(parent);
    elseBlock.Scope(parent);
    condition->Scope(parent);
}
