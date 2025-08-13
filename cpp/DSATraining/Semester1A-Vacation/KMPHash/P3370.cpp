/*
【模板】字符串哈希
题目描述
如题，给定 N 个字符串（第 i 个字符串长度为 Mi，字符串内包含数字、大小写字母，大小写敏感），请求出 N 个字符串中共有多少个不同的字符串。

输入格式
第一行包含一个整数 N，为字符串的个数。
接下来 N 行每行包含一个字符串，为所提供的字符串。

输出格式
输出包含一行，包含一个整数，为不同的字符串个数。
*/

#include<bits/stdc++.h> 
using namespace std;

typedef unsigned long long ULL;
const int base = 131;
const int N = 1e7;
ULL h[N];

ULL getHash(string s)
{
    ULL key = 0;
    int len = s.size();
    for (int i = 0; i < len; i++)
    {
        key = key * base + s[i];
    }
    return key;
}

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        h[i] = getHash(s);
    }
    sort(h, h + n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (h[i] != h[i + 1]) ans++;
    }

    cout << ans << endl;
    return 0;
}