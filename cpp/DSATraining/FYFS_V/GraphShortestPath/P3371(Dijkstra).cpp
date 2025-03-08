#include<bits/stdc++.h> 
using namespace std;

const int N = 1e4 + 5;
const int inf = 2e9;
struct edge
{int v, w;};
vector<edge> e[N];
int d[N], vis[N];
int n, m, s;

void dijkstra(int s)
{
    for (int i = 0; i <= n; i++) d[i] = inf;
    d[s] = 0;
    for (int i = 1; i < n; i++)
    { // 注意枚举次数为 n - 1 次
        int u = 0;
        for (int j = 1; j <= n; j++)
        { // 枚举每个节点
            if (!vis[j] && d[j] < d[u]) u = j;
        }
        vis[u] = 1;
        for (auto ed : e[u])
        { // 枚举 u 点邻边
            int v = ed.v, w = ed.w;
            if (d[v] > d[u] + w) d[v] = d[u] + w;
        }
    }
}

int main( )
{
    cin >> n >> m >> s;
    while (m--)
    {
        int u, v, w; cin >> u >> v >> w;
        e[u].push_back({v, w});
    }
    dijkstra(s);
    for (int i = 1; i <= n; i++) cout << d[i] << ' ';
    return 0;
}