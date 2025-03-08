#include<bits/stdc++.h> 
using namespace std;

const int N = 1e3 + 5;
const int inf = 0x3f;
struct edge{int v, w;};
vector<edge> e[N];
priority_queue<pair<int, int>> q;
int d[N], vis[N];
int n, m;

void dijkstra(int s)
{
    for (int i = 0; i <= n; i++) d[i] = inf, vis[i] = 0;
    d[s] = 0; q.push({0, s});
    while (q.size())
    {
        int u = q.top().second; q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto ed : e[u])
        {
            int v = ed.v, w = ed.w;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                q.push({-d[v], v});
            }
        }
    }
}

int main( )
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        e[u].push_back({v, w});
    }
    dijkstra(1);
    int ans = 0;
    for (int i = 1; i <= n; i++) ans += d[i];
    for (int i = 2; i <= n; i++)
    {
        dijkstra(i);
        ans += d[1];
    }

    cout << ans << endl;
    return 0;
}