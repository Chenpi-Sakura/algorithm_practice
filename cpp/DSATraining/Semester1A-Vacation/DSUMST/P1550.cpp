/*
[USACO08OCT] Watering Hole G
题目描述
Farmer John 的农场缺水了。
他决定将水引入到他的 n 个农场。他准备通过挖若干井，并在各块田中修筑水道来连通各块田地以供水。在第 i 号田中挖一口井需要花费 Wi 元。连接 i 号田与 j 号田需要 Pi,j（Pj,i=Pi,j）元。
请求出 FJ 需要为使所有农场都与有水的农场相连或拥有水井所需要的最少钱数。

输入格式
第一行为一个整数 n。
接下来 n 行，每行一个整数 Wi。
接下来 n 行，每行 n 个整数，第 i 行的第 j 个数表示连接 i 号田和 j 号田需要的费用 Pi,j。

输出格式
输出最小开销。
*/

/*
    此题直接做会很难想，但是我们可以假想还存在一个 水源点
    每个田打井的成本是理解为 该田与 水源点 的路径之间的距离
    然后直接运用kruskal算法即可
*/

#include<bits/stdc++.h> 
using namespace std;

struct edge
{int u, v, w;};
const int N = 305;
vector<edge> e;
int fa[N], n, ans;

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
    for (int i = 0; i <= n; i++) fa[i] = i;
    int len = e.size();
    for (auto w : e)
    {
        int x = find(w.u);
        int y = find(w.v);
        if (x != y)
        {
            fa[x] = y;
            ans += w.w;
        }
    }
}

int main( )
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int w; cin >> w;
        e.push_back({i, n + 1, w});
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int w; cin >> w;
            if (j < i) e.push_back({i, j, w});
        }
    }
    n++;
    kruskal();
    cout << ans << endl;
    return 0;
}