/**
 * @Author: Chenpi
 * @Date: 2025-08-04 11:39:41
 * @Link: https://www.luogu.com.cn/problem/P8436
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 5e5 + 5;
const int M = 2e6 + 5;
const int inf = 0x3f3f3f3f;

int dfn[N], low[N], tot;
int stk[N], top;
int cnt;
vector<int> ebcc[N];
struct {int v, ne;} e[M * 2];
int h[N], idx;

void add(int u, int v)
{
    e[idx] = {v, h[u]};
    h[u] = idx++;
}

void tarjan(int u, int ed)
{
    dfn[u] = low[u] = ++tot;
    stk[++top] = u;

    for (int i = h[u]; ~i; i = e[i].ne)
    {
        if (i == (ed ^ 1)) continue;
        int v = e[i].v;
        if (!dfn[v])
        {
            tarjan(v, i);
            low[u] = min(low[u], low[v]);
        }
        else
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
            ebcc[cnt].push_back(v);
        }
        while (v != u);
    }
}

void solve()
{
    int n, m; cin >> n >> m;
    memset(h, -1, sizeof(h));

    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        if (u == v) continue;
        add(u, v); add(v, u);
    }

    for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i, -1);

    cout << cnt << endl;
    for (int i = 1; i <= cnt; i++)
    {
        cout << ebcc[i].size();
        for (int x : ebcc[i]) cout << ' ' << x;
        cout << endl;
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