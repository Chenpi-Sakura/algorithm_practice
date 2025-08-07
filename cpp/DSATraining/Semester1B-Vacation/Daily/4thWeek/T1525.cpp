/** 
 * @Author: Chenpi
 * @Date: 2025-08-06 20:44:59
 * @Link: https://vjudge.net/problem/LibreOJ-10103
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 1e4 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f3f3f3f3fLL;

int dfn[N], low[N], tot;
int ch[N];
vector<int> e[N];
int p, c;

void tarjan(int u, int fa)
{
    dfn[u] = low[u] = ++tot;
    int chsiz = 0;
    int spch = 0;

    for (int v : e[u])
    {
        chsiz++;
        if (v == fa) continue;
        if (!dfn[v])
        {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[v]) spch++;
        }
        else low[u] = min(low[u], dfn[v]);
    }

    if (fa == -1) ch[u] = max(1LL, chsiz);
    else ch[u] = spch + 1;
}

void solve()
{
    tot = 0;
    for(int i = 0; i <= p; i++)
    {
        e[i].clear();
        ch[i] = 0;
        dfn[i] = 0;
        low[i] = 0;
    }

    for(int i = 0; i < c; i++)
    {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    if (p == 1 || p == 0)
    {
        cout << 0 << endl;
        return;
    }

    int res = 0;

    for (int i = 0; i < p; i++)
    {
        if (!dfn[i])
        {
            tarjan(i, -1);
            res++;
        }
    }
    
    int ans = 0;
    
    for (int i = 0; i < p; i++)
    {
        if (e[i].empty()) ans = max(ans, res - 1);
        else ans = (ans, res - 1 + ch[i]);
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    cin >> p >> c;
    while (p || c)
    {
        solve();
        cin >> p >> c;
    }
    return 0;
}