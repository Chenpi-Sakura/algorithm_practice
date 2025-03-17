/*
问题描述
已知一个平面上有 n 个城市，需要个 n 个城市均通上电。 一个城市有电，必须在这个城市有发电站或者和一个有电的城市用电缆相连。
在一个城市建造发电站的代价是 c[i]，将 i 和 j 两个城市用电缆相连的代价是 k[i]+k[j] 乘上两者的曼哈顿距离。
求最小代价的方案。

输入
第一行为城市数量，接下来n行为城市坐标，接下来两行为c数组和k数组。

输出
输出的第一行包含一个整数，表示最小的总成本。
第二行包含一个整数 v —— 建设发电站的城市数量。
第三行包含 v 个空格分隔的整数，表示建设发电站的城市编号。这些城市的编号必须是唯一的，且范围在 1 到 n 之间。
第四行包含一个整数 e —— 建设连接线的数量。
第五行包含 e 行，每行包含两个空格分隔的整数 a 和 b，表示第 i 条连接线连接的城市 a 和城市 b。每对城市只能出现一次（对于每对 (a,b)，不能有 (a,b) 或 (b,a) 的情况）。你可以以任意顺序输出这些连接线。
如果有多组解可以达到最小的总成本，则输出其中任意一组。
*/

/*
    同样是建一个虚拟节点
*/
#include<bits/stdc++.h> 
using namespace std;

struct edge
{int u, v; long long w;};
const int N = 2005;
vector<edge> e;
int fa[N], n;
long long c[N], k[N], ans;
pair<long, long> pos[N];

vector<pair<int, int>> cityPair;
vector<int> powerStation;

bool cmp(edge a, edge b)
{
    return a.w < b.w;
}

long long costCal(int i, int j)
{
    return (k[i] + k[j]) * (abs(pos[i].first - pos[j].first) + abs(pos[i].second - pos[j].second));
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
    for (auto c : e)
    {
        int x = find(c.u);
        int y = find(c.v);
        if (x != y)
        {
            fa[x] = y;
            ans += c.w;
            if (c.v == n) powerStation.push_back(c.u);
            else cityPair.push_back({c.u, c.v});
        }
    }
}

int main( )
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        long long x, y; cin >> x >> y;
        pos[i] = {x, y};
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> c[i];
        e.push_back({i, n + 1, c[i]});
    }
    for (int i = 1; i <= n; i++) cin >> k[i];

    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            e.push_back({i, j, costCal(i, j)});
        }
    }
    n++;
    kruskal();
    sort(powerStation.begin(), powerStation.end());
    cout << ans << endl;
    cout << powerStation.size() << endl;
    for (int s : powerStation) cout << s << " "; cout << endl;
    cout << cityPair.size() << endl;
    for (auto s : cityPair) cout << s.first << " " << s.second << endl;
    return 0;
}