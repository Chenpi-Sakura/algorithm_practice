/*
P3613 【深基15.例2】寄包柜

题目描述
超市里有 n(1≤n≤10^5) 个寄包柜。每个寄包柜格子数量不一，第 i 个寄包柜有 ai (1≤ai≤10^5) 个格子，不过我们并不知道各个 ai 的值。对于每个寄包柜，格子编号从 1 开始，一直到 ai。现在有 q(1≤q≤10^5)  次操作：
1 i j k：在第 i 个柜子的第 j 个格子存入物品  k(0≤k≤10^9)。当 k=0 时说明清空该格子。
2 i j：查询第 i 个柜子的第 j 个格子中的物品是什么，保证查询的柜子有存过东西。
已知超市里共计不会超过 10^7 个寄包格子，ai 是确定然而未知的，但是保证一定不小于该柜子存物品请求的格子编号的最大值。当然也有可能某些寄包柜中一个格子都没有。

输入格式
第一行 2 个整数 n 和 q，寄包柜个数和询问次数。
接下来 q 个行，每行有若干个整数，表示一次操作。

输出格式
对于查询操作时，输出答案，以换行隔开。
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
vector<vector<LL>> a;
vector<LL> m;

int main()
{
    LL n, q;
    cin >> n >> q;
    a.resize(n);
    m.resize(n);
    while(q--)
    {
        int v;
        cin >> v;
        if (v == 1)
        {
            int i, j, k;
            cin >> i >> j >> k;
            if (m[i - 1] < j)
            {
                m[i - 1] = j;
                a[i - 1].resize(j);
            }
            a[i - 1][j - 1] = k;
        }
        if (v == 2)
        {
            int i, j;
            cin >> i >> j;
            cout << a[i - 1][j - 1] << endl;
        }
    }
    return 0;
}
// 重点是要考虑到可能空间大小的问题