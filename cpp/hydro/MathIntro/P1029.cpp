/*
P1029 [NOIP2001 普及组] 最大公约数和最小公倍数问题
题目描述
输入两个正整数 x0 ,y0，求出满足下列条件的 P,Q 的个数：
    1.P,Q 是正整数。
    2.要求 P,Q 以 x0为最大公约数，以 y0 为最小公倍数。
试求：满足条件的所有可能的 P,Q 的个数。

输入格式
一行两个正整数 x0,y0。

输出格式
一行一个数，表示求出满足条件的 P,Q 的个数。
*/

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}

int main()
{
    int x, y, t = 0;
    cin >> x >> y;
    int i = x * y;
    for (int a = x; a * a <= x * y; a++)
    {
        if (i % a == 0 && gcd(a, i / a) == x)
        {
            t += 2; // 加二是因为会有两种情况
        }
    }
    if (x == y)
        t--; // 相等时只有一种情况 a = b
    cout << t;
    return 0;
}