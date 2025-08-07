/** 
 * @Author: Chenpi
 * @Date: 2025-08-06 10:55:46
 * @Link: https://www.luogu.com.cn/problem/P4306
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 2e3 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int dfn[N], low[N], tot;
int stk[N], instk[N], top;
int scc[N], siz[N], cnt;
vector<int> e[N], g[N];
bitset<N> f[N];
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

    if (low[u] == dfn[u])
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

void dfs(int u)
{
    if (vis[u]) return;
    vis[u] = true;
    f[u][u] = 1;

    for (int v : g[u])
    {
        dfs(v);
        f[u] |= f[v];
    }
}

void solve()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        string s; cin >> s;
        for (int j = 0; j < s.size(); j++)
        {
            if (s[j] == '1') e[i].push_back(j + 1);
        }
    }

    for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);

    for (int u = 1; u <= n; u++)
    {
        for (int v : e[u])
        {
            int su = scc[u], sv = scc[v];
            if (su != sv) g[su].push_back(sv);
        }
    }

    for (int i = 1; i <= cnt; i++) if (!vis[i]) dfs(i);

    int ans = 0;
    for (int i = 1; i <= cnt; i++)
    {
        int x = 0;
        for (int j = 1; j <= cnt; j++)
        {
            if (f[i][j]) x += siz[j];
        }
        ans += siz[i] * x;
    }
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