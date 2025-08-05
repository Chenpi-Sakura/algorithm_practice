/** 
 * @Author: Chenpi
 * @Date: 2025-08-04 20:25:48
 * @Link: https://www.luogu.com.cn/problem/P3854
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 2e4 + 5;
const int M = 1e5 + 5;
const int inf = 0x3f3f3f3f;

vector<int> g[N], t[N * 2];

int dfn[N], low[N], tot;
int stk[N], top;
int cut[N], id[N], bcnt;

int dep[N * 2], fa[N * 2][19];
int cnt;

void tarjan(int u, int rt)
{
    dfn[u] = low[u] = ++tot;
    stk[++top] = u;

    int ch = 0;
    for (int v : g[u])
    {
        if (!dfn[v])
        {
            ch++;
            tarjan(v, rt);
            low[u] = min(low[u], low[v]);
            if (low[v] >= dfn[u])
            {
                if (u != rt) cut[u] = 1;
                bcnt++;
                int y;

                do
                {
                    y = stk[top--];
                    t[N + bcnt].push_back(y);
                    t[y].push_back(N + bcnt);
                }
                while (y != v);
                t[N + bcnt].push_back(u);
                t[u].push_back(N + bcnt);
            }
        }
        else low[u] = min(low[u], dfn[v]);
    }
    if (u == rt && ch > 1) cut[u] = true;
}

void dfs(int u, int p)
{
    
}

void solve()
{
    
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