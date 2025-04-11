#include<bits/stdc++.h> 
using namespace std;
#define int long long
const int M = 1e9 + 7;

int f[205][105][105];
// 总 店 此时剩余的酒量 路径数
signed main()
{
    int n, m; cin >> n >> m;
    f[0][0][2] = 1;
    for (int i = 1; i <= n + m; i++)
    {
        for (int j = 1; j <= min(i, n); j++)
        {
            for (int k = 0; k <= 105; k++)
            { // 达到 k 酒量有两个途径 上一次酒店，翻倍; 上一次看花，减一
                if (k % 2 == 0) f[i][j][k] += f[i - 1][j - 1][k / 2] + f[i - 1][j][k + 1];
                else f[i][j][k] += f[i - 1][j][k + 1];
            }
        }
    }
    cout << f[m + n][n][0] << endl;
    return 0;
}