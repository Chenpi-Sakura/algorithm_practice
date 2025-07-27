/** 
 * @Author: Chenpi
 * @Date: 2025-07-26 09:59:59
 * @Link: https://codeforces.com/gym/624417/problem/M
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 1e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

vector<int> g[N];
int sz[N], fa[N];

void dfs(int u, int p)
{
    sz[u] = 1; fa[u] = p;
    for (int v : g[u])
    {
        if (v == p) continue;
        dfs(v, u);
        sz[u] += sz[v];
    }
}

int find_leaf(int u, int p)
{
    if (g[u].size() == 1 && u != 1) return u;
    for (int v : g[u])
    {
        if (v == p) continue;
        return find_leaf(v, u);
    }
}

void solve()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++) g[i].clear();
    int u = 0, v = 0;
    for (int i = 1; i < n; i++)
    {
        int x, y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
        if (i == 1) {u = x; v = y;}
    }
    dfs(1, 0);
    int zx = -1;
    for (int i = 2; i <= n; i++)
    {
        if (sz[i] == n / 2)
        {
            zx = i;
            break;
        }
    }
    if (zx == -1 || n % 2 != 0)
    {
        cout << u << ' ' << v << endl;
        cout << u << ' ' << v << endl;
    }
    else
    {
        int leaf = find_leaf(zx, fa[zx]);
        cout << leaf << " " << fa[leaf] << endl;
        cout << leaf << " " << fa[zx] << endl;
    }
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