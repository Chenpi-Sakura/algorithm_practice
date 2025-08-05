/**
 * @Author: Chenpi
 * @Date: 2025-08-04 15:57:32
 * @Link: https://www.luogu.com.cn/problem/P8435
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 5e5 + 5;
const int M = 4e6 + 5;
const int inf = 0x3f3f3f3f;

struct {int v, ne;} e[M];
int h[N], idx;
int dfn[N], low[N], tot;
int stk[N], top;
vector<int> edcc[N];
int cnt, dcc[N];

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
        int v = e[i].v;
        if (i == (ed ^ 1)) continue;
        if (!dfn[v])
        {
            tarjan(v, i);
            low[u] = min(low[u], low[v]);

            if (low[v] >= dfn[u])
            {
                cnt++;
                int y;

                do
                {
                    y = stk[top--];
                    dcc[y] = cnt;
                    edcc[cnt].push_back(y);
                }
                while (y != v);
                edcc[cnt].push_back(u);
                dcc[u] = cnt;
            }
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

    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        if (u == v) continue;
        add(u, v); add(v, u);
    }

    for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i, -1);

    for (int i = 1; i <= n; i++) if (!dcc[i]) edcc[++cnt].push_back(i);

    cout << cnt << endl;
    for (int i = 1; i <= cnt; i++)
    {
        cout << edcc[i].size();
        for (int x : edcc[i]) cout << ' ' << x;
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