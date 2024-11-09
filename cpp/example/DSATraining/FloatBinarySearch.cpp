#include <bits/stdc++.h>
using namespace std;

bool check(double x);
int Hundred()
{
    double l, r;
    cin >> l >> r;
    int n;
    cin >> n;
    for (int i = 0; i <= 100; i++)
    {
        double mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l;
    return 0;
} // 计算100次

#define esp 1e-8
int smaller()
{
    double l, r;
    cin >> l >> r;
    int n;
    cin >> n;
    while (r - l > esp)
    {
        double mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l;
    return 0; // 计算到精度为1e-8为止
}

// 两种方式皆可