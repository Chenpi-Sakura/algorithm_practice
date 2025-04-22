#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 5e2 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

struct edge
{int v, w, f;};
vector<edge> e[N];
int dis[N], vis[N], fee[N];
priority_queue<pair<PII, int>> q;

void dijkstr(int s)
{
    memset(dis, inf, sizeof(dis));
    q.push({{0, 0}, s}); dis[s] = 0;
    while (q.size())
    {
        int u = q.top().second; q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto ed : e[u])
        {
            int v = ed.v, w = ed.w, f = ed.f;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                fee[v] = fee[u] + f;
                q.push({{-dis[v], -fee[v]}, v});
            }
            else if (dis[v] == dis[u] + w)
            {
                if (fee[v] > fee[u] + f)
                {
                    fee[v] = fee[u] + f;
                    q.push({{-dis[v], -fee[v]}, v});
                }
            }
        }
    }
}

void solve()
{
    int n, m, s, d; cin >> n >> m >> s >> d;
    for (int i = 0; i < m; i++)
    {
        int u, v, w, f; cin >> u >> v >> w >> f;
        e[u].push_back({v, w, f});
        e[v].push_back({u, w, f});
    }
    dijkstr(s);
    cout << dis[d] << ' ' << fee[d] << endl;
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