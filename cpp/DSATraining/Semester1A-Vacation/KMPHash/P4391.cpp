/*
[BOI2009] Radio Transmission 无线传输
题目描述
给你一个字符串 s1 ，它是由某个字符串 s2 不断自我连接形成的（保证至少重复 2 次）。但是字符串 s2 是不确定的，现在只想知道它的最短长度是多少。

输入格式
第一行一个整数 L，表示给出字符串的长度。
第二行给出字符串 s2 的一个子串，全由小写字母组成。

输出格式
仅一行，表示 s2 的最短长度。
*/

#include<bits/stdc++.h> 
using namespace std;

const int N = 1e7;
int Next[N];

int main( )
{
    int n; cin >> n;
    string s; cin >> s;
    int j = -1; Next[0] = j;
    for (int i = 1; i < n; i++)
    {
        while (j >= 0 && s[i] != s[j + 1]) j = Next[j];
        if (s[i] == s[j + 1]) j++;
        Next[i] = j;
    }
    cout << n - Next[n - 1] - 1 << endl;
    return 0;
}