/*
#P1072. [NOIP2009 提高组] Hankson 的趣味题

题目描述
已知正整数 a0, a1, b0, b1, 设某未知正整数 x 满足：
    1. x 和 a0 的最大公约数是 a1；
    2. x 和 b0 的最小公倍数是 b1。
第一行为一个正整数 n，表示有 n 组输入数据。接下来的n 行每行一组输入数据，为四个正整数 a0 ,a1 ,b0 ,b1 每两个整数之间用一个空格隔开。输入数据保证 a0 能被 a1 整除，b1 能被 b0 整除。

输出格式
共 n 行。每组输入数据的输出结果占一行，为一个整数。
对于每组数据：若不存在这样的x，请输出0，若存在这样的 x 请输出满足条件的个数。
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

LL gcd(LL a, LL b)
{
    if(b == 0)
        return a;
    return gcd(b, a % b); 
}

LL lcm(LL a, LL b)
{
    return (a * b) / gcd(a, b);
}

LL lcm(LL a, LL b) {
    return (a / gcd(a, b)) * b; // 防止溢出，先除后乘
}

vector<LL> divisors;
vector<LL> get_divisors(LL n) {
    for (LL i = 1; i * i <= n; ++i) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n / i) divisors.push_back(n / i);
        }
    }
    return divisors;
}

LL counter(LL a0, LL a1, LL b0, LL b1)
{
    if(b1 % lcm(b0, a1) != 0)
        return 0;
    LL t = 0;
    for(LL x = a1; x <= b1; x += a1)
    {
        if(gcd(a0, x) == a1 && lcm(b0, x) == b1)
            t++;
    }
    return t;
}

int main()
{
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (LL i = 0; i < n; i++)
    {
        LL a0, a1, b0, b1;
        cin >> a0 >> a1 >> b0 >> b1;
        cout << counter(a0, a1, b0, b1) << '\n';
    }
}