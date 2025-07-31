/** 
 * @Author: Chenpi
 * @Date: 2025-07-30 15:52:10
 * @Link: https://www.luogu.com.cn/problem/P3275
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
int stk[N], instk[N], top;
int scc[N], siz[N], cnt;

vector<PII> e[N], g[N];
int din[N], dis[N];

void tarjan(int x)
{
    dfn[x] = low[x] = ++tot;
    stk[++top] = x; instk[x] = 1;

    for (int y : e[x])
    {
        if (!dfn[y])
        {
            tarjan(y);
            
        }
    }
}

void solve()
{
    int n, k; cin >> n >> k;
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