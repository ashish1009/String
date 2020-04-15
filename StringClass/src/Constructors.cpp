#include <StringClass.h>

StringClass::StringClass()
    : m_Buffer(nullptr), m_Size(0), m_Capacity(0) {}

StringClass::~StringClass()
{
    DeleteString();
}

StringClass::StringClass(const StringClass &string)
{
    AllocCopyString(string.m_Buffer, string.m_Size);
}

StringClass::StringClass(const char *const string)
{
    AllocCopyString(string, (const unsigned int)strlen(string));
}

StringClass::StringClass(const StringClass &string, const unsigned int pos, const int len)
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
}

StringClass::StringClass(const char *const string, const unsigned int len)
{
    const unsigned int size = (strlen(string) >= len) ? len : (const unsigned int)strlen(string);
    AllocCopyString(string, size);
}

StringClass::StringClass(const unsigned int len, const unsigned char ch)
{
    AllocCopyString(ch, len);
}

StringClass::StringClass(const char ch)
{
    AllocCopyString(ch, sizeof(char));
}