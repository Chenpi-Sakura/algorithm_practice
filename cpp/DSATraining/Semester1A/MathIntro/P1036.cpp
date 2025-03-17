/*
#P1036. [NOIP2002 普及组] 选数
题目描述
从 x1, x2, x3 ... xn 中选 k 个数得其一系列的和。
要求求出和为素数得共计多少种。

输入格式
第一行两个空格隔开的整数 n,k（1≤n≤20，k<n）。
第二行 n 个整数，分别为 x1 ,x2 ,⋯ ,xn（1 ≤ xi ≤ 5 × 10^6）。

输出格式
输出一个整数，表示种类数。
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 5e6 + 1;
bool b[N];
int prime[N], tot;
// 素数筛

vector<int> nums;
int n, k, t;
// 排序组合

void sieve()
{
    fill(b, b + N, true);
    b[1] = false;
    for (int i = 2; i < N; i++)
    {
        if (b[i])
            prime[tot++] = i;
        for (int j = 0; i * prime[j] <= N; j++)
        {
            b[i * prime[j]] = false;
            if (i % prime[j] == 0)
                break;
        }
    }
}

void backtrack(int start, int count, int sum)
{
    if(count == k)
    {
        if(b[sum])
            t++;
        return;
    }
    for(int i = start; i < n; i++)
        backtrack(i + 1, count + 1, sum + nums[i]);
}

int main()
{
    cin >> n >> k;
    nums.resize(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    sieve();
    backtrack(0, 0, 0);
    cout << t;
}