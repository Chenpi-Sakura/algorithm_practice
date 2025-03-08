/*
    记忆化搜索
    可以理解为对于dfs的一种剪枝
*/

#include<bits/stdc++.h> 
using namespace std;

const int N = 1e3 + 5;
int a[N][N], f[N][N]; // f[N][N]记录从下向上的累加和
int n; // 深度

int dfs(int x, int y)
{
    if (f[x][y] != -1) return f[x][y]; // 若已计算出则返回
    if (x == n - 1) f[x][y] = a[x][y];
    else f[x][y] = a[x][y] + max(dfs(x + 1, y), dfs(x + 1, y + 1));
    return f[x][y];
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> a[i][j];
        }
    }
    memset(f, -1, sizeof(f));
    dfs(0, 0);
    cout << f[0][0] << endl;
    return 0;
}