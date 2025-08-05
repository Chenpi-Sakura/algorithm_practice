/** 
 * @Author: Chenpi
 * @Date: 2025-08-04 14:00:29
 * @Description: 链式向前星
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 5e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

struct edge {int v, w, ne;} e[N];
int h[N], idx;

void add(int u, int v, int w)
{
    e[idx] = {v, w, h[u]};
    h[u] = idx++;
}

void dfs(int u, int fa)
{
    for (int i = h[u]; ~i; i = e[i].ne)
    {
        int v = e[i].v, w = e[i].w;
        if (v == fa) continue;
        cout << u << ' ' << v << ' ' << w << endl;
        dfs(v, u);
    }
}

void solve()
{
    int n, m; cin >> n >> m;
    memset(h, -1, sizeof(h));
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        add(u, v, w);
    }

    dfs(1, 0);
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