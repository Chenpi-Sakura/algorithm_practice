/*
    快读模板代码
    原理：Speed：getchar() > scanf() > cin;
*/

#include <bits/stdc++.h>
using namespace std;

inline int read()
{
    int s = 0, w = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-') w *= -1;
        ch = getchar();
    }
    while ('0' <= ch && ch <= '9')
    {
        s = s * 10 + ch - '0';
        ch = getchar();
    }
    return s * w;
}

int main()
{

}