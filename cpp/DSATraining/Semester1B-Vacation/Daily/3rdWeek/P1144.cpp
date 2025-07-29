/** 
 * @Author: Chenpi
 * @Date: 2025-07-28 16:26:46
 * @Link: https://www.luogu.com.cn/problem/P1144
 */

 #include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 1e6 + 5;
const int M = 100003;
const int inf = 0x3f3f3f3f;

int cnt[N], dis[N], vis[N];
vector<int> e[N];
priority_queue<PII> q; 

void dijkstra()
{
    dis[1] = 0; q.push({0, 1});
    cnt[1] = 1;
    while (q.size())
    {
        int u = q.top().second; q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int v : e[u])
        {
            if (dis[v] > dis[u] + 1)
            {
                cnt[v] = cnt[u] % M;
                dis[v] = dis[u] + 1;
                q.push({-dis[v], v});
            }
            else if (dis[v] == dis[u] + 1)
            {
                cnt[v] = (cnt[v] + cnt[u]) % M;
            }
        }
    }
}

void solve()
{
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 0; i <= n; i++) dis[i] = inf, cnt[i] = 0;
    dijkstra();
    for (int i = 1; i <= n; i++) cout << cnt[i] % M << endl;
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