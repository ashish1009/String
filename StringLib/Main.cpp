#include <iostream>
#include "StringClass.h"
#include <string.h>
#include "Iterator.h"

void PrintString(const String &str)
{
    if (nullptr != str.CStr())
        std::cout << "String is : " << str << " : Size is : " << str.Size() << " : Capacity : " << str.Capacity() << " : Max Size : " << str.MaxSize() << std::endl
                  << std::endl;
}

int main()
{
    String str;

    // String str1("String is Created for the first time ");
    // PrintString(str1);

    // String str2(str1);
    // PrintString(str2);

    // String str3(str1, 3);
    // PrintString(str3);

    // String str4(str1, 3, 5);
    // PrintString(str4);

    // // String str5(str1, 43);
    // // PrintString(str5);

    // // String str6(str1, 44, 5);
    // // PrintString(str6);

    // String str7("String is Created for the first time ", 15);
    // PrintString(str7);

    // String str8("String is Created for the first time ", 55);
    // PrintString(str8);

    // String str9(7, 'A');
    // PrintString(str9);

    // String str10 = "String operator is called ";
    // PrintString(str10);

    // String str11 = str10;
    // PrintString(str11);

    // String str12 = 'A';
    // PrintString(str12);

    // str2.ReSize(20);
    // PrintString(str2);

    // str2.ReSize(22, 'R');
    // PrintString(str2);

    // str2.ReSize(6, 'R');
    // PrintString(str2);

    // str2.ReSize(28);
    // PrintString(str2);

    // str2.ShringToFit();
    // PrintString(str2);

    // str2[2] = 'z';
    // PrintString(str2);

    // std::cout << str2.At(3) << std::endl;
    // PrintString(str2);

    // std::cout << str2.Front() << std::endl;
    // PrintString(str2);

    // std::cout << str2.Back() << std::endl;
    // PrintString(str2);

    // str2 += " LOL See what added";
    // PrintString(str2);

    // str2 += str3;
    // PrintString(str2);

    // str2 += 'A';
    // PrintString(str2);

    // str2.Append(str4);
    // PrintString(str2);

    // str2.Append(" again appended LOL ");
    // PrintString(str2);

    // str4 = "ashish";
    // PrintString(str4);

    // str2.Append(str4, 5, 55);
    // PrintString(str2);

    // str2.Append(" AGAIN I AM ADDIDNG ONLY 15 ", 10);
    // PrintString(str2);

    // str2.Append(5, 'A');
    // PrintString(str2);

    // str3.Assign(str4);
    // PrintString(str3);

    // str3.Assign(" again appended LOL ");
    // PrintString(str3);

    // str3.Assign(str7, 3, 5);
    // PrintString(str3);

    // str3.Assign(" AGAIN I AM ADDIDNG ONLY 15 ", 10);
    // PrintString(str3);

    // str3.Assign(5, 'A');
    // PrintString(str3);

    // str3 = "THIS IS NEW ";
    // PrintString(str3);

    // str2 = "Will appene here -> ";
    // PrintString(str2);

    // str2.Insert(3, str3);
    // PrintString(str2);

    // str2.Insert(3, " Hey see this also ");
    // PrintString(str2);

    // str2.Insert(3, str3, 3, 4);
    // PrintString(str2);

    // str2.Insert(14, " Hey see this also ", 6);
    // PrintString(str2);

    // str2.Insert(14, 6, 'X');
    // PrintString(str2);

    // str2.Erase(4,10);
    // PrintString(str2);

    // String str13 = "0123456789!@#$%^&*()";
    // PrintString(str13);

    // String str14 = " new one ";
    // PrintString(str14);

    // str13.Replace(4, 3, str14);
    // PrintString(str13);

    // str13.Replace(7, 4, " 1234 ");
    // PrintString(str13);

    // str13.Replace(4, 3, str14, 1, 5);
    // PrintString(str13);

    // str13.Replace(7, 4, " 1234 ", 4);
    // PrintString(str13);

    // str13.Swap(str14);
    // PrintString(str13);
    // PrintString(str14);

    // str13.PopBack();
    // PrintString(str13);

    // int i = 0;
    // const char* temmpChar = str13.CStr();
    // while (temmpChar[i] != NULL_CHAR)
    // {
    //     std::cout << temmpChar[i] << std::endl;
    //     i++;
    // }

    // char *ch = "ashihs";
    // int len = str13.Copy(ch, 4);
    // ch[len] = NULL_CHAR;
    // std::cout << ch <<std::endl;

    // std::string str_1 = " Lest find some strings finds here we will find to see what we finds ";
    // std::string str_2 = "find";
    // std::cout << str_1.rfind(str_2) << std::endl;

    // String str15 = " Lest find some strings finds here we will find to see what we finds ";
    // PrintString(str15);

    // String str16 = "find";
    // PrintString(str16);
    // std::cout << str15.Find(str16) << std::endl;
    // std::cout << str15.Rfind(str16) << std::endl;

    // // str15.Replace(str15.Find(str16), str16.Size(), " replaced ");
    // // PrintString(str15);

    // String str17 = "fint";
    // PrintString(str17);
    // std::cout << str15.Find(str17) << std::endl;
    // std::cout << str15.Rfind(str17) << std::endl;

    // String str18 = "finds";
    // PrintString(str18);
    // std::cout << str15.Find(str18) << std::endl;
    // std::cout << str15.Rfind(str18) << std::endl;

    // String str19 = "LOLfinds";
    // PrintString(str19);
    // std::cout << str15.Find(str19, 3) << std::endl;
    // std::cout << str15.Rfind(str19, 3) << std::endl;

    // String str20 = "LOLfinds";
    // PrintString(str20);
    // std::cout << str15.Find(str20, 2) << std::endl;
    // std::cout << str15.Rfind(str20, 2) << std::endl;

    // std::cout << str15.Find("find") << std::endl;
    // std::cout << str15.Find("fint") << std::endl;
    // std::cout << str15.Find("finds") << std::endl;
    // std::cout << str15.Find("LOLfinds", 2) << std::endl;
    // std::cout << str15.Find("LOLfinds", 3) << std::endl;
    // std::cout << str15.Find("LOLfinds", 3, 3) << std::endl;

    // std::cout << str15.Rfind("find") << std::endl;
    // std::cout << str15.Rfind("fint") << std::endl;
    // std::cout << str15.Rfind("finds") << std::endl;
    // std::cout << str15.Rfind("LOLfinds", 2) << std::endl;
    // std::cout << str15.Rfind("LOLfinds", 3) << std::endl;
    // std::cout << str15.Rfind("LOLfinds", 3, 3) << std::endl;

    // String str21 = "aeiou";
    // PrintString(str21);

    // int found = str15.FindFirstOf(str21);
    // while (String::NPOS != found)
    // {
    //     std::cout << str15[found] << std::endl;
    //     found = str15.FindFirstOf(str21, found + 1);        
    // }

    // std::cout << str15.FindFirstOf(str21) << std::endl;
    // std::cout << str15.FindLastOf(str21) << std::endl;
    // std::cout << str15.FindFirstNotOf(str21) << std::endl;
    // std::cout << str15.FindLastNotOf(str21) << std::endl;

    // String str22 = str15.SubStr(2, 6);
    // PrintString(str22);

    // str22 = "LOL";
    // PrintString(str22);

    // str22 = str15.SubStr(4, 6);
    // PrintString(str22);

    // String str23 = " we will compare this";
    // String str24 = "compare";
    // String str25 = "compare";
    // String str26 = "LOLcompareLOL";

    // std::cout << str24.Compare(str25) << std::endl;
    // std::cout << str23.Compare(str25) << std::endl;
    // std::cout << str23.Compare(9, 7, str25) << std::endl;
    // std::cout << str23.Compare(9, 7, str26, 3, 7) << std::endl;
    // std::cout << str23.Compare(9, 7, str26) << std::endl;

    // std::string str_1 = "asihs";
    // std::string::iterator it = str_1.begin();
    // std::cout << *it << std::endl;
    // for (std::string::iterator it = str_1.begin(); it != str_1.end(); it++)
    // {
    // }
    
    // String str27 = " Iterator test";
    // for(Iterator it = str27.Begin(); it != str27.End(); it++)
    // {

    // }

    return 0;
}
