/** 
 * @Author: Chenpi
 * @Date: 2025-07-28 14:45:59
 * @Link: https://www.luogu.com.cn/problem/P1629
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 2e3 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int dis[N], vis[N];
vector<PII> e[N];
priority_queue<PII> q;

void dijkstra(int s)
{
    dis[s] = 0; q.push({0, s});
    while (q.size())
    {
        int u = q.top().second; q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v, w] : e[u])
        {
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                q.push({-dis[v], v});
            }
        }
    } 
}

void solve()
{
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v + n].push_back({u + n, w});
    }
    for (int i = 1; i <= n * 2; i++) dis[i] = inf; 
    dijkstra(1);
    dijkstra(n + 1);
    int ans = 0;
    for (int i = 1; i <= n * 2; i++) ans += dis[i];
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