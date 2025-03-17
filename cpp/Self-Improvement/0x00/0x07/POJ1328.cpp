/*
假设海岸是一条无限长的直线，陆地位于海岸的一侧，海洋位于另外一侧。
每个小岛都位于海洋一侧的某个点上。
雷达装置均位于海岸线上，且雷达的监测范围为 d，当小岛与某雷达的距离不超过 d 时，该小岛可以被雷达覆盖。
我们使用笛卡尔坐标系，定义海岸线为 x 轴，海的一侧在 x 轴上方，陆地一侧在 x 轴下方。
现在给出每个小岛的具体坐标以及雷达的检测范围，请你求出能够使所有小岛都被雷达覆盖所需的最小雷达数目。

输入格式
第一行输入两个整数 n 和 d，分别代表小岛数目和雷达检测范围。
接下来 n 行，每行输入两个整数，分别代表小岛的 x，y 轴坐标。
同一行数据之间用空格隔开。

输出格式
输出一个整数，代表所需的最小雷达数目，若没有解决方案则所需数目输出 −1。

数据范围
1≤n≤1000,
1≤d≤200,
−1000≤x,y≤1000
*/

// 此题目需要注意 double 精度问题

#include <bits/stdc++.h>
using namespace std;

typedef pair<double, double> PDD;
const int N = 1e4;
PDD fw[N]; // 左端点与右端点

bool cmp(PDD a, PDD b)
{
    return a.second < b.second;
}

int main()
{
    int n; double d; cin >> n >> d;
    for (int i = 0; i < n; i++)
    {
        double x, y; cin >> x >> y;
        if (y > d) 
        {
            cout << -1 << endl; 
            return 0;
        }
        double dis = sqrt(d * d - y * y);
        fw[i] = {x - dis, x + dis};
    }
    
    sort(fw, fw + n, cmp);
    int ans = 0;
    stack<double> place;

    for (int i = 0; i < n; i++)
    {
        if (place.empty() || place.top() < fw[i].first)
        {
            ans++;
            place.push(fw[i].second);
        }
    }
    
    cout << ans << endl;
    return 0;
}