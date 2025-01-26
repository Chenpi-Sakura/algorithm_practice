/*
【模板】单调栈
题目背景
模板题，无背景。

题目描述
给出项数为 n 的整数数列 a1…an。

定义函数 f(i) 代表数列中第 i 个元素之后第一个大于 ai 的元素的下标，若不存在，则 f(i)=0。

试求出 f(1…n)。

输入格式
第一行一个正整数 n。
第二行 n 个正整数 a1…an。

输出格式
一行 n 个整数表示 
f(1),f(2),…,f(n) 的值。
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;
int a[N], ans[N], q[N];

int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int top = 0;
    for (int i = 0; i <= n; i++)
    {
        while (top > 0 && a[q[top]] < a[i])
        {
            ans[q[top]] = i;
            top--;
        }
        q[++top] = i;
    }

    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
    return 0;
}