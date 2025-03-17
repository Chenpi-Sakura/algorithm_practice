/*
差分约束系统(system of difference constraints)
题目描述

给出一组包含 m 个不等式，有 n 个未知数的形如：

x_c1 - x_c1' <= y1
x_c2 - x_c2' <= y2
...
x_cm - x_cm' <= ym

的不等式组，求任意一组满足这个不等式组的解。

输入格式

第一行为两个正整数 n, m，代表未知数的数量和不等式的数量。
接下来 m 行，每行包含三个整数 c, c', y，代表一个不等式 x_c - x_c' <= y。

输出格式
一行，n 个数，表示 x1, x2, ..., xn 的一组可行解，如果有多组解，请输出任意一组，无解请输出 NO。

输入输出样例

输入 #1

3 3
1 2 3
2 3 -2
1 3 1

输出 #1

5 3 5

说明/提示
样例解释

x1 - x2 <= 3
x2 - x3 <= -2
x1 - x3 <= 1

一种可行的方法是 x1 = 5, x2 = 3, x3 = 5。

5 - 3 = 2 <= 3
3 - 5 = -2 <= -2
5 - 5 = 0 <= 1

数据范围
对于 100% 的数据，1 <= n, m <= 5 × 10^3，-10^4 <= y <= 10^4，1 <= c, c' <= n，c ≠ c'。
*/

// 使用SPFA的原因是要处理可能存在的负权值

#include<bits/stdc++.h> 
using namespace std;

const int N = 1e4 + 5;
const int inf = 0x3f3f3f3f;
struct edge {int v, w;};
vector<edge> e[N];
queue<int> q;
int d[N], vis[N], cnt[N];
int n, m;

bool spfa(int s)
{
    for (int i = 1; i <= n; i++) d[i] = inf;
    d[s] = 0; vis[s] = 1; q.push(s);
    while (q.size())
    {   
        int u = q.front(); q.pop(); vis[u] = 0;
        for (auto ed : e[u])
        {
            int v = ed.v, w = ed.w;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                cnt[v] = cnt[u] + 1;
                if (cnt[v] > n) return true; // 存在负环
                if (!vis[v]) q.push(v), vis[v] = 1;
            }
        }
    }
    return false;
}

int main()
{
    cin >> n >> m;
    // 建边：对于每个不等式 x_u - x_v <= w
    while (m--)
    {
        int u, v, w; cin >> u >> v >> w;
        e[v].push_back({u, w});  // 从v到u建立一条权值为w的边
    }

    // 建立超级源点0到所有点的边，权值为0
    for (int i = 1; i <= n; i++)
        e[0].push_back({i, 0});

    if (spfa(0))
        cout << "NO" << endl;
    else{
        for (int i = 1; i <= n; i++)
            cout << d[i] << " ";
        cout << endl;
    }   
    return 0;
}
