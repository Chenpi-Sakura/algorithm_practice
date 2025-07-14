#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

struct edge
{int u, v, w;};

int c[N], fa[N];
edge g[N];

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

int find(int n)
{
    if (fa[n] == n) return n;
    return fa[n] = find(fa[n]);
}

void solve()
{
    int n, p, s = inf; cin >> n >> p;
    for (int i = 1; i <= n; i++) {cin >> c[i]; s = min(c[i], s);}
    for (int i = 0; i < p; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        g[i] = {u, v, w * 2 + c[u] + c[v]};
    }
    sort(g, g + p, cmp);
    for (int i = 1; i <= n; i++) fa[i] = i;
    int r = 0, ans = s;
    for (int i = 0; r < n - 1; i++)
    {
        if (find(g[i].u) != find(g[i].v))
        {
            ans += g[i].w;
            fa[find(g[i].u)] = fa[find(g[i].v)];
            r++;
        }
    }
    cout << ans << endl;
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