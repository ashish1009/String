#pragma once

#include <iostream>

class Iterator
{
private:

public:
    bool operator!=(const Iterator &it) const;
    Iterator operator++(const int inc) const;

public:
    Iterator();
    ~Iterator();
};