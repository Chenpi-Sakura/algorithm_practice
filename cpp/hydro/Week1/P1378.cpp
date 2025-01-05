/*
题目描述
在一个长方形框子里，最多有 N 个相异的点，在其中任何一个点上放一个很小的油滴，那么这个油滴会一直扩展，直到接触到其他油滴或者框子的边界。必须等一个油滴扩展完毕才能放置下一个油滴。那么应该按照怎样的顺序在这 N 个点上放置油滴，才能使放置完毕后所有油滴占据的总面积最大呢？（不同的油滴不会相互融合）
注：圆的面积公式 S=πr^2 ，其中 r 为圆的半径。

输入格式
第一行，一个整数 N。
第二行，四个整数 x, y, x',y',表示长方形边框一个顶点及其对角顶点的坐标。
接下来 N 行，第 i 行两个整数 xi ,yi，表示盒子内第 i 个点的坐标。

输出格式
一行，一个整数，长方形盒子剩余的最小空间（结果四舍五入输出）。

对于 100% 的数据，1≤N≤6(很小的数据范围)，坐标范围在 [−1000,1000] 内。
*/
#include <bits/stdc++.h>
using namespace std;

typedef pair<double, double> PDD;

int N;
double a, b, c, d;
PDD n[6];          // first 储存x坐标 second 储存y坐标
vector<int> plist;
double maxArea = -1;
double pai = 3.1415926;

double cal()
{
    double area = 0;
    double r[6];
    for (int i = 0; i < N; i++)
    {// 遍历plist的每一个参数，算出总面积
        // 计算r
        int index = plist[i];
        double xi = n[index].first;
        double yi = n[index].second;
        
        double left = abs(a - xi);
        double right = abs(c - xi);
        double up = abs(b - yi);
        double down = abs(d - yi);

        double minDist = min({left, right, up, down});

        for (int j = 0; j < i; j++)
        {// 遍历第i个圆之前的所有圆，以找到最大且适合的半径
            int jndex = plist[j];
            double xj = n[jndex].first;
            double yj = n[jndex].second;

            double Dist = sqrt(pow(xj - xi, 2) + pow(yj - yi, 2)) - r[j];
            minDist = min(Dist, minDist);
        } // 找最小的r^2避免碰撞油滴
        minDist = max(0.0, minDist);
        r[i] = minDist;
        area += pai * minDist * minDist;
    }
    return area;
}

void pick(int u, int state)
{
    if (u == N)
    {
        double calculation = cal();
        if (calculation > maxArea)
        {
            maxArea = calculation;
        }
        return;
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            if (!(state >> i & 1))
            {
                plist.push_back(i);
                pick(u + 1, state | 1 << i);
                plist.pop_back();
            }
        }
    }
}

int main()
{
    cin >> N;
    cin >> a >> b >> c >> d;
    for (int i = 0; i < N; i++)
    {
        cin >> n[i].first >> n[i].second;
    }
    pick(0, 0);
    double square = abs(a - c) * abs(b - d);
    double minN = square - maxArea;
    cout << (long long)round(minN) << endl;
    return 0;
}