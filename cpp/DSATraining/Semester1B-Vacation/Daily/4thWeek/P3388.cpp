/**
 * @Author: Chenpi
 * @Date: 2025-08-04 19:07:50
 * @Link: https://www.luogu.com.cn/problem/P3388
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 2e4 + 5;
const int M = 2e5 + 7;
const int inf = 0x3f3f3f3f;

int dfn[N], low[N], tot;
struct {int v, ne;} e[M];
int h[N], idx;

set<int> res;
int rt, cnt;

void add(int u, int v)
{
    e[idx] = {v, h[u]};
    h[u] = idx++;
}

void tarjan(int u, int ed)
{
    dfn[u] = low[u] = ++tot;

    for (int i = h[u]; ~i; i = e[i].ne)
    {
        if (i == (ed ^ 1)) continue;
        int v = e[i].v;
        if (!dfn[v])
        {
            if (u == rt) cnt++;
            tarjan(v, i);
            low[u] = min(low[u], low[v]);

            if (low[v] >= dfn[u]) res.insert(u);
        }
        else
        {
            low[u] = min(low[u], dfn[v]);
        }
    }
}

void solve()
{
    int n, m; cin >> n >> m;
    memset(h, -1, sizeof(h));

    for (int i = 1; i <= m; i++)
    {
        int u, v; cin >> u >> v;
        add(u, v); add(v, u);
    }

    for (int i = 1; i <= n; i++) 
    {
        if (!dfn[i])
        {
            rt = i; cnt = 0;
            tarjan(i, -1);
            if (cnt < 2) res.erase(i);
        } 
    }
    
    vector<int> ans(res.begin(), res.end());
    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for (int x : ans) cout << x << ' ';
    cout << endl;
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