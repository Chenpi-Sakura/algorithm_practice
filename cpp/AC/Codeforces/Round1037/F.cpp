#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

struct edge {int v, w;};

void solve()
{
    int n, q; cin >> n >> q;
    vector<int> c(n + 1);
    vector<edge> g[n + 1]; 
    for (int i = 1; i <= n; i++) cin >> c[i];
    int ans = 0;
    for (int i = 1; i < n; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        if (c[u] != c[v]) ans += w;
    }
    while (q--)
    {
        int v, x; cin >> v >> x;
        for (auto ed : g[v])
        {
            auto [u, w] = ed;
            if (c[u] != c[v] && c[u] == x) ans -= w;
            if (c[u] == c[v] && c[u] != x) ans += w;
        }
        c[v] = x;
        cout << ans << endl;
    }
}

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