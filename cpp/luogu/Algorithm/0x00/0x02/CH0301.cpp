/*
递归实现指数型枚举
从 1∼n 这 n 个整数中随机选取任意多个，输出所有可能的选择方案。

输入格式
输入一个整数 n。

输出格式
每行输出一种方案。
同一行内的数必须升序排列，相邻两个数用恰好 1 个空格隔开。
对于没有选任何数的方案，输出空行。

数据范围
n < 20+65
*/
#include<bits/stdc++.h>
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
                cout << i + 1 << " ";
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