/*
[JSOI2010] 部落划分
题目描述
聪聪研究发现，荒岛野人总是过着群居的生活，但是，并不是整个荒岛上的所有野人都属于同一个部落，野人们总是拉帮结派形成属于自己的部落，不同的部落之间则经常发生争斗。只是，这一切都成为谜团了——聪聪根本就不知道部落究竟是如何分布的。

不过好消息是，聪聪得到了一份荒岛的地图。地图上标注了 n 个野人居住的地点（可以看作是平面上的坐标）。我们知道，同一个部落的野人总是生活在附近。我们把两个部落的距离，定义为部落中距离最近的那两个居住点的距离。聪聪还获得了一个有意义的信息——这些野人总共被分为了 k 个部落！这真是个好消息。聪聪希望从这些信息里挖掘出所有部落的详细信息。他正在尝试这样一种算法：

对于任意一种部落划分的方法，都能够求出两个部落之间的距离，聪聪希望求出一种部落划分的方法，使靠得最近的两个部落尽可能远离。

输入格式
输入文件第一行包含两个整数 n 和 k，分别代表了野人居住点的数量和部落的数量。
接下来 n 行，每行包含两个整数 x，y，描述了一个居住点的坐标。

输出格式
输出一行一个实数，为最优划分时，最近的两个部落的距离，精确到小数点后两位。
*/

#include<bits/stdc++.h> 
#include <vector>
using namespace std;

struct edge
{int u, v; double w;};
const int N = 1e6 + 10;
vector<edge> e;
int fa[N], n, k;
pair<double, double> pos[1005];

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

double discalc(int a, int b)
{
    return sqrt(pow(pos[a].first - pos[b].first, 2) + pow(pos[a].second - pos[b].second, 2));
}

int find(int x)
{
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

int kruskal(double d)
{
    sort(e.begin(), e.end(), cmp);
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (auto h : e)
    {
        if (h.w > d) break; // 假如距离大于 d 则跳过
        int x = find(h.u);
        int y = find(h.v);
        if (x != y)
            fa[x] = y;
    }
    int num = 0;
    for (int i = 1; i <= n; i++) if (fa[i] == i) num++; // 统计一共有几个群落

    // cout << num << endl;
    return num;
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> pos[i].first >> pos[i].second;

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            e.push_back({i, j, discalc(i, j)});
        }
    }

    double l = 0.0, r = 1e8;
    while (r - l > 1e-5)
    { // 此处巧妙地运用了二分来找到最近的距离
        double mid = (l + r) / 2.0;
        // cout << mid << endl;
        if (kruskal(mid) >= k) l = mid;
        else r = mid;
    }
    printf("%.2lf", l);
    return 0;
}