/** 
 * @Author: Chenpi
 * @Date: 2025-08-06 19:10:06
 * @Link: https://www.luogu.com.cn/problem/P9431
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 5e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f3f3f3f3fLL;

int dfn[N], low[N], tot;
int stk[N], instk[N], top;
int scc[N], siz[N], cnt;
vector<int> e[N], g[N];
int f[N], ans;

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

int dfs(int u)
{
    if (f[u]) return f[u];
    int res = 0;
    for (int v : g[u])
    {
        res = max(res, dfs(v));
    }
    return f[u] = siz[u] + res;
}

void solve()
{
    int n, d, c; cin >> n >> d >> c;
    cnt = 0, tot = 0, top = 0, ans = 0;
    for (int i = 0; i <= n; ++i) 
    {
        e[i].clear();
        g[i].clear();
        f[i] = 0;
        dfn[i] = 0;
        instk[i] = 0;
        siz[i] = 0;
    }
    vector<PII> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[j].second - a[i].second + abs(a[j].first - a[i].first) <= d) e[i].push_back(j);
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

    cout << dfs(scc[c]) << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    int T = 1, id;
    cin >> T >> id;
    while (T--) solve();
    return 0;
}