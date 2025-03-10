/*
题目背景
还记得 NOIP 2011 提高组 Day1 中的铺地毯吗？时光飞逝，光阴荏苒，三年过去了。组织者精心准备的颁奖典礼早已结束，留下的则是被人们踩过的地毯。请你来解决类似于铺地毯的另一个问题。

题目描述
会场上有 n 个关键区域，不同的关键区域由 m 条无向地毯彼此连接。每条地毯可由三个整数 u、v、w 表示，其中 u 和 v 为地毯连接的两个关键区域编号，w 为这条地毯的美丽度。

由于颁奖典礼已经结束，铺过的地毯不得不拆除。为了贯彻勤俭节约的原则，组织者被要求只能保留至多 K 条地毯，且保留的地毯构成的图中，任意可互相到达的两点间只能有一种方式互相到达。换言之，组织者要求新图中不能有环。现在组织者求助你，想请你帮忙算出这至多 K 条地毯的美丽度之和最大为多少。

输入格式
第一行包含三个正整数 n、m、K。

接下来 m 行中每行包含三个正整数 u、v、w。

输出格式
只包含一个正整数，表示这 K 条地毯的美丽度之和的最大值。
*/

/*
    kruskal模板题
*/

#include<bits/stdc++.h> 
using namespace std;

struct edge
{int u, v, w;};
const int N = 1e5 + 10;
vector<edge> e;
int fa[N], n, m, k, ans, cnt;

bool cmp(edge a, edge b)
{
    return a.w > b.w;
}

int find(int x)
{
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

void kruskal()
{
    sort(e.begin(), e.end(), cmp);
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (auto f : e)
    {
        int x = find(f.u);
        int y = find(f.v);
        if (x != y)
        {
            fa[x] = y;
            ans += f.w;
            cnt++;
            if (cnt == k) return;
        }
    }
}

int main( )
{
    cin >> n >> m >> k;
    while (m--)
    {
        int u, v, w; cin >> u >> v >> w;
        e.push_back({u, v, w});
    }
    kruskal();
    cout << ans << endl;
    return 0;
}