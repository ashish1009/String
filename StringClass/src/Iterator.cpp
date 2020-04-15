#include "Iterator.h"

Iterator::Iterator(){}

Iterator::~Iterator(){}

bool Iterator::operator!=(const Iterator &it) const
{
    return false;
}

Iterator Iterator::operator++(const int inc) const
{
    Iterator it;
    return it;
}
