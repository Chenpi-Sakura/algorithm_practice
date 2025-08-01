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

    for (auto ed : e[x])
    {
        int y = ed.first;
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
    int n, k; cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int x, a, b; cin >> x >> a >> b;
        if (x == 1) {e[a].push_back({b, 0}); e[b].push_back({a, 0});}
        else if (x == 2) {if (a == b) {cout << -1 << endl; return; } e[a].push_back({b, 1});}
        else if (x == 3) {e[b].push_back({a, 0});}
        else if (x == 4) {if (a == b) {cout << -1 << endl; return; } e[b].push_back({a, 1});}
        else {e[a].push_back({b, 0});}
    }

    for (int i = 1; i <= n; i++) if (!dfn[i]) tarjan(i);
    for (int u = 1; u <= n; u++)
    {
        for (auto [v, w] : e[u])
        {
            int su = scc[u], sv = scc[v];
            // 假如两个节点存在于同一个强连通分量
            if (su == sv)
            {
                if (w > 0)
                {// 假如此时边权大于0，则一定会形成一个正权环
                    cout << -1 << endl;
                    return;
                }
            }
            else 
            {
                g[su].push_back({sv, w});
                din[sv]++;
            }
        }
    }

    // topoSort
    queue<int> q;
    for (int i = 1; i <= cnt; i++)
    {
        dis[i] = 1;
        if (din[i] == 0) q.push(i);
    }

    while (q.size())
    {
        int u = q.front(); q.pop();
        for (auto [v, w] : g[u])
        {
            dis[v] = max(dis[v], dis[u] + w);
            din[v]--;
            if (din[v] == 0) q.push(v);
        }
    }

    int ans = 0;
    for (int i = 1; i <= cnt; i++) ans += dis[i] * siz[i];
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