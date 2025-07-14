#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1000 + 5;
const int M = 1024 + 5;
const int inf = 0x3f3f3f3f;

vector<PII> G[N];
int n, m, ans = inf;
bool vis[N][M];

void dfs(int u, int x)
{
    if (vis[u][x]) return;
    vis[u][x] = true;

    if (u == n)
    {
        ans = min(ans, x);
    }
    for (auto ed : G[u]) dfs(ed.first, x ^ ed.second);
}

// dfs
void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        G[u].push_back({v, w});
    }
    dfs(1, 0);
    cout << (ans == inf ? -1 : ans) << endl;
}

//bfs
queue<PII> q;

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        G[u].push_back({v, w});
    }
    q.push({1, 0}); vis[1][0] = 1;
    while (q.size())
    {
        auto [u, val] = q.front(); q.pop();
        for (auto [v, w] : G[u])
        {
            if (!vis[v][val ^ w])
            {
                vis[v][val ^ w] = 1;
                q.push({v, val ^ w});
            }
        }
    }
    int ans = -1;
    for (int i = 0; i < 1024; i++) if (vis[n][i]) {ans = i; break;};
    cout << ans << endl;
}

// struct edge{int v, w;};
// vector<edge> ed[N];
// int dis[N], vis[N];
// int n, m; 

// void dfs(int u, int x)
// {
//     if (ed[u].empty() || u == n)
//     {
//         dis[u] = min(dis[u], x);
//     }
//     for (auto e : ed[u])
//     {
//         if (vis[u]) continue;
//         vis[u] = 1;
//         dfs(e.v, x ^ e.w);
//         vis[u] = 0;
//     }
// }

// void solve()
// {
//     memset(dis, inf, sizeof(dis));
//     cin >> n >> m;
//     for (int i = 0; i < m; i++)
//     {
//         int u, v, w; cin >> u >> v >> w;
//         ed[u].push_back({v, w});
//     }
//     dfs(1, 0);
//     if (dis[n] >= inf) cout << -1;
//     else cout << dis[n];
// }

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