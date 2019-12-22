#include <iostream>
#include "StringClass.h"

std::ostream &operator<<(std::ostream &stream, const StringClass &string)
{
    stream << string.m_Buffer;
    return stream;
}

unsigned int SetCapacity(const unsigned int size)
{
    unsigned int capacity = 0;
    while (size > capacity)
        capacity += CAPACITY_INC_FACTOR;

    return capacity;
}

void MemCpy(char *dst, const char *src, const unsigned dstSize, const unsigned int srcPos, const unsigned int dstPos)
{
    if ((nullptr != src) && (nullptr != dst))
    {
        const unsigned int srcSize = (const unsigned int)strlen(src);
        for (unsigned short srcIdx = srcPos, dstIdx = dstPos; ((srcIdx < srcSize) && (dstIdx < dstSize)); srcIdx++, dstIdx++)
            dst[dstIdx] = src[srcIdx];

        dst[dstSize] = NULL_CHAR;
    }
    else
    {
        throw std::invalid_argument("String::MemCpy() : String is NULL");
        exit(0);
    }
}

void MemCpy(char *dst, const char ch, const unsigned size, const unsigned int dstPos)
{
    for (unsigned short idx = dstPos; idx < size; idx++)
        dst[idx] = ch;

    dst[size] = NULL_CHAR;
}
