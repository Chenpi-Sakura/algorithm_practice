#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

struct edge
{int v, w;};
vector<edge> e[N];
vector<int> tp;
int din[N], in[N];
int n, m;

bool toposort(int s)
{
    queue<int> q; q.push(s);
    while (q.size())
    {
        int u = q.front(); q.pop();
        tp.push_back(u);
        for (auto ed : e[u])
        {
            int v = ed.v;
            if (--in[v] == 0) q.push(v);
        }
    }
    return tp.size() == n;
}

void solve()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        e[u].push_back({v, w});
        din[v]++; in[v]++;
    }
    int s;
    for (int i = 1; i <= n; i++) 
        if (din[i] == 0) s = i;
    
        if (!toposort(s))
    {
        cout << 0 << endl;
        return;
    }


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