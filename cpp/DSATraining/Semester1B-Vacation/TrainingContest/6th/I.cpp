#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f3f3f3f3fLL;

vector<int> e[N];
int fa[N][20], dep[N], a[N], w[N];

void dfs(int u, int p)
{
    w[u] = w[p] + a[u];
    dep[u] = dep[p] + 1;
    fa[u][0] = p;
    for (int i = 1; i <= 19; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (int v : e[u]) if (v != p) dfs(v, u);
}

int lca(int a, int b)
{
    if (dep[a] < dep[b]) swap(a, b);
    for (int i = 19; i >= 0; i--)
        if (dep[fa[a][i]] >= dep[b])
            a = fa[a][i];
    if (a == b) return a;
    for (int i = 19; i >= 0; i--)
        if (fa[a][i] != fa[b][i])
            a = fa[a][i], b = fa[b][i];
    return fa[a][0];
}

void solve()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
    }
    dfs(1, 0);
    int q; cin >> q;
    while (q--)
    {
        int k; cin >> k;
        int a, b; cin >> a >> b; 
        int c = lca(a, b);
        cout << w[a] + w[b] - w[c] << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}