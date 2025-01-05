#include <bits/stdc++.h>
using namespace std;

// 模板
int quickpow(int a, int b, int p)
{
    int ans = 1 % p; // p 可能为 1
    while (b)
    {
        if (b & 1) ans = (long long)ans * a % p;
        a = (long long)a * a % p;
        b >>= 1; // 二进制移位操作
    }
    return ans;
}

typedef long long LL;
// 类似于上一个，乘法的实现
LL multiply(LL a, LL b, LL p)
{
    LL ans = 0;
    a = a % p;
    while (b)
    {
        if (b & 1) ans = (ans + a) % p;
        a = a * 2 % p;
        b >>= 1;
    }
    return ans;
}

// 快速幂的迭代方式
long long quickpow1(long long a, long long b, long long m)
{
    long long result = 1;
    a %= m;

    while (b > 0)
    {
        if (b % 2 == 1)
            result = (result * a) % m;
        a = (a * a) % m;
        b /= 2;
    }

    return result;
}

// 快速幂的递归方法
long long quickpow2(long long a, long long b, long long m)
{
    if (b == 0)
        return 1;
    a %= m;
    if (b % 2 == 1)
        return (a * quickpow2(a, b - 1, m)) % m;
    else
    {
        long long half = quickpow2(a, b / 2, m);
        return (half * half) % m;
    }
}

int main()
{
    int a, b, m;
    cin >> a >> b >> m;
    int result1, result2;
    result1 = quickpow1(a, b, m);
    result2 = quickpow2(a, b, m);
    cout << result1 << " " << result2;
}