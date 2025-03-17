/*
倍增
给定一个长度为 N 的数组 A，针对若干次询问，每次给定一个整数 T，求出某个最大的 k，满足 ∑A[i] ≤ T。
要求算法必须是在线的（即必须即时回答每一个询问，不能等所有询问到齐后再统一处理），假设 0 ≤ T ≤ ∑A[i]。
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 1e6 + 10;

int a[N], sum[N];

int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    int q; cin >> q;
    while (q--)
    {
        LL t; cin >> t;
        LL s = 0;
        int k = 0, p = 1;
        while (p)
        {
            if (s + sum[k + p] - sum[k] <= t)
            {
                s += sum[k + p] - sum[k];
                k += p;
                p *= 2;
            }
            else p /= 2;
        }
        cout << k << endl;
    }

    return 0;
}