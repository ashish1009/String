#pragma once
#include <iostream>
#include <math.h>
#include "Iterator.h"

#define String StringClass

const unsigned short CAPACITY_INC_FACTOR = 10;
const unsigned char NULL_CHAR = '\0';

class StringClass
{
private:
    static const unsigned short BITS_IN_INT = 32;
    friend std::ostream &operator<<(std::ostream &stream, const StringClass &string);

private:
    char *m_Buffer;
    unsigned int m_Size;
    unsigned int m_Capacity;

public:
    static const short NPOS = -1;

private:
    void DeleteString();
    void AllocCopyString(const char *const string, const unsigned int size);
    void AllocCopyString(const char ch, const unsigned int size);
    void AllocString(const unsigned int size, const unsigned int capacity = 0);

    StringClass &AppendString(const char *const string, const unsigned int strSize, const unsigned int dstPos = 0);
    StringClass &AppendString(const char ch);

    StringClass &InsertString(const unsigned int pos, const char *const string, const unsigned int strSize, const unsigned int dstPos = 0);
    StringClass &ReplaceString(const unsigned int pos, const unsigned int len, const char *const string, const unsigned int strSize, const unsigned int subPos = 0);

    const int FindString(const char *const string, const unsigned int pos, const unsigned int len) const;
    const int RfindString(const char *const string, const unsigned int pos, const unsigned int len) const;
    const int FindFisrtOfString(const char *const string, const unsigned int pos, const unsigned int len) const;
    const int FindLastOfString(const char *const string, const unsigned int pos, const unsigned int len) const;
    const int FindFisrtNotOfString(const char *const string, const unsigned int pos, const unsigned int len) const;
    const int FindLastNotOfString(const char *const string, const unsigned int pos, const unsigned int len) const;

    const int CompareString(const unsigned int pos, const unsigned int len, const char *const string, const unsigned int subPos, const unsigned int subLen) const;

public:
    /*
    * String operation
    */
    Iterator Begin() const;
    Iterator End() const;

public:
    /*
    * String operation
    */
    inline const char *CStr() const
    {
        return this->m_Buffer;
    }

    inline const char *Data() const
    {
        return this->m_Buffer;
    }

    const unsigned int Copy(char *str, const unsigned int len, const unsigned int pos = 0) const;

    const int Find(const StringClass &string, const unsigned int pos = 0) const;
    const int Find(const char *const string, const unsigned int pos = 0) const;
    const int Find(const char *const string, const unsigned int pos, const unsigned int len) const;
    const int Find(const char ch, const unsigned int pos) const;

    const int Rfind(const StringClass &string, const unsigned int pos = 0) const;
    const int Rfind(const char *const string, const unsigned int pos = 0) const;
    const int Rfind(const char *const string, const unsigned int pos, const unsigned int len) const;
    const int Rfind(const char ch, const unsigned int pos) const;

    const int FindFirstOf(const StringClass &string, const unsigned int pos = 0) const;
    const int FindFirstOf(const char *const string, const unsigned int pos = 0) const;
    const int FindFirstOf(const char *const string, const unsigned int pos, const unsigned int len) const;
    const int FindFirstOf(const char ch, const unsigned int pos) const;

    const int FindLastOf(const StringClass &string, const unsigned int pos = 0) const;
    const int FindLastOf(const char *const string, const unsigned int pos = 0) const;
    const int FindLastOf(const char *const string, const unsigned int pos, const unsigned int len) const;
    const int FindLastOf(const char ch, const unsigned int pos) const;

    const int FindFirstNotOf(const StringClass &string, const unsigned int pos = 0) const;
    const int FindFirstNotOf(const char *const string, const unsigned int pos = 0) const;
    const int FindFirstNotOf(const char *const string, const unsigned int pos, const unsigned int len) const;
    const int FindFirstNotOf(const char ch, const unsigned int pos) const;
    
    const int FindLastNotOf(const StringClass &string, const unsigned int pos = 0) const;
    const int FindLastNotOf(const char *const string, const unsigned int pos = 0) const;
    const int FindLastNotOf(const char *const string, const unsigned int pos, const unsigned int len) const;
    const int FindLastNotOf(const char ch, const unsigned int pos) const;

    StringClass SubStr(const unsigned pos = 0, const int len = NPOS) const;

