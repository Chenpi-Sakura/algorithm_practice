#include<bits/stdc++.h> 
using namespace std;

const int N = 1e5 + 5;
const int inf = 2e9;
struct edge {int v, w;};
vector<edge> e[N];
queue<int> q;
int d[N], vis[N], cnt[N];
int n, m, s;

bool spfa(int s)
{
    for (int i = 0; i <= n; i++) d[i] = inf;
    d[s] = 0; vis[s] = 1; q.push(s);
    while (q.size())
    {
        int u = q.front(); q.pop(); vis[u] = 0;
        for (auto ed : e[u])
        {
            int v = ed.v, w = ed.w;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] >= n) return true;
                if (!vis[v]) q.push(v), vis[v] = 1;
            }
        }
    }
    return false;
}

signed main( )
{
    cin >> n >> m >> s;
    while (m--)
    {
        int u, v, w; cin >> u >> v >> w;
        e[u].push_back({v, w});
    }
    spfa(s);
    for (int i = 1; i <= n; i++) cout << d[i] << ' ';
    return 0;
}