/*
递归实现排列型枚举
题目描述
今有 n 名学生，要从中选出 k 人排成一列拍照。
请按字典序输出所有可能的排列方式。

输入格式
仅一行，两个正整数 n,k。

输出格式
若干行，每行 k 个正整数，表示一种可能的队伍顺序。
*/

#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> num;

void dfs(int m, int state)
{
    if (m == k)
    {
        for (auto i : num) cout << i << " ";
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (!(state >> i & 1))
        {
            num.push_back(i + 1);
            dfs(m + 1, state | 1 << i);
            num.pop_back();
        }
    }
}

int main()
{
    cin >> n >> k;
    dfs(0, 0);
    return 0;
}