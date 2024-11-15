/*
P1226【模板】快速幂
题目描述
给你三个整数 a,b,p，求 a^b mod p。

输入格式
输入只有一行三个整数，分别代表 a,b,p。

输出格式
输出一行一个字符串 a^b mod p=s，其中 a,b,p 分别为题目给定的值，s 为运算结果。
*/

#include <bits/stdc++.h>
using namespace std;

long long quickpow(long long a, long long b, long long m)
{
    long long result = 1;
    while (b > 0)
    {
        a %= m;
        if (b % 2 == 1)
            result = (result * a) % m;

        a *= a;
        b /= 2;
    }
    return result;
}

int main()
{
    long long a, b, p;
    cin >> a >> b >> p;
    printf("%lld^%lld mod %lld=%lld", a, b, p, quickpow(a, b, p));
    return 0;
}