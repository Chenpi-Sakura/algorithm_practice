#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e4 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

struct edge{int v, w;};
vector<edge> g[N];
priority_queue<PII, vector<PII>, greater<PII>> pq;
int f[N], vis[N], dis[N];

void dijkstra(int maxn)
{
    memset(dis, inf, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    while(pq.size()) pq.pop();
    dis[1] = 0;
    pq.push({dis[1], 1});
    while (pq.size())
    {
        int u = pq.top().second; pq.pop();
        if (vis[u]) continue; vis[u] = 1;
        for (auto ed : g[u])
        {
            int v = ed.v, w = ed.w;
            if (f[v] > maxn) continue;
            if (dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
}

void solve()
{
    int n, m, hp; cin >> n >> m >> hp;
    int l = 0, r = 0;
    for (int i = 1; i <= n; i++) 
    {
        cin >> f[i];
        r = max(r, f[i]);
    }
    l = max(f[1], f[n]);
    for (int i = 1; i <= m; i++) 
    {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    while (l < r)
    {
        int mid = (l + r) / 2;
        dijkstra(mid);
        if (dis[n] > hp) l = mid + 1;
        else r = mid;
    }
    dijkstra(l);
    if (dis[n] > hp) cout << "AFK" << endl;
    else cout << l << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}