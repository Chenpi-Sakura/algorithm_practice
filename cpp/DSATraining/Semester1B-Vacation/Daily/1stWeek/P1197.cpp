#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

struct edge{int x, y, w;};
int fa[N*2], vis[N*2], ans[N*2];
edge g[N];
int num;

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

int find(int x)
{
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

void merge(int x, int y)
{
    int fx = find(x), fy = find(y);
    if (fx != fy) fa[fx] = fy, num--;
}

void solve()
{
    int n, m; cin >> n >> m; num = n;
    for (int i = 0; i < n; i++) fa[i] = i;
    for (int i = 0; i < m; i++)
    {
        int x, y; cin >> x >> y;
        g[i] = {x, y, 0};
    }
    int k; cin >> k;
    for (int i = 1; i <= k; i++)
    {
        int x; cin >> x;
        vis[x] = k - i + 1;
    }
    for (int i = 0; i < m; i++) g[i].w = max(vis[g[i].x], vis[g[i].y]);
    sort(g, g + m, cmp);
    for (int i = 0, j = 0; i <= k; i++)
    {
        for (; g[j].w==i; j++) merge(g[j].x, g[j].y);
        ans[i] = num - (k - i);
    }
    for (int i = k; i >= 0; i--) cout << ans[i] << endl;
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