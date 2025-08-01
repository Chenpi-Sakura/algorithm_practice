/** 
 * @Author: Chenpi
 * @Date: 2025-07-30 10:55:06
 * @Link: https://codeforces.com/problemset/problem/1846/G
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 5e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

void solve()
{
    int n, m; cin >> n >> m;
    int sz = 1 << (n + 1);
    string ss; cin >> ss; 
    int s = stoll(ss, 0, 2);
    vector<pair<PII, int>> g;
    for (int i = 0; i < m; i++)
    {
        int d; cin >> d;
        string su, sv; cin >> su >> sv;
        int u = stoll(su, 0, 2), v = stoll(sv, 0, 2);
        g.push_back({{u, v}, d});
    }
    vector<int> dis(sz, inf), vis(sz);
    priority_queue<PII> pq;
    dis[s] = 0;
    pq.push({0, s});
    while (pq.size())
    {
        int u = pq.top().second; pq.pop();
        if (u == 0) break;
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto [ed, w] : g)
        {
            int v = (u & (~ed.first)) | ed.second;
            if (dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                pq.push({-dis[v], v});
            }
        }
    }
    if (dis[0] != inf) cout << dis[0] << endl;
    else cout << -1 << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}