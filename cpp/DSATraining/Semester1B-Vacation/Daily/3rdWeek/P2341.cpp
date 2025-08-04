/**
 * @Author: Chenpi
 * @Date: 2025-08-02 13:23:46
 * @Link: https://www.luogu.com.cn/problem/P2341
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
int dfn[N], low[N], tot;
int stk[N], instk[N], top;
int scc[N], siz[N], cnt;
int dout[N];

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
        while(u != v);
    }
}

void solve()
{
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        e[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);
    for (int u = 1; u <= n; u++)
    {
        for (int v : e[u])
        {
            // 此处的边是 v->u，因此对应的联通分量关系也为 v->u
            int su = scc[u], sv = scc[v];
            if (su != sv) dout[su]++;
        }
    }
    int ans = 0;
    for (int u = 1; u <= cnt; u++)
    {
        if (dout[u] == 0)
        {
            if (ans)
            {
                cout << 0 << endl;
                return;
            }
            ans = siz[u];
        } 
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