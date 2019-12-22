#include "StringClass.h"

void StringClass::DeleteString()
{
    if (nullptr == this->m_Buffer)
        delete this->m_Buffer;

    this->m_Size = 0;
    this->m_Capacity = 0;
}

void StringClass::AllocString(const unsigned int size, const unsigned int capacity)
{
    DeleteString();
    this->m_Capacity = (0 == capacity) ? SetCapacity(size) : capacity;
    this->m_Buffer = new char[this->m_Capacity + 1];
    this->m_Size = size;
}

void StringClass::AllocCopyString(const char *const string, const unsigned int size)
{
    AllocString(size);
    MemCpy(this->m_Buffer, string, size);
}

void StringClass::AllocCopyString(const char ch, const unsigned int size)
{
    AllocString(size);
    MemCpy(this->m_Buffer, ch, size);
}

StringClass &StringClass::AppendString(const char *const string, const unsigned int strSize, const unsigned int dstPos)
{
    StringClass localStr = this->m_Buffer;

    const unsigned int dstSize = strSize + localStr.m_Size;
    AllocString(dstSize);
    MemCpy(this->m_Buffer, localStr.m_Buffer, localStr.m_Size);
    MemCpy(this->m_Buffer, string, dstSize, dstPos, localStr.m_Size);

    return *this;
}

StringClass &StringClass::AppendString(const char ch)
{
    StringClass localStr = this->m_Buffer;

    const unsigned int dstSize = sizeof(ch) + localStr.m_Size;
    AllocString(dstSize);
    MemCpy(this->m_Buffer, localStr.m_Buffer, localStr.m_Size);
    MemCpy(this->m_Buffer, ch, dstSize, localStr.m_Size);

    return *this;
}

StringClass &StringClass::InsertString(const unsigned int pos, const char *const string, const unsigned int strSize, const unsigned int subPos)
{
    if (pos <= this->m_Size)
    {
        StringClass localStr = this->m_Buffer;

        const unsigned int dstSize = this->m_Size + strSize;
        AllocString(dstSize);

        MemCpy(this->m_Buffer, localStr.m_Buffer, pos + 1);
        MemCpy(this->m_Buffer, string, (pos + strSize), subPos, pos);
        MemCpy(this->m_Buffer, localStr.m_Buffer, dstSize, pos, (pos + strSize));
    }
    else
    {
        throw std::out_of_range("Insert() : pos > this->size ");
        exit(0);
    }
    return *this;
}

StringClass &StringClass::ReplaceString(const unsigned int pos, const unsigned int len, const char *const string, const unsigned int strSize, const unsigned int subPos)
{
    if (pos <= this->m_Size)
    {
        StringClass localStr = this->m_Buffer;

        const unsigned int dstSize = this->m_Size - len + strSize;
        AllocString(dstSize);

        MemCpy(this->m_Buffer, localStr.m_Buffer, pos + 1);
        MemCpy(this->m_Buffer, string, (pos + strSize), subPos, pos);
        MemCpy(this->m_Buffer, localStr.m_Buffer, dstSize, (pos + len), (pos + strSize));
    }
    else
    {
        throw std::out_of_range("Insert() : pos > this->size ");
        exit(0);
    }
    return *this;
}

const int StringClass::FindString(const char *const string, const unsigned int pos, const unsigned int len) const
{
    short foundPos = NPOS;
    bool fisrtFound = false;

    for (unsigned short thisIdx = 0, strIdx = pos; ((this->m_Size > thisIdx) && (len > strIdx)); thisIdx++)
    {
        if (this->m_Buffer[thisIdx] == string[strIdx])
        {
            if (!fisrtFound)
            {
                foundPos = thisIdx;
            }
            fisrtFound = true;
            strIdx++;
        }
        else if (fisrtFound)
        {
            foundPos = NPOS;
            fisrtFound = false;
            strIdx = pos;
        }
    }
    return foundPos;
}

const int StringClass::RfindString(const char *const string, const unsigned int pos, const unsigned int len) const
{
    short foundPos = NPOS;
    bool fisrtFound = false;

    for (short thisIdx = this->m_Size - 1, strIdx = len - 1; ((0 <= thisIdx) && (pos <= strIdx)); thisIdx--)
    {
        if (this->m_Buffer[thisIdx] == string[strIdx])
        {
            fisrtFound = true;
            if (strIdx == pos)
                foundPos = thisIdx;
            strIdx--;
        }
        else if (fisrtFound)
        {
            fisrtFound = false;
            strIdx = len;
        }
    }
    return foundPos;
}

const int StringClass::FindFisrtOfString(const char *const string, const unsigned int pos, const unsigned int len) const
{
    for (unsigned short thisIdx = pos; this->m_Size > thisIdx; thisIdx++)
        for (unsigned short strIdx = 0; strIdx < len; strIdx++)
            if (this->m_Buffer[thisIdx] == string[strIdx])
                return thisIdx;

    return NPOS;
}

const int StringClass::FindLastOfString(const char *const string, const unsigned int pos, const unsigned int len) const
{
    for (short thisIdx = this->m_Size; 0 <= thisIdx; thisIdx--)
        for (unsigned short strIdx = 0; strIdx < len; strIdx++)
            if (this->m_Buffer[thisIdx] == string[strIdx])
                return thisIdx;

    return NPOS;
}

const int StringClass::FindFisrtNotOfString(const char *const string, const unsigned int pos, const unsigned int len) const
{
    for (unsigned short thisIdx = pos; this->m_Size > thisIdx; thisIdx++)
        for (unsigned short strIdx = 0; strIdx < len; strIdx++)
            if (this->m_Buffer[thisIdx] != string[strIdx])
                return thisIdx;

    return NPOS;
}

const int StringClass::FindLastNotOfString(const char *const string, const unsigned int pos, const unsigned int len) const
{
    for (short thisIdx = this->m_Size; 0 <= thisIdx; thisIdx--)
        for (unsigned short strIdx = 0; strIdx < len; strIdx++)
            if (this->m_Buffer[thisIdx] != string[strIdx])
                return thisIdx;

    return NPOS;
}

const int StringClass::CompareString(const unsigned int pos, const unsigned int len, const char *const string, const unsigned int subPos, const unsigned int subLen) const
{
    for (unsigned int thisIdx = pos, strIdx = subPos; ((thisIdx < (pos + len)) && (strIdx < (subPos + subLen))); thisIdx++, strIdx++)
        if(this->m_Buffer[thisIdx] != string[strIdx])
            return -1;

    return 0;
}
