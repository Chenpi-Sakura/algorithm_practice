#include<bits/stdc++.h> 
using namespace std;
#define int long long

const int N = 1e4 + 5;
const int inf = ((int)1 << 31) - 1;
struct edge
{int v, w;};
vector<edge> e[N];
int d[N], vis[N];
priority_queue<pair<int, int>> q;
int n, m, s;

void dijkstra(int s)
{
    for (int i = 0; i <= n; i++) d[i] = inf;
    d[s] = 0; q.push({0, s});
    while (q.size())
    { 
        auto t = q.top(); q.pop();
        int u = t.second;
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto ed : e[u])
        {
            int v = ed.v, w = ed.w;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w; // different from Prim, there is add, not replace
                q.push({-d[v], v});
            }
        }
    }
}

signed main( )
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