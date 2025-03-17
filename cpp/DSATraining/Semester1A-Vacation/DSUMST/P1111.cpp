/*
题目背景
A 地区在地震过后，连接所有村庄的公路都造成了损坏而无法通车。政府派人修复这些公路。

题目描述
给出 A 地区的村庄数 N，和公路数 M，公路是双向的。并告诉你每条公路的连着哪两个村庄，并告诉你什么时候能修完这条公路。问最早什么时候任意两个村庄能够通车，即最早什么时候任意两条村庄都存在至少一条修复完成的道路（可以由多条公路连成一条道路）。

输入格式
第 1 行两个正整数 N,M。
下面 M 行，每行 3 个正整数 x,y,t，告诉你这条公路连着 x,y 两个村庄，在时间t时能修复完成这条公路。

输出格式
如果全部公路修复完毕仍然存在两个村庄无法通车，则输出 −1，否则输出最早什么时候任意两个村庄能够通车。
*/
#include<bits/stdc++.h>
using namespace std;

struct edge
{int u, v, w;};
vector<edge> e;
const int N = 1e3 + 10;
int fa[N], n, m, ans, cnt;

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

int find(int x)
{
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

bool kruskal()
{
    sort(e.begin(), e.end(), cmp);
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (auto r : e)
    {
        int x = find(r.u);
        int y = find(r.v);
        if (x != y)
        {
            fa[x] = y;
            ans = r.w;
            cnt++;
            if (cnt == n - 1) break;
        }
    }
    return cnt == n - 1;
}

int main()
{
    cin >> n >> m;
    while (m--)
    {
        int x, y, t; cin >> x >> y >> t;
        e.push_back({x, y, t});
    }
    if (!kruskal()) cout << -1 << endl;
    else cout << ans << endl;
    return 0;
}