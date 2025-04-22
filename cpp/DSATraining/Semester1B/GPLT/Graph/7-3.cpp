#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

struct edge
{int v, w;};
vector<edge> e[105];
int vis[105], dis[105];
priority_queue<PII> q;

void Dijkstr(int s)
{
    memset(dis, inf, sizeof(dis));
    memset(vis, 0, sizeof(vis));
    dis[s] = 0; q.push({0, s});
    while (q.size())
    {
        int u = q.top().second; q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto ed : e[u])
        {
            int v = ed.v, w = ed.w;
            if (dis[u] + w < dis[v])
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
        e[v].push_back({u, w});
    }
    int minMaxV = inf, minI = 0;;
    for (int i = 1; i <= n; i++)
    {
        Dijkstr(i);
        int maxV = -1;
        for (int j = 1; j <= n; j++)
        {
            if (dis[j] >= inf)
            {
                cout << 0 << endl;
                return;
            }
            if (i != j) maxV = max(maxV, dis[j]);
        }
        if (maxV < minMaxV)
        {
            minMaxV = maxV;
            minI = i;
        }
    }
    cout << minI << ' ' << minMaxV << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); //cout.tie(0);
    int t; // cin >> t;
    t = 1;
    while (t--) solve();
    return 0;
}