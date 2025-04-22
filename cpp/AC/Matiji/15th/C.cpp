#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

struct edge
{int v, w;};
vector<edge> e[N];
map<PII, bool> vis;
priority_queue<PII> q;

vector<int> w;
int a, b, ans;

void dfs(int u)
{
    if (u == b) 
    {
        if (w.size() >= 3)
        {
            vector<int> temp(w.begin(), w.end());
            sort(temp.begin(), temp.end());
            int i = temp[0], j = temp[1], k = temp[2];
            ans = min(ans, i * j + j * k + k * i);
            // cout << ans << endl;
            return;
        }
    }
    for(auto ed : e[u])
    {
        if (vis[{u, ed.v}]) continue;
        // cout << u << ' ' << ed.v << endl;
        vis[{u, ed.v}] = 1;
        w.push_back(ed.w);
        dfs(ed.v);
        vis[{u, ed.v}] = 0;
        w.pop_back();
    }
}

// void dijkstr(int s)
// {
//     q.push({0, s}); dis[s] = 0;
//     while (q.size())
//     {
//         int u = q.top().second; q.pop();
//     }
// }

void solve()
{
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    int t; cin >> t;
    while (t--)
    {
        cin >> a >> b;
        ans = inf;
        vis.clear();
        dfs(a);
        if (ans >= inf) cout << -1 << endl;
        else cout << ans << endl; 
    }
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