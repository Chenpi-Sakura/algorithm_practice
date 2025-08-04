/**
 * @Author: Chenpi
 * @Date: 2025-08-02 10:36:42
 * @Link:https://www.luogu.com.cn/problem/B3609
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 5e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

vector<int> e[N], g[N];
int dfn[N], low[N], tot;
int stk[N], instk[N], top;
int scc[N], siz[N], cnt;
int vis[N];

void tarjan(int u)
{
    dfn[u] = low[u] = ++tot;
    stk[++top] = u; instk[u] = 1;
    for (int v : e[u])
    {
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if (instk[v])
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (dfn[u] == low[u])
    {
        cnt++;
        int v;
        
        do
        {
            v = stk[top--];
            instk[v] = 0;
            scc[v] = cnt;
            siz[cnt]++;
            g[cnt].push_back(v);
        }
        while(u != v);
    }
}

void solve()
{
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);
    cout << cnt << endl;
    for (int i = 1; i <= n; i++)
    {
        if (vis[scc[i]]) continue;
        vis[scc[i]] = 1;
        sort(g[scc[i]].begin(), g[scc[i]].end());
        for (int x : g[scc[i]]) cout << x << ' ';
        cout << endl;
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
