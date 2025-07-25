/** 
 * @Author: Chenpi
 * @Date: 2025-07-24 19:01:14
 * @Link: https://www.luogu.com.cn/problem/P3379
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 5e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

vector<int> e[N];
int fa[N], dep[N], son[N], sz[N], top[N];

void dfs1(int u, int p)
{
    fa[u] = p, dep[u] = dep[p] + 1, sz[u] = 1;
    for (int v : e[u])
    {
        if (v == p) continue;
        dfs1(v, u);
        sz[u] += sz[v];
        if (sz[son[u]] < sz[v]) son[u] = v;
    }
}

void dfs2(int u, int t)
{
    top[u] = t;
    if (!son[u]) return;
    dfs2(son[u], t);
    for (int v : e[u])
    {
        if (v == fa[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}

int lca(int u, int v)
{
    while (top[u] != top[v])
    {
        if (dep[top[u]] < dep[top[v]]) swap(u, v);
        u = fa[top[u]];
    }
    return dep[u] < dep[v] ? u : v;
}

void solve()
{
    int n, m, s; cin >> n >> m >> s;
    for (int i = 1; i < n; i++)
    {
        int x, y; cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs1(s, 0);
    dfs2(s, s);
    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        cout << lca(a, b) << endl;
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