/** 
 * @Author: Chenpi
 * @Date: 2025-07-28 15:23:06
 * @Link: https://www.luogu.com.cn/problem/P1462
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 1e4 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int n;
int f[N], vis[N], dis[N];
vector<PII> e[N];
priority_queue<PII> q;

void dijkstra(int x)
{
    for (int i = 1; i <= n; i++)
    {
        dis[i] = inf;
        vis[i] = 0;
    }
    while (q.size()) q.pop();
    dis[1] = 0; q.push({0, 1});
    while (q.size())
    {
        int u = q.top().second; q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [v, w] : e[u])
        {
            if (f[v] > x) continue;
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
    int m, hp; cin >> n >> m >> hp;
    int l = 0, r = 0;
    for (int i = 1; i <= n; i++) 
    {
        cin >> f[i];
        r = max(r, f[i]);
    }
    l = max(f[1], f[n]);
    for (int i = 1; i <= m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    int ans = -1;
    while (l <= r)
    {
        int mid = (l + r) / 2;
        dijkstra(mid);
        if (dis[n] <= hp)
        {
            ans = mid;
            r = mid - 1;
        } 
        else l = mid + 1;
    }
    if (ans != -1) cout << ans << endl;
    else cout << "AFK" << endl;
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