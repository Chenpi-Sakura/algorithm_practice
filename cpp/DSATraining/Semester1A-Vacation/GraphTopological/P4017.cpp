/*
P4017 最大食物链计数

题目背景

你知道食物链吗？Delia 生物考试的时候，数食物链条数的题目全都错了，因为她总是重复数了几条或漏掉了几条。于是她来就来求助你，然而你也不会啊！写一个程序来帮帮她吧。

题目描述
给你一个食物网，你要求出这个食物网中最大食物链的数量。
（这里的“最大食物链”，指的是**生物学意义上的食物链**，即**最左端是不会捕食其他生物的生产者，最右端是不会被其他生物捕食的消费者**。）
Delia 非常急，所以你只有 1 秒的时间。
由于这个结果可能过大，你只需要输出总数模上 80112002 的结果。

输入格式
第一行，两个正整数 n、m，表示生物种类 n 和吃与被吃的关系数 m。
接下来 m 行，每行两个正整数，表示被吃的生物A和吃A的生物B。

输出格式
一行一个整数，为最大食物链数量模上 80112002 的结果。
*/
#include <bits/stdc++.h>
using namespace std;

const int M = 80112002;
const int N = 5e3 + 10;
vector<int> adj[N];
int din[N], dout[N], num[N], n;

// 会超时
// int dfs(int index)
// {
//     int res = 0;
//     if (adj[index].empty()) return 1;
//     for (int i : adj[index])
//     {
//         res += dfs(i);
//         res %= M;
//     }
//     return res;
// }

int toposort()
{
    int res = 0;
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (din[i] == 0)
        {
            q.push(i);
            num[i] = 1;
        }
    }
    while (q.size())
    {
        int x = q.front();
        q.pop();
        for (int y : adj[x])
        {
            if (--din[y] == 0)
                q.push(y);
            num[y] += num[x];
            num[y] %= M;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (dout[i] == 0)
        {
            res += num[i];
            res %= M;
        }
    }
    return res;
}

int main()
{
    int m;
    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        din[b]++;
        dout[a]++;
    }

    int ans = toposort();
    cout << ans << endl;
    return 0;
}