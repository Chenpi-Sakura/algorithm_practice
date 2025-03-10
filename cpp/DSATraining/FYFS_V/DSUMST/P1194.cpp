/*
题目描述
又到了一年一度的明明生日了，明明想要买 B 样东西，巧的是，这 B 样东西价格都是 A 元。
但是，商店老板说最近有促销活动，也就是：
如果你买了第 I 样东西，再买第 J 样，那么就可以只花 KI,J 元，更巧的是，KI,J 竟然等于 KJ,I。
现在明明想知道，他最少要花多少钱。

输入格式
第一行两个整数，A,B。
接下来 B 行，每行 B 个数，第 I 行第 J 个为 KI,J。
我们保证 KI,J=KJ,I 并且 KI,I=0。
特别的，如果 KI,J=0，那么表示这两样东西之间不会导致优惠。
注意 KI,J 可能大于 A。

输出格式
一个整数，为最小要花的钱数。
*/

/* 
    同样是建立了一个虚拟的点
*/
#include<bits/stdc++.h> 
using namespace std;

struct edge
{int u, v, w;};
const int N = 505;
vector<edge> e;
int fa[N], n, a, ans;

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

int find(int x)
{
    if(x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

void kruskal()
{
    sort(e.begin(), e.end(), cmp);
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (auto k : e)
    {
        int x = find(k.u);
        int y = find(k.v);
        if (x != y)
        {
            fa[x] = y;
            ans += k.w;
        }
    }
}

int main( )
{
    cin >> a >> n;
    for (int i = 1; i <= n; i++)
    {
        e.push_back({i, n + 1, a});
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int k; cin >> k;
            if (k == 0) continue;
            if (j < i) e.push_back({i, j, k}); // 这一步相当于直接两点之间增加了一条路
        }
    }
    n++;
    kruskal();
    cout << ans << endl;
    return 0;
}