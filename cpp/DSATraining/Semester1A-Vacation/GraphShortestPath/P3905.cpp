/*
道路重建
题目描述
从前，在一个王国中，在 n 个城市间有 m 条道路连接，而且任意两个城市之间至多有一条道路直接相连。在经过一次严重的战争之后，有 d 条道路被破坏了。国王想要修复国家的道路系统，现在有两个重要城市 A 和 B 之间的交通中断，国王希望尽快的恢复两个城市之间的连接。你的任务就是修复一些道路使 A 与 B 之间的连接恢复，并要求修复的道路长度最小。

输入格式
输入文件第一行为一个整数 n (2<n<=100)，表示城市的个数。这些城市编号从 1 到 n。
第二行为一个整数 m (n-1<=m<=1/2n(n-1))，表示道路的数目。
接下来的 m 行，每行 3 个整数 i,j,k (1<=i,j<=n,i!=j,0<k<=100)，表示城市 i 与 j 之间有一条长为 k 的道路相连。
接下来一行为一个整数 d (1<=d<=m)，表示战后被破坏的道路的数目。在接下来的 d 行中，每行两个整数 i 和 j，表示城市 i 与 j 之间直接相连的道路被破坏。
最后一行为两个整数 A 和 B，代表需要恢复交通的两个重要城市。

输出格式
输出文件仅一个整数，表示恢复 A 与 B 间的交通需要修复的道路总长度的最小值。
*/

/*
    最短路径，我们通过一个数组来记录这个条路是否被破坏。
    被破环的话，代价为 k
    没被破坏的话，代价为 0
*/

#include<bits/stdc++.h> 
using namespace std;

const int inf = 2e9;
struct edge
{int v, w;};
vector<edge> e[105];
priority_queue<pair<int, int>> q;
int d[105], vis[105], broken[105][105], n, m;

void dijkstra(int s)
{
    for (int i = 0; i <= n; i++) d[i] = inf;
    d[s] = 0; q.push({0, s});
    while (q.size())
    {
        int u = q.top().second; q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto ed : e[u])
        {
            int v = ed.v, w = 0;
            if (broken[u][v]) w = ed.w;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                q.push({-d[v], v});
            }
        }
    }
}

signed main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w}); // 无向图注意！！！
    }
    int de; cin >> de;
    while (de--)
    {
        int u, v; cin >> u >> v;
        broken[u][v] = 1;
        broken[v][u] = 1;
    }
    int a, b; cin >> a >> b;
    dijkstra(a);
    cout << d[b] << endl;
    return 0;
}