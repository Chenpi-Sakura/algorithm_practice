#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 3e3 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

struct edge
{int u, v, w;} e[N];
int fa[N], n, m, ans;

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

int find(int x)
{
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

bool kruskal()
{
    int cnt = 0;
    sort(e, e + m, cmp);
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 0; i < m; i++)
    {
        int x = find(e[i].u);
        int y = find(e[i].v);
        if (x != y)
        {
            fa[x] = y;
            ans += e[i].w;
            cnt++;
        }
    }
    // cout << cnt << endl;
    return cnt == n - 1;
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        e[i] = {u, v, w};
    }
    if (kruskal()) cout << ans << endl;
    else cout << -1 << endl;
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