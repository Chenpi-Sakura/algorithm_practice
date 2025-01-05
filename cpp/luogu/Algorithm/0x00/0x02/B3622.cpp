/*
递归实现组合型枚举
题目描述
今有 n 位同学，可以从中选出任意名同学参加合唱。
请输出所有可能的选择方案。

输入格式
仅一行，一个正整数 n。

输出格式
若干行，每行表示一个选择方案。

每一种选择方案用一个字符串表示，其中第 i 位为 Y 则表示第 i 名同学参加合唱；为 N 则表示不参加。

需要以字典序输出答案。
*/
#include <bits/stdc++.h>
using namespace std;

int n;

void dfs(int m, int state)
{
    if (m == n)
    {
        for (int i = 0; i < n; i++)
        {
            if (state >> i & 1)
            {
                cout << "Y";
            }
            else
            {
                cout << "N";
            }
        }
        cout << endl;
        return;
    }

    dfs(m + 1, state);
    dfs(m + 1, state | 1 << m);
}

int main()
{
    cin >> n;
    dfs(0, 0);
    return 0;
}