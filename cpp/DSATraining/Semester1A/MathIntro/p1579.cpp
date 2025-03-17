/*
#P1579. 哥德巴赫猜想（升级版）

题目背景
1742 年 6 月 7 日，哥德巴赫写信给当时的大数学家欧拉，正式提出了以下的猜想：任何一个大于 9 的奇数都可以表示成 3 个质数之和。
这就是哥德巴赫猜想。欧拉在回信中说，他相信这个猜想是正确的，但他不能证明。
从此，这道数学难题引起了几乎所有数学家的注意。哥德巴赫猜想由此成为数学皇冠上一颗可望不可及的“明珠”。

题目描述
现在请你编一个程序验证哥德巴赫猜想。
先给出一个奇数 n，要求输出 3 个质数，这 3 个质数之和等于输入的奇数。

输入格式
仅有一行，包含一个正奇数 n，其中 9<n<20000。

输出格式
仅有一行，输出 3 个质数，这 3 个质数之和等于输入的奇数。相邻两个质数之间用一个空格隔开，最后一个质数后面没有空格。如果表示方法不唯一，请输出第一个质数最小的方案，如果第一个质数最小的方案不唯一，请输出第一个质数最小的同时，第二个质数最小的方案。
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 20020;
bool b[N];
int prime[N];
int tot;

void sieve(int n)
{
    fill(b, b + n + 1, true);
    b[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (b[i])
            prime[tot++] = i;
        for (int j = 0; i * prime[j] <= n; j++)
        {
            b[i * prime[j]] = false;
            if (i % prime[j] == 0)
                break;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    sieve(n);
    for (int i = 0; prime[i] <= n / 3; i++) // n / 3减少开销
    {
        for (int j = i; prime[j] <= (n - prime[i]) / 2; j++)
        {
            int temp = n - prime[i] - prime[j];
            if (b[temp]) // 有表直接查询！
            {
                cout << prime[i] << " " << prime[j] << " " << temp;
                return 0;
            }
        }
    }
}