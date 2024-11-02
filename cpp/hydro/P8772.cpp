/*
#P8772. [蓝桥杯 2022 省 A] 求和

给定n个整数a1,a2,...,an,求它们两两相乘再相加的和，即
S = a1 * a2 + a1 * a3 + ... +a1 * an + a2 * a3 + ... + an - 1 * an
*/

#include <iostream>
using namespace std;

int main()
{
    long long n, sum = 0;
    cin >> n;
    long long a[n + 2], s[n + 2];
    for (long long i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = a[i] + s[i - 1];
    }
    for (long long i = 1; i < n; i++)
    {
        sum += a[i] * (s[n] - s[i]);
    }
    cout << sum;

    return 0;
}

// 还是不要在main外定义了吧，也尽量把大小控制好，好多问题。。