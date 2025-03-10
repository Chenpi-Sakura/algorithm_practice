/*
题目描述
国防部计划用无线网络连接若干个边防哨所。2 种不同的通讯技术用来搭建无线网络；
每个边防哨所都要配备无线电收发器；有一些哨所还可以增配卫星电话。
任意两个配备了一条卫星电话线路的哨所（两边都有卫星电话）均可以通话，无论他们相距多远。而只通过无线电收发器通话的哨所之间的距离不能超过 D，这是受收发器的功率限制。收发器的功率越高，通话距离 D 会更远，但同时价格也会更贵。
收发器需要统一购买和安装，所以全部哨所只能选择安装一种型号的收发器。换句话说，每一对哨所之间的通话距离都是同一个 D。你的任务是确定收发器必须的最小通话距离 D，使得每一对哨所之间至少有一条通话路径（直接的或者间接的）。

输入格式
第一行，2 个整数 S 和 P，S 表示可安装的卫星电话的哨所数，P 表示边防哨所的数量。
接下里 P 行，每行两个整数 x，y 描述一个哨所的平面坐标 (x,y)，以 km 为单位。

输出格式
第一行，1 个实数 D，表示无线电收发器的最小传输距离，精确到小数点后两位。
*/


#include<bits/stdc++.h>
using namespace std;

const int N = 3e6;
const int INF = 1e9 + 100;
struct edge{int v; double w;};
vector<edge> e[N];
pair<double, double> nList[N];
vector<double> dList;
priority_queue<pair<double, int>> q; // 最大堆<距离，节点>
double d[N]; int vis[N];
int n, m;

double calcdis(pair<double, double> a,  pair<double, double> b)
{
    double c = a.first - b.first;
    double d = a.second - b.second;
    return sqrt(c * c + d * d);
}

void prim(int s)
{
    for (int i = 0; i <= n; i++) d[i] = INF;
    d[s] = 0; q.push({0.0, s});
    while (q.size())
    {
        int x = q.top().second; q.pop();
        if (vis[x]) continue;
        vis[x] = 1;
        dList.push_back(d[x]); // 存储遍历过的边的大小
        for (auto ed : e[x])
        {
            int v = ed.v; double w = ed.w;
            if (d[v] > w)
            {
                d[v] = w;
                q.push({-d[v], v});
            }
        }
    }
}

int main( )
{
    cin >> m >> n;
    for (int i = 1; i <= n; i++)
        cin >> nList[i].first >> nList[i].second;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            double distance = calcdis(nList[i], nList[j]);
            e[i].push_back({j, distance});
        }
    }
    prim(1);
    sort(dList.begin(), dList.end(), greater<double>());
    printf("%.2lf\n", dList[m - 1]);
    return 0;
}