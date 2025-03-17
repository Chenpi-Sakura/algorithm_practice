/*
[NOI1995] 石子合并
题目描述
在一个圆形操场的四周摆放 N 堆石子，现要将石子有次序地合并成一堆，规定每次只能选相邻的 2 堆合并成新的一堆，并将新的一堆的石子数，记为该次合并的得分。
试设计出一个算法,计算出将 N 堆石子合并成 1 堆的最小得分和最大得分。

输入格式
数据的第 1 行是正整数 N，表示有 N 堆石子。
第 2 行有 N 个整数，第 i 个整数 ai 表示第 i 堆石子的个数。

输出格式
输出共 2 行，第 1 行为最小得分，第 2 行为最大得分。
*/

/*
    区间dp
    由于该题是环形，我们选择经典的处理方法，把序列重复两次
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 205;
const int inf = 0x3f3f3f3f;
int a[N], s[N];
int f[N][N], g[N][N];
int n;

int main()
{
    memset(f, 0x3f, sizeof(f));
    memset(g, -0x3f, sizeof(g));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i + n] = a[i];
    }
    for (int i = 1; i <= n * 2; i++)
    {
        s[i] = s[i - 1] + a[i]; // 由于该题涉及到大量的区间得分计算，我们选择使用前缀和来优化
        f[i][i] = 0; g[i][i] = 0;
    }

    for (int len = 2; len <= n; len++){ // 列举区间长度
        for (int l = 1; l + len - 1 <= n * 2; l++)
        { // 列举区间起点
            int r = l + len - 1;
            for (int k = l; k < r; k++)
            { // 列举分割点
                f[l][r] = min(f[l][r], f[l][k] + f[k + 1][r] + s[r] - s[l - 1]);
                g[l][r] = max(g[l][r], g[l][k] + g[k + 1][r] + s[r] - s[l - 1]);
            }
        }
    }
    int minv = inf, maxv = -inf;
    for (int i = 1; i <= n; i++)
    {// 枚举最值
        minv = min(minv, f[i][i + n - 1]);
        maxv = max(maxv, g[i][i + n - 1]);
    }
    cout << minv << endl << maxv << endl;
    return 0;
}