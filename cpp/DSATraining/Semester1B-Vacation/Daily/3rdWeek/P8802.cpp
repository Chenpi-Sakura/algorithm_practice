/** 
 * @Author: Chenpi
 * @Date: 2025-07-28 14:12:31
 * @Link: https://www.luogu.com.cn/problem/P8802
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 1e3 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int w[N], vis[N], dis[N];
vector<PII> g[N];
priority_queue<PII> q;

void dijkstra()
{
    dis[1] = 0; q.push({0, 1});
    while (q.size())
    {
        int u = q.top().second; q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v, c] : g[u])
        {
            if (dis[v] > dis[u] + c + w[v])
            {
                dis[v] = dis[u] + c + w[v];
                q.push({-dis[v], v});
            }
        }
    }
}

void solve()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 0; i < m; i++)
    {
        int u, v, c; cin >> u >> v >> c;
        g[u].push_back({v, c});
        g[v].push_back({u, c});
    }
    for (int i = 1; i <= n; i++) dis[i] = inf;
    dijkstra();
    cout << dis[n] - w[n] << endl;
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