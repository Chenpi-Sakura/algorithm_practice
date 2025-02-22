/*
【模板】拓扑排序 / 家谱树
题目描述
有个人的家族很大，辈分关系很混乱，请你帮整理一下这种关系。给出每个人的后代的信息。输出一个序列，使得每个人的后辈都比那个人后列出。

输入格式
第 1 行一个整数 N（1≤N≤100），表示家族的人数。接下来 N 行，第 i 行描述第 i 个人的后代编号 ai,j，表示 ai,j 是 i 的后代。每行最后是 0 表示描述完毕。

输出格式
输出一个序列，使得每个人的后辈都比那个人后列出。如果有多种不同的序列，输出任意一种即可。
*/

#include<bits/stdc++.h> 
using namespace std;

const int N = 1e3;
vector<int> e[N], tp; // e[N] 邻接表 tp 拓扑序列
int din[N]; // 用于存点 x 的入度
int n; // 节点数

bool toposort()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (din[i] == 0) q.push(i);
    while (q.size())
    {
        int x = q.front(); q.pop();
        tp.push_back(x);
        for (auto y : e[x])
            if (--din[y] == 0) q.push(y);
    }
    return tp.size() == n;
}

int main( )
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int d; cin >> d;
        while (d != 0)
        {
            e[i].push_back(d);
            din[d]++;
            cin >> d;
        }
    }
    if (!toposort()) cout << -1;
    else for (auto x : tp) cout << x << " ";
    cout << endl;

    return 0;
}