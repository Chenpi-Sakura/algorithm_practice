/*
口袋的天空
题目背景
小杉坐在教室里，透过口袋一样的窗户看口袋一样的天空。
有很多云飘在那里，看起来很漂亮，小杉想摘下那样美的几朵云，做成棉花糖。

题目描述
给你云朵的个数 N，再给你 M 个关系，表示哪些云朵可以连在一起。
现在小杉要把所有云朵连成 K 个棉花糖，一个棉花糖最少要用掉一朵云，小杉想知道他怎么连，花费的代价最小。

输入格式
第一行有三个数 N,M,K。
接下来 M 行每行三个数 X,Y,L，表示 X 云和 Y 云可以通过 L 的代价连在一起。

输出格式
对每组数据输出一行，仅有一个整数，表示最小的代价。
如果怎么连都连不出 K 个棉花糖，请输出 No Answer。
*/

#include<bits/stdc++.h> 
using namespace std;

struct edge
{int u, v, w;};
const int N = 1e3 + 10;
vector<edge> e;
int fa[N], n, m, k, ans, cnt;

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
    if (k > n) return false;
    sort(e.begin(), e.end(), cmp);
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (auto c : e)
    {
        int x = find(c.u);
        int y = find(c.v);
        if (x != y)
        {
            fa[x] = y;
            ans += c.w;
            if (--cnt == k) break;
        }
    }
    return cnt == k;
}

int main( )
{
    cin >> n >> m >> k;
    cnt = n;
    while (m--)
    {
        int x, y, l; cin >> x >> y >> l;
        e.push_back({x, y, l});
    }
    if (!kruskal()) cout << "No Answer" << endl;
    else cout << ans << endl;
    return 0;
}