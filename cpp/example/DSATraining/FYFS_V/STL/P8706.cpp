/*
[蓝桥杯 2020 省 AB1] 解码
题目描述
小明有一串很长的英文字母，可能包含大写和小写。

在这串字母中，有很多连续的是重复的。小明想了一个办法将这串字母表达得更短：将连续的几个相同字母写成字母 + 出现次数的形式。 
例如，连续的 5 个 a，即 aaaaa，小明可以简写成 a5（也可能简写成 a4a、aa3a 等）。

对于这个例子：HHHellllloo，小明可以简写成 H3el5o2。为了方便表达，小明不会将连续的超过9个相同的字符写成简写的形式。

现在给出简写后的字符串，请帮助小明还原成原来的串。

输入格式
输入一行包含一个字符串。

输出格式
输出一个字符串，表示还原后的串。
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin >> s;
    int len = s.size();
    for (int i = 0; i < len; i++)
    {
        char letter = s[i];
        char number = s[i + 1];
        if ((('a' <= letter && letter <= 'z') || ('A' <= letter && letter <= 'Z')) && '1'<= number && number <= '9')
        {
            number -= '0';
            while (number--)
            {
                cout << letter;
            }
            i++;
        }
        else
        {
            cout << letter;
        }
    }
    return 0;
}