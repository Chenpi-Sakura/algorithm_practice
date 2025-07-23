/**
 * @Author: Chenpi
 * @Date: 2025-07-22 11:39:22
 * @Link: https://www.luogu.com.cn/problem/P8200
 */
#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 5e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

vector<PII> g[N];
int d[N];

void dfs(int u, int p)
{
    for (auto [v, w] : g[u])
    {
        if (v == p) continue;
        d[v] = d[u] ^ w;
        dfs(v, u);
    }
}

void solve()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        int a, b, l; cin >> a >> b >> l;
        g[a].push_back({b, l});
        g[b].push_back({a, l});
    }
    dfs(1, 0);
    while (m--)
    {
        int a, b, k; cin >> a >> b >> k;
        if ((d[a] ^ d[b]) == k) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
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