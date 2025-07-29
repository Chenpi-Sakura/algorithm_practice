/** 
 * @Author: Chenpi
 * @Date: 2025-07-28 09:13:03
 * @Link: https://www.luogu.com.cn/problem/P1073
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 1e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int n, m; 
int w[N], dmin[N], dmax[N], vis[N];
vector<int> g[N], gr[N];

void spfa1()
{
    for (int i = 1; i <= n; i++)
    {
        dmin[i] = inf;
        vis[i] = 0;
    }
    queue<int> q; q.push(1);
    dmin[1] = w[1]; vis[1] = 1;
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        vis[u] = 0;
        for (int v : g[u])
        {
            if (min(dmin[u], w[v]) < dmin[v])
            {
                dmin[v] = min(dmin[u], w[v]);
                if (!vis[v]) 
                {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
}

void spfa2()
{
    for (int i = 1; i <= n; i++)
    {
        dmax[i] = -inf;
        vis[i] = 0;
    }
    queue<int> q; q.push(n);
    dmax[n] = w[n]; vis[n] = 1;
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        vis[u] = 0;
        for (int v : gr[u])
        {
            if (max(dmax[u], w[v]) > dmax[v])
            {
                dmax[v] = max(dmax[u], w[v]);
                if (!vis[v])
                {
                    q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> w[i];
    for (int i = 0; i < m; i++)
    {
        int x, y, z; cin >> x >> y >> z;
        g[x].push_back(y);
        gr[y].push_back(x);
        if (z == 2) 
        {
            g[y].push_back(x);
            gr[x].push_back(y);
        }
    }

    spfa1();
    spfa2();

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (dmin[i] != inf && dmax[i] != -inf)
        {
            ans = max(ans, dmax[i] - dmin[i]);
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
    // cin >> T;
    while (T--) solve();
    return 0;
}