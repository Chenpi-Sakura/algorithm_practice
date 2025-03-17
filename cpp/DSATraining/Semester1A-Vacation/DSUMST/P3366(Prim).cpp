/*
【模板】最小生成树
题目描述
如题，给出一个无向图，求出最小生成树，如果该图不连通，则输出 orz。

输入格式
第一行包含两个整数 N,M，表示该图共有 N 个结点和 M 条无向边。

接下来 M 行每行包含三个整数 Xi, Yi, Zi，
表示有一条长度为 Zi 的无向边连接结点 Xi, Yi。

输出格式
如果该图连通，则输出一个整数表示最小生成树的各边的长度之和。如果该图不连通则输出 orz。
*/

// Prim 更适合用于浓稠图

#include<bits/stdc++.h> 
using namespace std;

const int N = 2e5 + 10;
struct edge{int v, w;};
vector<edge> e[N];
int d[N], vis[N];
int ans = 0, n, m, cnt;

bool prim(int s)
{
    for (int i = 0; i <= n; i++) d[i] = N;
    d[s] = 0;
    for (int i = 1; i <= n; i++)
    {
        int u = 0;
        for (int j = 1; j <= n; j++)
            if (!vis[j] && d[j] < d[u]) u = j;
        vis[u] = 1;
        ans += d[u];
        if (d[u] != N) cnt++;
        for (auto ed : e[u])
        {
            int v = ed.v, w = ed.w;
            if (d[v] > w) d[v] = w;
        }
    }
    return cnt == n;
}

int main()
{
    cin >> n >> m;
    while (m--)
    {
        int x, y, z; cin >> x >> y >> z;
        e[x].push_back({y, z});
        e[y].push_back({x, z});
    }
    if (!prim(1)) cout << "orz" << endl;
    else cout << ans << endl;
    return 0;
}