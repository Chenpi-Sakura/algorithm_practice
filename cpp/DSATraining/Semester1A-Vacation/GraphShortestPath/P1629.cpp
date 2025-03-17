/*
题目描述
有一个邮递员要送东西，邮局在节点 1。他总共要送 n-1 样东西，其目的地分别是节点 2 到节点 n。由于这个城市的交通比较繁忙，因此所有的道路都是单行的，共有 m 条道路。这个邮递员每次只能带一样东西，并且运送每件物品过后必须返回邮局。求送完这 n-1 样东西并且最终回到邮局最少需要的时间。

输入格式
第一行包括两个整数，n 和 m，表示城市的节点数量和道路数量。
第二行到第 (m+1) 行，每行三个整数，u,v,w，表示从 u 到 v 有一条通过时间为 w 的道路。

输出格式
输出仅一行，包含一个整数，为最少需要的时间。
*/

/*
    有向图，我们可以做多源最短路径，
    起点到每个点和每个点到起点的最短距离，但是这样做时间复杂度过高
    
*/

// 朴素做法

#include<bits/stdc++.h> 
using namespace std;

const int N = 1e3 + 5;
const int inf = 0x3f;
struct edge{int v, w;};
vector<edge> e[N];
priority_queue<pair<int, int>> q;
int d[N], vis[N];
int n, m;

void dijkstra(int s)
{
    for (int i = 0; i <= n; i++) d[i] = inf, vis[i] = 0;
    d[s] = 0; q.push({0, s});
    while (q.size())
    {
        int u = q.top().second; q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto ed : e[u])
        {
            int v = ed.v, w = ed.w;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                q.push({-d[v], v});
            }
        }
    }
}

int main( )
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        e[u].push_back({v, w});
    }
    dijkstra(1);
    int ans = 0;
    for (int i = 1; i <= n; i++) ans += d[i];
    for (int i = 2; i <= n; i++)
    {
        dijkstra(i);
        ans += d[1];
    }

    cout << ans << endl;
    return 0;
}

// 优化做法，我们制作了反向图，
// 将 从每个点回到起点 的距离计算   转化为   从起点到每个点 的距离计算

#include<bits/stdc++.h> 
using namespace std;
#define int long long

const int N = 2e3 + 5;
const int inf = 0x3f3f3f3f;
struct edge{int v, w;};
vector<edge> e[N];
priority_queue<pair<int, int>> q;
int d[N], vis[N];
int n, m;

void dijkstra(int s)
{
    for (int i = 0; i <= 2 * n; i++) d[i] = inf;
    d[s] = 0; q.push({0, s});
    while (q.size())
    {
        int u = q.top().second; q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto ed : e[u])
        {
            int v = ed.v, w = ed.w;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                q.push({-d[v], v});
            }
        }
    }
}

signed main( )
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v, w; cin >> u >> v >> w;
        e[u].push_back({v, w});
        e[v + n].push_back({u + n, w});
    }
    dijkstra(1);
    int ans = 0;
    for (int i = 2; i <= n; i++) ans += d[i];
    dijkstra(1 + n);
    for (int i = 2 + n; i <= 2 * n; i++) ans += d[i];
    cout << ans << endl;
    return 0;
}