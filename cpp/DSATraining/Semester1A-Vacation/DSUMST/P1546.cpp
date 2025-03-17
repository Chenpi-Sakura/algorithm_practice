/*
[USACO3.1] 最短网络 Agri-Net
题目背景
Farmer John 被选为他们镇的镇长！他其中一个竞选承诺就是在镇上建立起互联网，并连接到所有的农场。当然，他需要你的帮助。

题目描述
FJ 已经给他的农场安排了一条高速的网络线路，他想把这条线路共享给其他农场。为了用最小的消费，他想铺设最短的光纤去连接所有的农场。
你将得到一份各农场之间连接费用的列表，你必须找出能连接所有农场并所用光纤最短的方案。每两个农场间的距离不会超过 105。

输入格式
第一行农场的个数 N（3<=N<=100）。
接下来是一个 N×N 的矩阵，表示每个农场之间的距离。理论上，他们是 N 行，每行由 N 个用空格分隔的数组成，实际上，由于每行 80 个字符的限制，因此，某些行会紧接着另一些行。当然，对角线将会是 0，因为不会有线路从第 i 个农场到它本身。

输出格式
只有一个输出，其中包含连接到每个农场的光纤的最小长度。
*/

/*
    最短路径模板题
*/

#include<bits/stdc++.h> 
using namespace std;

struct edge
{int u, v, w;};
const int N = 1e4 + 10;
vector<edge> e;
int fa[N], n, ans;

bool cmp(edge a, edge b)
{
    return a.w < b.w;
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
        }
    }
}

int main( )
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int l; cin >> l;
            if (i != j && j <= i)
            {
                // cout << i << " " << j << " " << l <<endl;
                e.push_back({i, j, l});
            }
        }
    }
    kruskal();
    cout << ans << endl;
    return 0;
}