/** 
 * @Author: Chenpi
 * @Date: 2025-07-31 11:04:33
 * @Link: https://codeforces.com/problemset/problem/1850/H
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

// 带权并查集

// int fa[N], dis[N];

// int find(int i)
// {
//     if (fa[i] == i) return i;
//     int fi = find(fa[i]);
//     dis[i] += dis[fa[i]];
//     return fa[i] = fi;
// }

// void solve()
// {
//     int n, m; cin >> n >> m;
//     for (int i = 1; i <= n; i++)
//     {
//         fa[i] = i;
//         dis[i] = 0;
//     }
//     int ans = 1;
//     for (int i = 0; i < m; i++)
//     {
//         int a, b, d; cin >> a >> b >> d;
//         if (!ans) continue;
//         int faa = find(a), fab = find(b);
//         if (faa != fab)
//         {
//             fa[fab] = faa;
//             dis[fab] = dis[a] - dis[b] + d;
//         }
//         else
//         {
//             if (dis[b] - dis[a] != d) ans = 0;
//         }
//     }
//     if (ans) cout << "YES" << endl;
//     else cout << "NO" << endl;
// }

// DFS

vector<PII> e[N];

int vis[N], pos[N];
int ans = 1;

void dfs(int u, int c)
{
    vis[u] = 1;
    pos[u] = c;

    for (auto [v, w] : e[u])
    {
        if (!ans) return;
        if (!vis[v]) dfs(v, c + w);
        else if (pos[v] != c + w) ans = 0;
    }
}

void solve()
{
    int n, m; cin >> n >> m;
    ans = 1;
    for (int i = 1; i <= n; i++)
    {
        e[i].clear();
        vis[i] = 0;
        pos[i] = 0;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, d; cin >> a >> b >> d;
        e[b].push_back({a, d});
        e[a].push_back({b, -d});
    }
    for (int i = 1; i <= n; i++) if (!vis[i] && ans) dfs(i, 0);
    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;
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