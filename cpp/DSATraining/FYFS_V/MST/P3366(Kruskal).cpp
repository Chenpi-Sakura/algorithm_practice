/*
【模板】最小生成树
题目描述
如题，给出一个无向图，求出最小生成树，如果该图不连通，则输出 orz。

输入格式
第一行包含两个整数 N,M，表示该图共有 N 个结点和 M 条无向边。

接下来 M 行每行包含三个整数 Xi, Yi, Zi，
表示有一条长度为 Zi 的无向边连接结点 Xi, Yi。

输出格式
如果该图连通，则输出一个整数表示最小生成树的各边的长度之和。如果该图不连通则输出 orz。
*/

/* Kruskal 着重于 边 的扩张*/

#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
struct edge
{
    int u, v, w; // 起点，终点，边权
    bool operator < (const edge &t)const // 重载运算符以方便排序
    {return w < t.w;}
}e[N];
int fa[N], ans, cnt, n, m; // n 节点数 m 边数

int find(int x)
{
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

bool kruskal()
{
    sort(e, e + m);
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 0; i < m; i++)
    {// 按边权从小到大排序，从小开始选取
        int x = find(e[i].u);
        int y = find(e[i].v);
        if(x != y) // 不存在于同一个集合，即未连在一起，则该边可选
        {
            fa[x] = y;
            ans += e[i].w;
            cnt++;
        }
    }
    return cnt == n - 1; // 注意此处是 n - 1
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> e[i].u >> e[i].v >> e[i].w;
    if (!kruskal()) cout << "orz" << endl;
    else cout << ans << endl;
    return 0;
}