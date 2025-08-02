/** 
 * @Author: Chenpi
 * @Date: 2025-07-30 20:21:16
 * @Link: https://codeforces.com/gym/626001/problem/E
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

// DFS

// int w[N], cost[N];
// unordered_map<int, int> e[N];

// int dfs(int u)
// {
//     int res = 0;
//     if (e[u].size() == 0) return w[u];
//     for (auto [v, n] : e[u]) 
//     {
//         if (cost[v] >= inf) cost[v] = min(w[v], dfs(v) * n);
//         res += cost[v];
//     }
//     return res;
// }

// void solve()
// {
//     int n, k; cin >> n >> k;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> w[i];
//         e[i].clear();
//         cost[i] = inf;
//     } 
//     for (int i = 0; i < k; i++)
//     {
//         int id; cin >> id;
//         w[id] = 0; cost[id] = 0;
//     }
//     for (int i = 1; i <= n; i++)
//     {
//         int m; cin >> m;
//         for (int j = 0; j < m; j++)
//         {
//             int x; cin >> x;
//             if (w[i] == 0) continue; // 假如本身就是无限供应，我们就不需要储存配方了
//             e[i][x]++;
//         }
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         if (cost[i] >= inf) cost[i] = min(w[i], dfs(i));
//         cout << cost[i] << ' ';
//     }
//     cout << endl;
// }

// Topo

vector<int> e[N];
int din[N], c[N];

void solve()
{
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) 
    {
        e[i].clear();
        cin >> c[i];
    }
    for (int i = 1; i <= k; i++)
    {
        int p; cin >> p;
        c[p] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        int m; cin >> m;
        din[i] += m;
        for (int j = 0; j < m; j++)
        {
            int x; cin >> x;
            e[x].push_back(i);
        }
    }
    
    queue<int> q;
    vector<int> ans(n + 1), mc(n + 1);
    for (int i = 1; i <= n; i++) if (din[i] == 0) {ans[i] = c[i]; q.push(i);}
    
    while (q.size())
    {
        int u = q.front(); q.pop();
        for (int v : e[u])
        {
            mc[v] += ans[u];
            din[v]--;
            if (din[v] == 0)
            {
                ans[v] = min(c[v], mc[v]);
                q.push(v);
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << endl;
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