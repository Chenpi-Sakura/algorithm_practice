#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 5;
vector<int> e[N];
deque<int> path;
int color[N];

int dfs(int u, int uu)
{
    if (color[u] == 1)
    {
        while (path.front() != u)
        {
            path.pop_front();
        }
        return u;
    }
    if (color[u] == 2) return 0;
    color[u] = 1;
    path.push_back(u);
    for (int v : e[u])
    {
        if (uu != v)
        {
            int x = dfs(v, u);
            if (x) return x;
        }
        
    }
    path.pop_back();
    color[u] = 2;
    return 0;
}

void solve()
{
    memset(color, 0, sizeof(color));
    while (path.size()) path.pop_back();
    for (int i = 0; i <= N; i++) e[i].clear();
    int n; cin >> n;

    while (n--)
    {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs(1, 1);
    int minN = N;
    for (int i : path) minN = min(minN, i);
    while (path[0] != minN)
    {
        path.push_back(path[0]);
        path.pop_front();
    }
    cout << path.size() << ' ';
    for (int i : path) cout << i << ' ';
    cout << endl;
}

int main()
{
    int t; cin >> t;
    while (t--) solve();
    return 0;
}