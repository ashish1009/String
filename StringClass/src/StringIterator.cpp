#include "StringClass.h"

Iterator StringClass::Begin() const
{
    Iterator it = (Iterator)this->Front();
    return it;
}

Iterator StringClass::End() const
{
    Iterator it;
    return it;
}