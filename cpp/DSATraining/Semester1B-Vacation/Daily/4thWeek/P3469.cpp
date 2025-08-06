/** 
 * @Author: Chenpi
 * @Date: 2025-08-05 19:52:05
 * @Link: https://www.luogu.com.cn/problem/P3469
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 1e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int dfn[N], low[N], tot;
int sz[N], ans[N];
int n;

vector<int> g[N];

void tarjan(int u, int p)
{
    dfn[u] = low[u] = ++tot;
    sz[u] = 1;

    int ch = 0, chsz = 0, sum = 0;

    for (int v : g[u])
    {
        if (v == p) continue;
        if (!dfn[v])
        {
            ch++;
            tarjan(v, u);

            sz[u] += sz[v];
            low[u] = min(low[u], low[v]);

            if (low[v] >= dfn[u])
            {
                chsz += sz[v];
                sum += sz[v] * sz[v];
            }
        }
        else low[u] = min(low[u], dfn[v]);
    }

    ans[u] = 2 * (n - 1);
    if ((p == 0 && ch > 1) || (p != 0 && chsz > 0))
    {
        int x = n - 1 - chsz;
        sum += x * x;
        ans[u] += (n - 1) * (n - 1) - sum;
    }
}

void solve()
{
    int m; cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    tarjan(1, 0);

    for (int i = 1; i <= n; i++) cout << ans[i] << endl;
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