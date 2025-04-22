#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1005; // 节点数最大1000，所以N取1005
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

vector<int> adj[N];
int degree[N];
int fa[N];

int find(int x)
{
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

void solve()
{
    int n, m;
    cin >> n >> m;

    if (m == 0) // 没有边就没有欧拉回路（除非是1个点0条边，但题意是走过桥，所以m=0直接0）
    {
        cout << 0 << endl;
        return;
    }

    iota(fa, fa + n + 1, 0);

    for (int i = 0; i < m; ++i)
    {
        int u, v; cin >> u >> v;
        fa[find(u)] = find(v);
        degree[u]++;
        degree[v]++;
    }

    // 检查度数
    for (int i = 1; i <= n; ++i)
    {
        if (degree[i] % 2 != 0)
        {
            cout << 0 << endl;
            return;
        }
    }

    int cnt = 0;
    // 找到一个度数大于0的顶点作为起点
    for (int i = 1; i <= n; i++)
    {
        if (i == find(i)) cnt++;
    }
    if (cnt > 1) cout << 0 << endl;
    // 两项检查都通过，存在欧拉回路
    else cout << 1 << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); //cout.tie(0);
    int t; // cin >> t;
    t = 1;
    while (t--) solve();
    return 0;
}