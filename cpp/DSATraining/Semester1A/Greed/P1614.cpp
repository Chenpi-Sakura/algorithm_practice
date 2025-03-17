/*
#P1614. 爱与愁的心痛

题目描述
最近有 n 个不爽的事，每句话都有一个正整数刺痛值（心理承受力极差）。爱与愁大神想知道连续 m 个刺痛值的和的最小值是多少，但是由于业务繁忙，爱与愁大神只好请你编个程序告诉他。

输入格式
第一行有两个用空格隔开的整数，分别代表 n 和 m。

第 2 到第 (n+1) 行，每行一个整数，第 (i+1) 行的整数 ai 代表第 i 件事的刺痛值 ai。

输出格式
输出一行一个整数，表示连续 m 个刺痛值的和的最小值是多少。

提示
对于 100% 的数据，保证 0 ≤ m ≤ n ≤ 3×10^3，1 ≤ ai ≤ 100。
*/

#include <bits/stdc++.h>
using namespace std;

vector<int> a;

int main()
{
    int n, m;
    cin >> n >> m;
    a.resize(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    
    int current = 0;

    for (int i = 0; i < m; i++)
        current += a[i];

    int min = current;

    for (int i = m; i < n; i++)
    {
        current += a[i] - a[i - m];
        if (current < min)
            min = current;
    }
    cout << min << endl;

    return 0;
}