/*
#P2280. [HNOI2003] 激光炸弹

题目描述

有一种新型的激光炸弹，其爆破范围是一个边长为 m 的正方形区域。现在，地图上有 n 个目标，每个目标都有一个特定的位置 (xi, yi) 和价值 vi。激光炸弹的投放是通过卫星定位的，但其爆破的正方形区域必须与 x 轴和 y 轴平行。重要的是要注意，如果目标位于爆破正方形的边上（包括四个边），则该目标不会被摧毁。即爆炸范围为 (m - 1) * (m -1)

输入格式

第一行包含两个整数 n 和 m，分别表示目标数量和炸弹爆破的正方形边长。
接下来的 n 行，每行包含三个整数 x, y, v，分别表示一个目标的 x 坐标、y 坐标和价值。

输出格式

输出一个正整数，表示一颗炸弹最多能炸掉地图上目标的总价值（结果不会超过 32767）。
*/

#include <iostream>
#include <algorithm>
using namespace std;

int a[5050][5050], s[5050][5050], n, m, x, y, v = 0, temp, N = 5001;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> x >> y >> v;
        a[x + 1][y + 1] += v; // 注意此处的 +=
    }
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            s[i][j] = a[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }
    int ans = 0;
    for (int i = m; i <= N; i++)
    {
        for (int j = m; j <= N; j++)
        {
            temp = s[i][j] - s[i - m][j] - s[i][j - m] + s[i - m][j - m];
            ans = max(ans, temp);
        }
    }
    cout << ans << endl;

    return 0;
}