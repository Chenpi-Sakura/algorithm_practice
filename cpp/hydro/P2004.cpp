/*
#P2004. 领地选择
题目描述

作为在虚拟世界里统帅千军万马的领袖，小乙认为天时、地利、人和三者是缺一不可的，所以，谨慎地选择首都的位置对于小乙来说是非常重要的。首都被认为是一个占地 C x C 的正方形。小乙希望你寻找到一个合适的位置，使得首都所占领的位置的土地价值和最高。

输入格式
第一行三个整数 N,M,C,表示地图的宽和长以及首都的边长,接下来 N 行每行 M 个整数，表示了地图上每个地块的价值。价值可能为负数。

输出格式
行两个整数 X,Y，表示首都左上角的坐标
*/
#include <iostream>
using namespace std;

int a[1010][1010], s[1010][1010];
int main()
{
    int n, m, c, v, x, y;
    cin >> n >> m >> c;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            s[i][j] = a[i][j] + s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }
    }

    v = s[c][c]; // 初始化V的值

    for (int i = c; i <= n; i++)
    {
        for (int j = c; j <= m; j++) //[i][j]此时为首都右下坐标
        {
            if ((s[i][j] - s[i - c][j] - s[i][j - c] + s[i - c][j - c]) > v)
            {
                x = i - c + 1;
                y = j - c + 1;
                v = s[i][j] - s[i - c][j] - s[i][j - c] + s[i - c][j - c];
            }
        }
    }

    cout << x << " " << y;

    return 0;
}