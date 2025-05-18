#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

struct edges {int u, v, w;};
vector<edges> eds;
struct edge {int v, w;};
vector<edge> ed[N];
int dis1[N], dis2[N], vis[N];
priority_queue<PII> q;
int n, m;

void dijkstra1()
{
    memset(dis1, inf, sizeof(dis1));
    memset(vis, 0, sizeof(vis));
    q.push({0, 1});
    dis1[1] = 0;
    while (q.size())
    {
        int u = q.top().second; q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto x : ed[u])
        {
            int v = x.v, w = x.w;
            if (dis1[u] + w < dis1[v])
            {
                dis1[v] = dis1[u] + w;
                q.push({-dis1[v], v});
            }
        }
    }
}

void dijkstran()
{
    memset(dis2, inf, sizeof(dis2));
    memset(vis, 0, sizeof(vis));
    q.push({0, n});
    dis2[n] = 0;
    while (q.size())
    {
        int u = q.top().second; q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto x : ed[u])
        {
            int v = x.v, w = x.w;
            if (dis2[u] + w < dis2[v])
            {
                dis2[v] = dis2[u] + w;
                q.push({-dis2[v], v});
            }
        }    
    }
}

void solve()
{
    cin >> n >> m;
    eds.clear();
    for (int i = 0; i <= n; i++) ed[i].clear();
    for (int i = 0; i < m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        ed[u].push_back({v, w});
        ed[v].push_back({u, w});
        eds.push_back({u, v, w});
    }
    dijkstra1();
    dijkstran();
    for (auto x : eds)
    {
        if (dis1[x.u] + dis2[x.v] + x.w == dis1[n] || dis1[x.v] + x.w + dis2[x.u] == dis1[n]) cout << 1;
        else cout << 0;
    }
    cout << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); //cout.tie(0);
    int t; cin >> t;
    // t = 1;
    while (t--) solve();
    return 0;
}