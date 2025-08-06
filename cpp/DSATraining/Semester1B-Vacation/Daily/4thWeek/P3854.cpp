/** 
 * @Author: Chenpi
 * @Date: 2025-08-04 20:25:48
 * @Link: https://www.luogu.com.cn/problem/P3854
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 2e4 + 5;
const int M = 1e5 + 5;
const int inf = 0x3f3f3f3f;

vector<int> g[N], tr[N + M];

int dfn[N], low[N], tot;
int stk[N], top;
int cut[N], id[N], bcnt;

int dep[N + M], fa[N + M][20];
int cnt;

void tarjan(int u, int rt)
{
    dfn[u] = low[u] = ++tot;
    stk[++top] = u;

    int ch = 0;
    for (int v : g[u])
    {
        if (!dfn[v])
        {
            ch++;
            tarjan(v, rt);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u])
            {
                if (u != rt) cut[u] = 1;
                bcnt++;
                int y;

                do
                {
                    y = stk[top--];
                    tr[N + bcnt].push_back(y);
                    tr[y].push_back(N + bcnt);
                }
                while (y != v);
                tr[N + bcnt].push_back(u);
                tr[u].push_back(N + bcnt);
            }
        }
        else low[u] = min(low[u], dfn[v]);
    }
    if (u == rt && ch > 1) cut[u] = true;
}

void dfs(int u, int p)
{
    dep[u] = dep[p] + 1;
    fa[u][0] = p;
    for (int i = 1; i <= 19; i++) fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (int v : tr[u]) if (v != p) dfs(v, u);
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
    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    tarjan(1, 1);
    cnt = n + bcnt;

    dfs(1, 0);

    int q; cin >> q;
    while (q--)
    {
        int s, t, m; cin >> s >> t >> m;
        if (!cut[m])
        {
            cout << "no" << endl;
            continue;
        }

        int sn = cut[s] ? s : tr[s][0];
        int tn = cut[t] ? t : tr[t][0];

        if (sn == tn)
        {
            cout << "no" << endl;
            continue;
        }

        int fa = lca(sn, tn);
        if ((lca(sn, m) == m && lca(tn, m) == fa) || lca(tn, m) == m && lca(sn, m) == fa) cout << "yes" << endl;
        else cout << "no" << endl;
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