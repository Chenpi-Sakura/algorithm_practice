/*
7-1 列出连通集
给定一个有 n 个顶点和 m 条边的无向图，请用深度优先遍历（DFS）和广度优先遍历（BFS）分别列出其所有的连通集。假设顶点从 0 到 n−1 编号。进行搜索时，假设我们总是从编号最小的顶点出发，按编号递增的顺序访问邻接点。

输入格式:
输入第 1 行给出 2 个整数 n (0<n≤10) 和 m，分别是图的顶点数和边数。随后 m 行，每行给出一条边的两个端点。每行中的数字之间用 1 空格分隔。

输出格式:
按照输出样例的格式，每行输出一个连通集。先输出 DFS 的结果，再输出 BFS 的结果。

输入样例:
8 6
0 7
0 1
2 0
4 1
2 4
3 5
输出样例:
{ 0 1 4 2 7 }
{ 3 5 }
{ 6 }
{ 0 1 2 7 4 }
{ 3 5 }
{ 6 }
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

vector<int> e[20];
int vis[20];

void dfs(int x)
{
    cout << x << ' ';
    for (int i : e[x])
    {
        if (!vis[i]) 
        {
            vis[i] = 1;
            dfs(i);
        }
    }
}

void bfs(int x)
{
    queue<int> q; q.push(x);
    while (q.size())
    {
        int i = q.front(); q.pop();
        cout << i << ' ';
        for (int j : e[i])
        {    
            if (!vis[j]) 
            {
                vis[j] = 1;
                q.push(j);
            }
        }
    }
}

void solve()
{
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    for (int i = 0; i < n; i++) sort(e[i].begin(), e[i].end());
    for (int i = 0; i < n; i++)
    {
        if (!vis[i]) 
        {
            vis[i] = 1;
            cout << "{ ";
            dfs(i);
            cout << "}\n";
        }
    }
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++)
    {
        if (!vis[i]) 
        {
            vis[i] = 1;
            cout << "{ ";
            bfs(i);
            cout << "}\n";
        }
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