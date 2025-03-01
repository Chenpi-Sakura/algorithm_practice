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

// HeapPrim 更适合用于稀疏图，这样效率更高 "Prim 注重点的扩张"

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
struct edge{int v, w;};             // 记录终点与边权
vector<edge> e[N];                  // e[u] 记录 u 点的所有邻边的终点与边权
priority_queue<pair<int, int>> q;   // 大根堆
int d[N], vis[N];                   // d[u] 记录 u 点与圈外邻点的最小距离，vis[u] 记录 u 点是否出圈。
int n, ans, cnt;                    // n 节点数

bool prim(int s)
{
    for (int i = 0; i <= n; i++) d[i] = N;
    d[s] = 0; q.push({0, s}); // 初始化
    while (q.size())
    {
        int x = q.top().second; q.pop();
        if (vis[x]) continue;
        vis[x] = 1;
        ans += d[x]; cnt++;
        for (auto y : e[x])
        {
            int v = y.v, w = y.w;
            if (d[v] > w)
            {
                d[v] = w;
                q.push({-d[v], v});
            }
        }
    }
    return cnt == n;
}

int main()
{
    int m; cin >> n >> m;
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