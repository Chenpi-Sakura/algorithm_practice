/*
营救
题目背景
“咚咚咚……”“查水表！”原来是查水表来了，现在哪里找这么热心上门的查表员啊！小明感动得热泪盈眶，开起了门……

题目描述
妈妈下班回家，街坊邻居说小明被一群陌生人强行押上了警车！妈妈丰富的经验告诉她小明被带到了 t 区，而自己在 s 区。
该市有 m 条大道连接 n 个区，一条大道将两个区相连接，每个大道有一个拥挤度。小明的妈妈虽然很着急，但是不愿意拥挤的人潮冲乱了她优雅的步伐。所以请你帮她规划一条从 s 至 t 的路线，使得经过道路的拥挤度最大值最小。

输入格式
第一行有四个用空格隔开的 n，m，s，t，其含义见【题目描述】。
接下来 m 行，每行三个整数 u,v,w，表示有一条大道连接区 u 和区 v，且拥挤度为 w。
两个区之间可能存在多条大道。

输出格式
输出一行一个整数，代表最大的拥挤度。

*/

/*
    最短路径模板题
*/

#include<bits/stdc++.h> 
#include <vector>
using namespace std;

const int N = 1e4 + 10;
struct edge
{
    int u, v, w;
    bool operator < (const edge &t)const
    {return w < t.w;}
};
vector<edge> e;
int fa[N];
int n, m, s, t;

int find(int x)
{
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

int kruskal()
{
    sort(e.begin(), e.end());
    for (int i = 1; i <= n; i++) fa[i] = i;
    int maxW = 0;
    for (auto i : e)
    {
        if (find(s) == find(t)) return maxW;
        int x = find(i.u);
        int y = find(i.v);
        if (x != y)
        {
            fa[x] = y;
            maxW = max(maxW, i.w);
        }
    }
    return maxW;
}

int main( )
{
    cin >> n >> m >> s >> t;
    while (m--)
    {
        int u, v, w; cin >> u >> v >> w;
        e.push_back({u, v, w});
    }
    int ans = kruskal();
    cout << ans << endl;
    return 0;
}