#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e3 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

struct edge {int v, w;};
vector<edge> g[N];
int dis[N], cnt[N], vis[N];
priority_queue<PII, vector<PII>, greater<PII>> q;

void solve()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> dis[i];
        cnt[i]++;
        q.push({dis[i], i});
    }
    int a, b, c;
    while (cin >> a >> b >> c)
    {
        g[a].push_back({b, c});
        if (a == b) continue;
        g[b].push_back({a, c});
    }
    while (q.size())
    {
        int u = q.top().second; q.pop();
        if (vis[u]) continue;
        vis[u] = 1;

        for (auto [v, c] : g[u])
        {
            if (!vis[v]) continue;
            int cost = dis[u] + dis[v];
            int ways = cnt[u] * cnt[v];
            if (cost < dis[c])
            {
                dis[c] = cost;
                cnt[c] = ways;
                q.push({dis[c], c});
            }
            else if (cost == dis[c])
            {
                cnt[c] += ways;
            }
        }
    }
    cout << dis[0] << ' ' << cnt[0] << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}