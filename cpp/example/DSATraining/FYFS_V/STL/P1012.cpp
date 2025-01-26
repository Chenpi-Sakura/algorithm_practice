/*
[NOIP1998 提高组] 拼数
题目描述
设有 n 个正整数 a1…an，将它们联接成一排，相邻数字首尾相接，组成一个最大的整数。

输入格式
第一行有一个整数，表示数字个数 n。
第二行有 n 个整数，表示给出的 n 个整数 ai。

输出格式
一个正整数，表示最大的整数
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
vector<string> a;

bool cmp(string a, string b)
{
    return a + b > b + a;
}

int main()
{
    int n; cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end(), cmp);
    for (int i = 0; i < n; i++) cout << a[i];
    cout << endl;
    return 0;
}