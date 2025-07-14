#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e3 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

struct edge{int v, w;};
vector<edge> ed[N];
int dis[N], vis[N];
int n, m; 

void dfs(int u, int x)
{
    if (ed[u].empty() || u == n)
    {
        dis[u] = min(dis[u], x);
    }
    for (auto e : ed[u])
    {
        if (vis[u]) continue;
        vis[u] = 1;
        dfs(e.v, x ^ e.w);
        vis[u] = 0;
    }
}

void solve()
{
    memset(dis, inf, sizeof(dis));
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        ed[u].push_back({v, w});
    }
    dfs(1, 0);
    if (dis[n] >= inf) cout << -1;
    else cout << dis[n];
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