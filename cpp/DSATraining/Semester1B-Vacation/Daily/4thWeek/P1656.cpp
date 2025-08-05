/** 
 * @Author: Chenpi
 * @Date: 2025-08-04 09:21:52
 * @Link: https://www.luogu.com.cn/problem/P1656
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 155;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int dfn[N], low[N], tot;
int stk[N], instk[N], top;
int scc[N], siz[N], cnt;
vector<int> e[N];
vector<PII> ans;

void tarjan(int u, int fa)
{
    dfn[u] = low[u] = ++tot;
    
    for (int v : e[u])
    {
        if (v == fa) continue;
        if (!dfn[v])
        {
            tarjan(v, u);
            low[u] = min(low[u], low[v]);

            // 从v出发，是否存在其他路径可以绕回u或者到达比u更早的祖先？
            if (low[v] > dfn[u]) ans.push_back({min(u, v), max(u, v)});
        }
        else low[u] = min(low[u], dfn[v]);
    }
}

void solve()
{
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        e[a].push_back(b);
        e[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i, i);

    sort(ans.begin(), ans.end());

    for (auto x : ans) cout << x.first << ' ' << x.second << endl;
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