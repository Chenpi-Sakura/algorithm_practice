/*
 * @Author: Chenpi
 * @Date: 2025-07-21 17:24:48
 * @Link: https://www.luogu.com.cn/problem/P8805
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 1e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

vector<int> g[N];
int fa[N][20], dep[N], din[N], ds[N];

void dfs(int u, int p)
{
    dep[u] = dep[p] + 1;
    fa[u][0] = p;
    ds[u] += ds[p] + din[u];
    for (int i = 1; i <= 19; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (int v : g[u]) if (v != p) dfs(v, u);
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
    int n, m; cin >> n >> m;
    for (int i = 0; i < n - 1; i++) 
    {
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        din[x]++; din[y]++;
    }
    dfs(1, 0);
    while (m--)
    {
        int x, y; cin >> x >> y;
        int z = lca(x, y);
        cout << ds[x] + ds[y] - 2 * ds[z] + din[z] << endl;
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