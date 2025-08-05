/** 
 * @Author: Chenpi
 * @Date: 2025-08-04 15:00:19
 * @Link: 
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
int ew[N], gw[N], f[N], din[N];

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
        }
        while (u != v);
    }
}

void solve()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> ew[i];
    for (int i = 1; i <= m; i++)
    {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);
    for (int u = 1; u <= n; u++)
    {
        int su = scc[u];
        gw[su] += ew[u];
        for (int v : e[u])
        {
            int sv = scc[v];
            if (su != sv)
            {
                g[su].push_back(sv);
                din[sv]++;
            }
        }
    }
    queue<int> q;
    for (int i = 1; i <= cnt; i++)
    {
        if (!din[i]) 
        {
            q.push(i);
            f[i] = gw[i];
        }
    }
    while (q.size())
    {
        int u = q.front(); q.pop();
        for (int v : g[u])
        {
            f[v] = max(f[v], f[u] + gw[v]);
            din[v]--;
            if (din[v] == 0) q.push(v);
        } 
    }
    int ans = 0;
    for (int i = 1; i <= cnt; i++) ans = max(ans, f[i]);

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