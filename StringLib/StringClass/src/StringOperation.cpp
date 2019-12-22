#include "StringClass.h"

const unsigned int StringClass::Copy(char *str, const unsigned int len, const unsigned int pos) const
{
    if (nullptr != str)
        delete str;

    str = new char[len];
    for (unsigned short srcIdx = 0, dstIdx = pos; srcIdx < len; srcIdx++, dstIdx++)
        str[srcIdx] = this->m_Buffer[dstIdx];

    return len;
}

const int StringClass::Find(const StringClass &string, const unsigned int pos) const
{
    return FindString(string.m_Buffer, pos, string.m_Size);
}

const int StringClass::Find(const char *const string, const unsigned int pos) const
{
    return FindString(string, pos, (const unsigned int)strlen(string));
}

const int StringClass::Find(const char *const string, const unsigned int pos, const unsigned int len) const
{
    return FindString(string, pos, pos + len);
}

const int StringClass::Find(const char ch, const unsigned int pos) const
{
    for (unsigned short thisIdx = pos; this->m_Size > thisIdx; thisIdx++)
        if (this->m_Buffer[thisIdx] == ch)
            return thisIdx;

    return NPOS;
}

const int StringClass::Rfind(const StringClass &string, const unsigned int pos) const
{
    return RfindString(string.m_Buffer, pos, string.m_Size);
}

const int StringClass::Rfind(const char *const string, const unsigned int pos) const
{
    return RfindString(string, pos, (const unsigned int)strlen(string));
}

const int StringClass::Rfind(const char *const string, const unsigned int pos, const unsigned int len) const
{
    return RfindString(string, pos, pos + len);
}

const int StringClass::Rfind(const char ch, const unsigned int pos) const
{
    for (short thisIdx = this->m_Size - 1; pos <= thisIdx; thisIdx--)
        if (this->m_Buffer[thisIdx] == ch)
            return thisIdx;

    return NPOS;
}

const int StringClass::FindFirstOf(const StringClass &string, const unsigned int pos) const
{
    return FindFisrtOfString(string.m_Buffer, pos, string.m_Size);
}

const int StringClass::FindFirstOf(const char *const string, const unsigned int pos) const
{
    return FindFisrtOfString(string, pos, (const unsigned int)strlen(string));
}

const int StringClass::FindFirstOf(const char *const string, const unsigned int pos, const unsigned int len) const
{
    return FindFisrtOfString(string, pos, pos + len);
}

const int StringClass::FindFirstOf(const char ch, const unsigned int pos) const
{
    return Find(ch, pos);
}

const int StringClass::FindLastOf(const StringClass &string, const unsigned int pos) const
{
    return FindLastOfString(string.m_Buffer, pos, string.m_Size);
}

const int StringClass::FindLastOf(const char *const string, const unsigned int pos) const
{
    return FindLastOfString(string, pos, (const unsigned int)strlen(string));
}

const int StringClass::FindLastOf(const char *const string, const unsigned int pos, const unsigned int len) const
{
    return FindLastOfString(string, pos, pos + len);
}

const int StringClass::FindLastOf(const char ch, const unsigned int pos) const
{
    return Rfind(ch, pos);
}


const int StringClass::FindFirstNotOf(const StringClass &string, const unsigned int pos) const
{
    return FindFisrtNotOfString(string.m_Buffer, pos, string.m_Size);
}

const int StringClass::FindFirstNotOf(const char *const string, const unsigned int pos) const
{
    return FindFisrtNotOfString(string, pos, (const unsigned int)strlen(string));
}

const int StringClass::FindFirstNotOf(const char *const string, const unsigned int pos, const unsigned int len) const
{
    return FindFisrtNotOfString(string, pos, pos + len);
}

const int StringClass::FindFirstNotOf(const char ch, const unsigned int pos) const
{
    return Find(ch, pos);
}

const int StringClass::FindLastNotOf(const StringClass &string, const unsigned int pos) const
{
    return FindLastNotOfString(string.m_Buffer, pos, string.m_Size);
}

const int StringClass::FindLastNotOf(const char *const string, const unsigned int pos) const
{
    return FindLastNotOfString(string, pos, (const unsigned int)strlen(string));
}

const int StringClass::FindLastNotOf(const char *const string, const unsigned int pos, const unsigned int len) const
{
    return FindLastNotOfString(string, pos, pos + len);
}

const int StringClass::FindLastNotOf(const char ch, const unsigned int pos) const
{
    return Rfind(ch, pos);
}

StringClass StringClass::SubStr(const unsigned int pos, const int len) const
{
    StringClass string;
    string.Assign(*this, pos, len);
    return string;
}

const int StringClass::Compare(const StringClass &string) const
{
    return CompareString(0, this->m_Size, string.m_Buffer, 0, string.m_Size);
}

const int StringClass::Compare(const unsigned int pos, const unsigned int len, const StringClass &string) const
{
    return CompareString(pos, len, string.m_Buffer, 0, string.m_Size);
}

const int StringClass::Compare(const unsigned int pos, const unsigned int len, const StringClass &string, const unsigned int subPos, const unsigned int subLen) const
{
    return CompareString(pos, len, string.m_Buffer, subPos, subLen);
}

const int StringClass::Compare(const char* const string) const
{
    return CompareString(0, this->m_Size, string, 0, (const unsigned int)strlen(string));
}

const int StringClass::Compare(const unsigned int pos, const unsigned int len, const char* const string) const
{
    return CompareString(pos, len, string, 0, (const unsigned int)strlen(string));
}

const int StringClass::Compare(const unsigned int pos, const unsigned int len, const char* const string, const unsigned int subLen) const
{
    return CompareString(pos, len, string, 0, subLen);
}
