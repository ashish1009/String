#include "StringClass.h"
#include "string.h"

StringClass &StringClass::operator=(const char *string)
{
    AllocCopyString(string, (const unsigned int)strlen(string));
    return *this;
}

StringClass &StringClass::operator=(const StringClass &string)
{
    AllocCopyString(string.m_Buffer, string.m_Size);
    return *this;
}

StringClass &StringClass::operator=(const char ch)
{
    AllocCopyString(ch, sizeof(char));
    return *this;
}

void StringClass::ReSize(const unsigned int len, const unsigned char ch)
{
    StringClass string = this->m_Buffer;
    AllocString(len);

    const unsigned int size = (len < string.m_Size) ? len : string.m_Size;
    MemCpy(this->m_Buffer, string.m_Buffer, size);

    if(len > string.m_Size)
        MemCpy(this->m_Buffer, ch, len, string.m_Size);
}

void StringClass::ShringToFit()
{
    StringClass string = this->m_Buffer;
    AllocString(string.m_Size, string.m_Size);
    MemCpy(this->m_Buffer, string.m_Buffer, string.m_Size);
}
