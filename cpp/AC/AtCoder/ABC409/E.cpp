#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

struct edge {int v, w;};
vector<edge> e[N];

int pw[N], din[N];

int cost = 0;

void dfs(int u, int fa)
{
    for (auto ed : e[u])
    {
        if (ed.v == fa) continue;
        dfs(ed.v, u);
        pw[u] += pw[ed.v];
        cost += ed.w * abs(pw[ed.v]);
    }
}

void solve()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> pw[i];
    for (int i = 1; i < n; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v].push_back({u, w});
    }
    dfs(1, 0);
    cout << cost << endl;
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