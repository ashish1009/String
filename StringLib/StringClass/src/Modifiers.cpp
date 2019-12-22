#include "StringClass.h"

StringClass &StringClass::operator+=(const char *const string)
{
    return AppendString(string, (const unsigned int)strlen(string));
}

StringClass &StringClass::operator+=(const StringClass &string)
{
    return AppendString(string.m_Buffer, string.m_Size);
}

StringClass &StringClass::operator+=(const char ch)
{
    return AppendString(ch);
}

StringClass &StringClass::Append(const StringClass &string)
{
    return AppendString(string.m_Buffer, string.m_Size);
}

StringClass &StringClass::Append(const StringClass &string, const unsigned int pos, const unsigned int len)
{
    if (pos > string.m_Size)
        return *this;

    const unsigned int size = (len > (string.m_Size - pos)) ? (string.m_Size - pos) : len;
    return AppendString(string.m_Buffer, size, pos);
}

StringClass &StringClass::Append(const char *const string)
{
    return AppendString(string, (const unsigned int)strlen(string));
}

StringClass &StringClass::Append(const char *const string, const unsigned int len)
{
    const unsigned int size = (len > (const unsigned int)strlen(string)) ? (const unsigned int)strlen(string) : len;
    return AppendString(string, size);
}

StringClass &StringClass::Append(const unsigned int len, const char ch)
{
    StringClass localStr = this->m_Buffer;

    const unsigned int dstSize = len + localStr.m_Size;
    AllocString(dstSize);
    MemCpy(this->m_Buffer, localStr.m_Buffer, localStr.m_Size);

    for (unsigned short idx = localStr.m_Size; idx < dstSize; idx++)
        this->m_Buffer[idx] = ch;

    this->m_Buffer[dstSize] = NULL_CHAR;

    return *this;
}

StringClass &StringClass::PushBack(const char ch)
{
    return AppendString(ch);
}

StringClass &StringClass::Assign(const StringClass &string)
{
    AllocCopyString(string.m_Buffer, string.m_Size);
    return *this;
}

StringClass &StringClass::Assign(const StringClass &string, const unsigned int pos, const unsigned int len)
{
    if (string.m_Size >= pos)
    {
        const unsigned int size = (NPOS == len) ? (string.m_Size - pos) : len;
        AllocString(size);
        MemCpy(this->m_Buffer, string.m_Buffer, size, pos);
    }
    else
    {
        throw std::out_of_range(" Pos > size : ");
    }
    return *this;
}

StringClass &StringClass::Assign(const char *const string)
{
    AllocCopyString(string, (const unsigned int)strlen(string));
    return *this;
}

StringClass &StringClass::Assign(const char *const string, const unsigned int len)
{
    const unsigned int size = (strlen(string) >= len) ? len : (const unsigned int)strlen(string);
    AllocCopyString(string, size);
    return *this;
}

StringClass &StringClass::Assign(const unsigned int len, const char ch)
{
    AllocCopyString(ch, len);
    return *this;
}

StringClass &StringClass::Insert(const unsigned pos, const StringClass &string)
{
    return InsertString(pos, string.m_Buffer, string.m_Size);
}

StringClass &StringClass::Insert(const unsigned pos, const char *const string)
{
    return InsertString(pos, string, (const unsigned int)strlen(string));
}

StringClass &StringClass::Insert(const unsigned pos, const StringClass &string, const unsigned int subPos, const unsigned int subLen)
{
    if (pos > string.m_Size)
        return *this;

    const unsigned int size = (subLen > (string.m_Size - pos)) ? (string.m_Size - pos) : subLen;
    return InsertString(pos, string.m_Buffer, size, subPos);
}

StringClass &StringClass::Insert(const unsigned pos, const char *const string, const unsigned int len)
{
    const unsigned int size = (len > (const unsigned int)strlen(string)) ? (const unsigned int)strlen(string) : len;
    return InsertString(pos, string, size);
}

StringClass &StringClass::Insert(const unsigned pos, const unsigned int len, const char ch)
{
    StringClass localStr = this->m_Buffer;

    const unsigned int dstSize = len + localStr.m_Size;
    AllocString(dstSize);
    MemCpy(this->m_Buffer, localStr.m_Buffer, pos + 1);

    for (unsigned short idx = pos + 1; idx < (pos + len); idx++)
        this->m_Buffer[idx] = ch;

    MemCpy(this->m_Buffer, localStr.m_Buffer, dstSize, pos, (pos + len));

    this->m_Buffer[dstSize] = NULL_CHAR;

    return *this;
}

StringClass &StringClass::Erase(const unsigned int pos, const unsigned int len)
{
    if (pos > this->m_Size)
        return *this;
    
    const unsigned int size = (len == NPOS) ? this->m_Size : len;
    
    StringClass localStr = this->m_Buffer;
    const unsigned int dstSize = this->m_Size - size;

    AllocString(dstSize);
    MemCpy(this->m_Buffer, localStr.m_Buffer, pos + 1);
    MemCpy(this->m_Buffer, localStr.m_Buffer, dstSize, (pos + len), pos);
    return *this;
}

StringClass &StringClass::Replace(const unsigned pos, const unsigned int len, const StringClass &string)
{
    return ReplaceString(pos, len, string.m_Buffer, string.m_Size);
}

StringClass &StringClass::Replace(const unsigned pos, const unsigned int len, const char *const string)
{
    return ReplaceString(pos, len, string, (const unsigned int)strlen(string));
}

StringClass &StringClass::Replace(const unsigned pos, const unsigned int len, const StringClass &string, const unsigned int subPos, const unsigned int subLen)
{
    if (pos > string.m_Size)
        return *this;

    const unsigned int size = (subLen > (string.m_Size - pos)) ? (string.m_Size - pos) : subLen;
    return ReplaceString(pos, len, string.m_Buffer, size, subPos);
}

StringClass &StringClass::Replace(const unsigned pos, const unsigned int len, const char *const string, const unsigned int subLen)
{
    const unsigned int size = (len > (const unsigned int)strlen(string)) ? (const unsigned int)strlen(string) : len;
    return ReplaceString(pos, len, string, size);
}

StringClass &StringClass::Replace(const unsigned pos, const unsigned int len, const unsigned int subLen, const char ch)
{
    StringClass localStr = this->m_Buffer;

    const unsigned int dstSize = subLen + localStr.m_Size - len;
    AllocString(dstSize);
    MemCpy(this->m_Buffer, localStr.m_Buffer, pos + 1);

    for (unsigned short idx = pos + 1; idx < (pos + subLen); idx++)
        this->m_Buffer[idx] = ch;

    MemCpy(this->m_Buffer, localStr.m_Buffer, dstSize, pos + len, (pos + len));

    this->m_Buffer[dstSize] = NULL_CHAR;

    return *this;
}

StringClass &StringClass::Swap(StringClass &string)
{
    StringClass localString = *this;
    *this = string;
    string = localString;
    return *this;
}

void StringClass::PopBack()
{
    this->Erase(this->m_Size - 1, 1);
}