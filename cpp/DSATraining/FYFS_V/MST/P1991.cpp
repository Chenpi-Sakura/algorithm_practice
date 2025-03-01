/*
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