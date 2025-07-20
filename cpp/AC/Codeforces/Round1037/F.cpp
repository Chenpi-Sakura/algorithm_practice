#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int col[N], pa[N], w[N];
vector<PII> adj[N];
vector<int> child[N];
map<int, int> ccol[N];

void dfs(int u, int p)
{
    pa[u] = p;
    for (auto edge : adj[u])
    {
        auto [v, c] = edge;
        if (v == p) continue;
        w[v] = c;
        child[u].push_back(v);
        dfs(v, u);
    }
}

void solve()
{
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; ++i) 
    {
        adj[i].clear();
        child[i].clear();
        ccol[i].clear();
        pa[i] = 0;
        w[i] = 0;
    }
    for (int i = 1; i <= n; i++) cin >> col[i];
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, c; cin >> u >> v >> c;
        adj[u].push_back({v, c});
        adj[v].push_back({u, c});
    }
    dfs(1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (pa[i] != 0 && col[i] != col[pa[i]]) ans += w[i];
        for (int c : child[i]) ccol[i][col[c]] += w[c];
    }
    while (q--)
    {
        int v, x; cin >> v >> x;
        int oc = col[v];
        if (col[v] == x)
        {
            cout << ans << endl;
            continue;
        }

        ans += ccol[v][oc] - ccol[v][x];

        if (pa[v] != 0)
        {
            int p = pa[v], c = w[v];
            ccol[p][oc] -= c;
            if (ccol[p][oc] == 0) ccol[p].erase(oc);
            if (col[p] != oc) ans -= c;
            if (col[p] != x) ans += c;
            ccol[p][x] += c;
        }
        col[v] = x;
        cout << ans << endl;
    }
}

// 直观做法TLE
// struct edge {int v, w;};
// void solve()
// {
//     int n, q; cin >> n >> q;
//     vector<int> c(n + 1);
//     vector<edge> g[n + 1]; 
//     for (int i = 1; i <= n; i++) cin >> c[i];
//     int ans = 0;
//     for (int i = 1; i < n; i++)
//     {
//         int u, v, w; cin >> u >> v >> w;
//         g[u].push_back({v, w});
//         g[v].push_back({u, w});
//         if (c[u] != c[v]) ans += w;
//     }
//     while (q--)
//     {
//         int v, x; cin >> v >> x;
//         for (auto ed : g[v])
//         {
//             auto [u, w] = ed;
//             if (c[u] != c[v] && c[u] == x) ans -= w;
//             if (c[u] == c[v] && c[u] != x) ans += w;
//         }
//         c[v] = x;
//         cout << ans << endl;
//     }
// }

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}