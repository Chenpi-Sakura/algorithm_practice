#include <bits/stdc++.h>
using namespace std;

//快速幂的迭代方式
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

//快速幂的递归方法
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