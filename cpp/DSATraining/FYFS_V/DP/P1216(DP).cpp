/*
[USACO1.5] [IOI1994] 数字三角形 Number Triangles
题目描述
观察下面的数字金字塔。
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5 
写一个程序来查找从最高点到底部任意处结束的路径，使路径经过数字的和最大。每一步可以走到左下方的点也可以到达右下方的点。

输入格式
第一个行一个正整数 r, 表示行的数目。
后面每行为这个数字金字塔特定行包含的整数。

输出格式
单独的一行,包含那个可能得到的最大的和。

输入数据 1
5
7
3 8
8 1 0
2 7 4 4
4 5 2 6 5 

输出数据 1
30

*/

// 以下是线段DP的做法
#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
int a[N][N], b[N][N];
int n, ans;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> a[i][j];
            b[i][j] = a[i][j];
        }
    }

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            b[i][j] += max(b[i - 1][j - 1], b[i - 1][j]);
        }
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, b[n][i]);
    cout << ans << endl;
    return 0;
}