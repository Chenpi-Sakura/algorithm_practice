#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
} // 妙啊，不用自己找相对较大的数字，自身就能转过来

int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}