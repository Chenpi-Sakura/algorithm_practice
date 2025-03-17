/*
给定一个整数 M，对于任意一个整数集合 S，定义“校验值”如下:

从集合 S 中取出 M 对数(即 2×M) 个数，不能重复使用集合中的数，如果 S 中的整数不够 M 对，则取到不能取为止)，使得“每对数的差的平方”之和最大，这个最大值就称为集合 S 的“校验值”。

现在给定一个长度为 N 的数列 A 以及一个整数 T。

我们要把 A 分成若干段，使得每一段的“校验值”都不超过 T。
求最少需要分成几段。

输入格式
第一行输入整数 K，代表有 K 组测试数据。

对于每组测试数据，第一行包含三个整数 N,M,T
第二行包含 N 个整数，表示数列 A1,A2⋯AN
。

输出格式
对于每组测试数据，输出其答案，每个答案占一行。

数据范围
1 ≤ K ≤ 12,
1 ≤ N,M ≤ 500000,
0 ≤ T ≤ 10^18,
0 ≤ Ai ≤ 2^20
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 5e5 + 10;
LL a[N], b[N], temp[N];
LL m, t;


/*一直错，错错错！
bool check(int l, int mid, int r)
{
    for (int i = mid; i <= r; i++) b[i] = a[i];// 创造b数列方便后续的排序
    sort(b + mid, b + r + 1);
    // 归并
    int x = l, y = l, z = mid + 1;
    while (x <= mid && z <= r)
    {
        if (b[x] >= b[z]) temp[y++] = b[x++];
        else temp[y++] = b[z++];
    }
    while (x <= mid) temp[y++] = b[x++];
    while (z <= r) temp[y++] = b[z++];
    for(int i = l; i <= r; i++) b[i] = temp[i];

    LL sum = 0, pairs = min(m, (LL)(r - l + 1) / 2);
    for (int i = 0; i < pairs; i++) sum += (b[l + i] - b[r - i]) * (b[l + i] - b[r - i]);
    return sum <= t;
}

int main()
{
    int k; cin >> k;
    while (k--)
    {
        int n; cin >> n >> m >> t;
        for (int i = 1; i <= n; i++) cin >> a[i]; // 输入数据
        int p, l = 1, r = 1, ans = 0;// 初始化
        while (r <= n)
        {
            p = 1;
            while (p)
            {
                if (r + p <= n && check(l, r, r + p))
                {
                    r += p;
                    p *= 2;
                    if (r >= n) break;
                }
                else p /= 2;
            }
            r++; l = r;// 开启下一个分段
            ans++;
        }
        cout << ans << endl;
    }
}
*/
//以下为超时答案
bool check(int l, int r)
{
    for (int i = l; i <= r; i++) b[i] = a[i];// 创造b数列方便后续的排序
    sort(b + l, b + r + 1);
    LL sum = 0, pairs = min(m, (LL)(r - l + 1) / 2);
    for (int i = 0; i < pairs; i++) sum += (b[l + i] - b[r - i]) * (b[l + i] - b[r - i]);
    return sum <= t;
}

int main()
{
    int k; cin >> k;
    while (k--)
    {
        int n; cin >> n >> m >> t;
        for (int i = 1; i <= n; i++) cin >> a[i]; // 输入数据
        int p, l = 1, r = 1, ans = 0;// 初始化
        while (r <= n)
        {
            p = 1;
            while (p)
            {
                if (r + p <= n && check(l, r + p))
                {
                    r += p;
                    p *= 2;
                }
                else p /= 2;
            }
            r++; l = r;// 开启下一个分段
            ans++;
        }
        cout << ans << endl;
    }
}