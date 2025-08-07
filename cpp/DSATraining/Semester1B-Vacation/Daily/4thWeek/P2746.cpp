/** 
 * @Author: Chenpi
 * @Date: 2025-08-06 09:21:21
 * @Link1: https://www.luogu.com.cn/problem/P2746
 * @Link2: https://www.luogu.com.cn/problem/P2812
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 1e4 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int dfn[N], low[N], tot;
int stk[N], instk[N], top;
int scc[N], siz[N], cnt;
vector<int> e[N];
int din[N], dout[N];

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
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        while (x)
        {
            e[i].push_back(x);
            cin >> x;
        }
    }

    for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);

    for (int u = 1; u <= n; u++)
    {
        for (int v : e[u])
        {
            int su = scc[u], sv = scc[v];
            if (su != sv)
            {
                din[sv]++; dout[su]++;
            }
        }
    }

    int ain = 0, aout = 0;
    for (int i = 1; i <= cnt; i++)
    {
        if (din[i] == 0) ain++;
        if (dout[i] == 0) aout++;
    }
    cout << ain << endl;
    cout << (cnt == 1 ? 0 : max(ain, aout)) << endl;
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