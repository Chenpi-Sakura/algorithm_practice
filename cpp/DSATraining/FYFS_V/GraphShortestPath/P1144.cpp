/*
最短路计数
题目描述
给出一个 N 个顶点 M 条边的无向无权图，顶点编号为 1 到 N。问从顶点 1 开始，到其他每个点的最短路有几条。

输入格式
第一行包含 2 个正整数 N,M，为图的顶点数与边数。
接下来 M 行，每行 2 个正整数 x,y，表示有一条连接顶点 x 和顶点 y 的边，请注意可能有自环与重边。

输出格式
共 N 行，每行一个非负整数，第 i 行输出从顶点 1 到顶点 i 有多少条不同的最短路，由于答案有可能会很大，你只需要输出 ans mod 100003 后的结果即可。如果无法到达顶点 i 则输出 0。
*/

/*
    最短路计数使用广搜，以保证每条路径都被搜索
*/

#include<bits/stdc++.h> 
#include <vector>
using namespace std;

const int inf = 0x3f3f3f3f;
const int N = 1e6 + 5;
const int M = 100003;
vector<int> e[N];
queue<int> q;
int d[N], cnt[N];
int n, m;

void bfs(int s)
{
    for (int i = 0; i <= n; i++) d[i] = inf;
    d[s] = 0; cnt[s] = 1; q.push(s);
    while (q.size())
    {
        int i = q.front(); q.pop();
        for (int j : e[i])
        {
            if (d[j] > d[i] + 1)
            {
                cnt[j] = cnt[i];
                d[j] = d[i] + 1;
                q.push(j);
            }
            else if (d[j] == d[i] + 1)
            {
                cnt[j] += cnt[i];
                cnt[j] %= M;
            }
        }
    }
}

int main( )
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int x, y; cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    bfs(1);
    for (int i = 1; i <= n; i++) cout << cnt[i] << endl;
    return 0;
}