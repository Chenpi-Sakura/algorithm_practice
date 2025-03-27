/*
    染色法判断是否有奇数环
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e7 + 5; 
vector<int> e[N];
int color[N];

bool dfs(int u, int c)
{
    color[u] = c;
    for (int v : e[u])
    {
        if (!color[v])
        {
            if (dfs(v, 3 - c)) return 1;
        }
        else if (color[v] == c) return 1;
    }
    return 0;
}

int main()
{
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    bool oddCycle = false;
    for (int i = 1; i <= n; i++)
    {
        if (!color[i])
        {
            if (dfs(i, 1))
            {
                oddCycle = true;
                break;
            }
        }
    }
    if (oddCycle) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}