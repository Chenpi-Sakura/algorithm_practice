/** 
 * @Author: Chenpi
 * @Date: 2025-07-30 14:15:53
 * @Link: https://www.luogu.com.cn/problem/P1993
 * @Description: 差分约束
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 5e3 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

vector<PII> g[N];
int n;

bool spfa(int s)
{
    vector<int> dis(n + 1, inf), vis(n + 1), cnt(n + 1);
    queue<int> q;
    dis[s] = 0; vis[s] = 1; q.push(s);
    while (q.size())
    {
        int u = q.front(); q.pop();
        vis[u] = 0;
        for (auto [v, w] : g[u])
        {
            if (dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                cnt[v]++;
                if (cnt[v] > n) return false;
                if (!vis[v]) q.push(v), vis[v] = 1;
            }
        }
    }
    return true;
}

void solve()
{
    int m; cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        g[0].push_back({i, 0});
    }
    for (int i = 0; i < m; i++)
    {
        int op, a, b; cin >> op >> a >> b;
        if (op == 1)
        {
            int c; cin >> c;
            g[a].push_back({b, -c});
        }
        else if (op == 2)
        {
            int c; cin >> c;
            g[b].push_back({a, c});
        }
        else 
        {
            g[a].push_back({b, 0});
            g[b].push_back({a, 0});
        }
    }
    if (spfa(0)) cout << "Yes" << endl;
    else cout << "No" << endl;
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