/*
题目描述
从 1∼n 这 n 个整数中随机选出 m 个，输出所有可能的选择方案。

输入格式
两个整数 n,m，在同一行用空格隔开。

输出格式
按照从小到大的顺序输出所有方案，每行 1 个。
首先，同一行内的数升序排列，相邻两个数用一个空格隔开。
其次，对于两个不同的行，对应下标的数一一比较，字典序较小的排在前面（例如 1 3 5 7 排在 1 3 6 8 前面）。
*/

#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> num;

void dfs(int m, int state)
{
    if (num.size() == k)
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

    for (int i = m; i < n; i++)
    {
        num.push_back(i + 1);
        dfs(i + 1, state | 1 << i);
        num.pop_back();
    }
}

int main()
{
    cin >> n >> k;
    dfs(0, 0);
    return 0;
}