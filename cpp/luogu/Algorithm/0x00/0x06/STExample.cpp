#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 100;
int f[N][20], a[N];
int n;

/**
 * @brief 预处理函数，用于构建稀疏表（Sparse Table）
 * 
 * 该函数通过动态规划的方式，计算出所有可能区间的最大值，并存储在二维数组 f 中。
 * f[i][j] 表示从位置 i 开始，长度为 2^j 的区间内的最大值。
 * 
 * @param None
 * @return None
 */
void ST_prework()
{
    // 初始化 f[i][0]，即每个位置的初始值为 a[i]
    for (int i = 1; i <= n; i++) f[i][0] = a[i]; 
    // 计算 log2(n)，用于确定最大的区间长度
    int k = log2(n);
    // 外层循环遍历所有可能的区间长度 2^j
    for (int j = 1; j <= k; j++) 
        // 内层循环遍历所有可能的起始位置 i
        for (int i = 1; i + (1 << j) - 1 <= n; i++) 
            // 更新 f[i][j]，取两个子区间的最大值
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j -1]);
}

/**
 * @brief 查询函数，用于查询给定区间内的最大值
 * 
 * 该函数通过计算 log2(r - l + 1)，找到合适的区间长度 2^k，
 * 然后比较两个长度为 2^k 的子区间的最大值，返回较大值。
 * 
 * @param l 区间的左端点
 * @param r 区间的右端点
 * @return int 区间内的最大值
 */
int ST_query(int l, int r)
{
    // 计算 log2(r - l + 1)，找到合适的区间长度 2^k
    int k = log2(r - l + 1);
    // 返回两个子区间的最大值
    return max(f[l][k], f[r - (1 << k) + 1][k]);
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    ST_prework();
    int l, r; cin >> l >> r;
    cout << ST_query(l, r) << endl;
    return 0;
}