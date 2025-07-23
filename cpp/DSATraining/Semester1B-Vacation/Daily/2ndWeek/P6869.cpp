/** 
 * @Author: Chenpi
 * @Date: 2025-07-21 19:55:48
 * @Link: https://www.luogu.com.cn/problem/P6869
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

struct edge {int v, c1, c2;};
vector<edge> g[N];
int fa[N][20], dep[N], cnt[N], cst1[N], cst2[N];

void dfs(int u, int p)
{
    dep[u] = dep[p] + 1;
    fa[u][0] = p;
    for (int i = 1; i <= 19; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (auto v : g[u]) 
    { 
        if (v.v == p) continue;
        cst1[v.v] = v.c1;
        cst2[v.v] = v.c2; 
        dfs(v.v, u);
    }
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

void dfs1(int u, int p)
{
    for (auto v : g[u])
    {
        if (v.v == p) continue;
        dfs1(v.v, u);
        cnt[u] += cnt[v.v];
    }
}

void solve()
{
    int n; cin >> n;
    for (int i = 1; i < n; i++)
    {
        int x, y, c1, c2; cin >> x >> y >> c1 >> c2;
        g[x].push_back({y, c1, c2}); 
        g[y].push_back({x, c1, c2});
    }
    dfs(1, 0);
    for (int i = 1; i < n; i++)
    {
        cnt[i]++, cnt[i + 1]++;
        cnt[lca(i, i + 1)]-=2;
    }
    dfs1(1, 0);
    int ans = 0;
    for (int i = 1; i <= n; i++) ans += min(cnt[i] * cst1[i], cst2[i]);
    cout << ans << endl;
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