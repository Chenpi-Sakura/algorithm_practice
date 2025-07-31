/** 
 * @Author: Chenpi
 * @Date: 2025-07-30 13:11:37
 * @Link: https://www.luogu.com.cn/problem/P2761
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
    int s = (1 << n) - 1;
    vector<pair<pair<PII, PII>, int>> patchs;
    for (int i = 0; i < m; i++)
    {
        int w; cin >> w;
        string b, f; cin >> b >> f;
        int b1 = 0, b2 = 0, f1 = 0, f2 = 0;
        for (int i = 0; i < n; i++)
        {
            if (b[i] == '+') b1 += (1 << i);
            else if (b[i] == '-') b2 += (1 << i);
            if (f[i] == '-') f1 += (1 << i);
            else if (f[i] == '+') f2 += (1 << i);
        }
        patchs.push_back({{{b1, b2}, {f1, f2}}, w});
    }

    vector<int> dis(1 << n, inf), vis(1 << n);
    priority_queue<PII> pq;
    dis[s] = 0;
    pq.push({0, s});

    while (pq.size())
    {
        int u = pq.top().second; pq.pop();
        if (u == 0) break;
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = 0; i < m; i++)
        {
            auto [ed, w] = patchs[i];
            int v = ((u & (~ed.second.first)) | ed.second.second);
            if (dis[u] + w < dis[v])
            {
                if (((u & ed.first.first) == ed.first.first) && ((u & ed.first.second) == 0))
                {
                    dis[v] = dis[u] + w;
                    pq.push({-dis[v], v});
                }
            }
        }
    }
    if (dis[0] == inf) cout << 0 << endl;
    else cout << dis[0] << endl;
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