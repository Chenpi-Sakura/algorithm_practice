/** 
 * @Author: Chenpi
 * @Date: 2025-07-28 10:32:16
 * @Link: https://www.luogu.com.cn/problem/P2863
 */

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 1e4 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

vector<int> e[N];
int dfn[N], low[N], tot;
int stk[N], instk[N], top;
int scc[N], siz[N], cnt;

void tarjan(int x)
{
    dfn[x] = low[x] = ++tot;
    stk[++top] = x; instk[x] = 1;

    for (int y : e[x])
    {
        if (!dfn[y])
        {
            tarjan(y);
            low[x] = min(low[x], low[y]);
        }
        else if (instk[y])
        {
            low[x] = min(low[x], dfn[y]);
        }
    }

    if (dfn[x] == low[x])
    {
        cnt++;
        int y;

        do
        {
            y = stk[top--];
            instk[y] = 0;
            scc[y] = cnt;
            ++siz[cnt];
        } while (y != x);
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
    for (int i = 1; i <= n; i++) if(!dfn[i]) tarjan(i);
    int ans = 0;
    for (int i = 1; i <= cnt; i++) if (siz[i] > 1) ans++;
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