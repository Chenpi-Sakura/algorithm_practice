/*
 #P1835. 素数密度
给定区间[L,R](1 <= L <= R < 2^31, R - L <= 10^6), 请计算区间中素数的个数。

输入格式
第一行，两个正整数 L 和 R。

输出格式
一行，一个整数，表示区间中素数的个数。
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL; // 取LL防止越界，溢出
const int MAX = 46341;
vector<LL> prime;

void sieve()
{
    vector<bool> b(MAX, true);
    b[1] = false;
    for(int i = 2; i <= MAX; i++)
    {
        if(b[i])
            prime.push_back(i);
        for (int j = 0; i * prime[j] <= MAX; j++)
        {
            b[i * prime[j]] = false;
        }
    }
}

LL tick(LL l, LL r)
{
    vector<bool> b(r - l + 1, true);
    for (LL p : prime)
    {
        LL start = max((LL)(p * p), (LL)((l + p - 1) / p) * p);
        for (LL i = start; i <= r; i += p)
            b[i - l] = false; // i - l 保证其在正确的位置，位置从 0 开始
    }
    if (l == 1)
        b[0] = false;
    return count(b.begin(), b.end(), true);
}

int main() {
    LL l, r;
    cin >> l >> r;

    sieve(); // 预处理小素数
    cout << tick(l, r); // 区间筛
    return 0;
}