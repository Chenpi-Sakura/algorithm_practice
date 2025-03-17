/*
umi的函数
题目背景
umi 找到了一个神秘的函数 f。

题目描述
这个函数接受两个字符串 s1,s2。这些字符串只能由小写字母组成，并且具有相同的长度。这个函数的输出是另一个长度与 s1,s2 相同的字符串 g。g 的第 i 个字符等于 s1 的第i 个字符和 s2 的第 i 个字符的最小值，简单来说，g[i]=min(s1[i],s2[i])。

例如：f("ab","ba")= "aa", f("nzwzl","zizez")="niwel".

她现在有两个相同长度的只有小写字母的字符串 x,y。找出任何一个满足 f(x,z)=y 的字符串 z。如果找不到这样的字符串的话，请输出-1。

输入格式
第一行给出以下两个字符串的长度 n。

第二行给出一个字符串 x。

第三行给出一个字符串 y。

输出格式
第一行输出一个字符串，代表你找到的符合条件的字符串。找不到的话，请输出-1。
*/
#include <bits/stdc++.h>
using namespace std;

string x, y, z;

int main()
{
    int n;
    cin >> n >> x >> y;
    z.resize(n);
    for (int i = 0; i < n; i++)
    {
        if (y[i] > x[i])
        {
            cout << -1;
            return 0;
        }
        else
        {
            z[i] = y[i];
        }
    }
    z[n] = '\0';
    cout << z;
    return 0;
}