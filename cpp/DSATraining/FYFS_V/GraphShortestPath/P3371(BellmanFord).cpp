#include<bits/stdc++.h> 
using namespace std;

const int N = 1e5 + 5;
const int inf = 2e9;
struct edge
{int v, w;};
vector<edge> e[N];
int d[N];
int n, m, s;

bool bellmanford(int s)
{
    for (int i = 0; i <= n; i++) d[i] = inf;
    d[s] = 0;
    bool flag;
    for (int i = 1; i <= n; i++)
    { // n 轮次
        flag = false;
        for (int j = 1; j <= n; j++)
        { // 第 n 点
            if(d[j] == inf) continue;
            for (auto ed : e[j])
            { 
                int v = ed.v, w = ed.w;
                if (d[v] > d[j] + w)
                {
                    d[v] = d[j] + w;
                    flag = true;
                }
            }
        }
        if (!flag) break;
    }
    return flag;
}

signed main( )
{
    cin >> n >> m >> s;
    while (m--)
    {
        int u, v, w; cin >> u >> v >> w;
        e[u].push_back({v, w});
    }
    bellmanford(s);
    for (int i = 1; i <= n; i++) cout << d[i] << ' ';
    return 0;
}