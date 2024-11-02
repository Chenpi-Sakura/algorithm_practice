/*
#P3397. 地毯

题目描述
在 n * n 的格子上有 m 个地毯。
给出这些地毯的信息，问每个点被多少个地毯覆盖。

输入格式
第一行，两个正整数 n,m。意义如题所述。
接下来 m 行，每行两个坐标(x1,y1)和(x2,y2)，代表一块地毯，左上角是(x1,y1)，右下角是(y2, y2)。

输出格式
输出 n 行，每行 n 个正整数。
第i行第j列的正整数表示(i,j)这个格子被多少个地毯覆盖。

解题方案：
差分，对坐标进行标记，然后再还原！
*/

#include <iostream>
using namespace std;

int d[1010][1010];
int main()
{
    int n, m, x1, x2, y1, y2;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        d[x1][y1] += 1;
        d[x1][y2 + 1] -= 1;
        d[x2 + 1][y1] -= 1;
        d[x2 + 1][y2 + 1] += 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            d[i][j] += d[i][j - 1] + d[i - 1][j] - d[i - 1][j - 1];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << d[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}