    const int Compare(const StringClass &string) const;
    const int Compare(const unsigned int pos, const unsigned int len, const StringClass &string) const;
    const int Compare(const unsigned int pos, const unsigned int len, const StringClass &string, const unsigned int subPos, const unsigned int subLen) const;
    const int Compare(const char* const string) const;
    const int Compare(const unsigned int pos, const unsigned int len, const char* const string) const;
    const int Compare(const unsigned int pos, const unsigned int len, const char* const string, const unsigned int subLen) const;

public:
    /*
    * Modifiers
    */
    StringClass &operator+=(const StringClass &str);
    StringClass &operator+=(const char *const string);
    StringClass &operator+=(const char ch);

    StringClass &Append(const StringClass &string);
    StringClass &Append(const StringClass &string, const unsigned int pos, const unsigned int len);
    StringClass &Append(const char *const string);
    StringClass &Append(const char *const string, const unsigned int len);
    StringClass &Append(const unsigned int len, const char ch);

    StringClass &PushBack(const char ch);

    StringClass &Assign(const StringClass &string);
    StringClass &Assign(const StringClass &string, const unsigned int pos, const unsigned int len);
    StringClass &Assign(const char *const string);
    StringClass &Assign(const char *const string, const unsigned int len);
    StringClass &Assign(const unsigned int len, const char ch);

    StringClass &Insert(const unsigned pos, const StringClass &string);
    StringClass &Insert(const unsigned pos, const StringClass &string, const unsigned int subPos, const unsigned int subLen);
    StringClass &Insert(const unsigned pos, const char *const string);
    StringClass &Insert(const unsigned pos, const char *const string, const unsigned int len);
    StringClass &Insert(const unsigned pos, const unsigned int len, const char ch);

    StringClass &Erase(const unsigned int pos = 0, const unsigned int len = NPOS);

    StringClass &Replace(const unsigned pos, const unsigned int len, const StringClass &string);
    StringClass &Replace(const unsigned pos, const unsigned int len, const StringClass &string, const unsigned int subPos, const unsigned int subLen);
    StringClass &Replace(const unsigned pos, const unsigned int len, const char *const string);
    StringClass &Replace(const unsigned pos, const unsigned int len, const char *const string, const unsigned int subLen);
    StringClass &Replace(const unsigned pos, const unsigned int len, const unsigned int subLen, const char ch);

    StringClass &Swap(StringClass &string);

    void PopBack();

public:
    /*
    * Element Access
    */
    inline char &At(const unsigned int pos) const
    {
        return ((pos < this->m_Size) ? this->m_Buffer[pos] : this->m_Buffer[-1]);
    }

    inline char &operator[](const unsigned int pos) const
    {
        return this->At(pos);
    }

    inline char &Back() const
    {
        return this->At(this->m_Size - 1);
    }

    inline char &Front() const
    {
        return this->At(0);
    }

public:
    /*
    * Capacity
    */
    inline const unsigned int Size() const
    {
        return this->m_Size;
    }
    inline const unsigned long MaxSize() const
    {
        return pow(2, BITS_IN_INT);
    }
    inline const unsigned long Capacity() const
    {
        return this->m_Capacity;
    }
    inline void Clear()
    {
        DeleteString();
    }
    inline bool Empty() const
    {
        return (0 == this->m_Size);
    }

    void ReSize(const unsigned int len, const unsigned char ch = NULL_CHAR);
    void ShringToFit();

public:
    /*
    * Constructor and Destructor
    */
    StringClass();

    StringClass(const char ch);
    StringClass(const char *const string);
    StringClass(const char *const string, const unsigned int len);

    StringClass(const StringClass &string);
    StringClass(const StringClass &string, const unsigned int pos, const int len = NPOS);

    StringClass(const unsigned int len, const unsigned char ch);

    ~StringClass();

    /*
    * Member Function
    */
    StringClass &operator=(const StringClass &str);
    StringClass &operator=(const char *str);
    StringClass &operator=(const char ch);
};

unsigned int SetCapacity(const unsigned int size);
void MemCpy(char *dst, const char *src, const unsigned size, const unsigned int srcPos = 0, const unsigned int dstPos = 0);
void MemCpy(char *dst, const char ch, const unsigned size, const unsigned int dstPos = 0);

/*
* Non Member Function
*/
