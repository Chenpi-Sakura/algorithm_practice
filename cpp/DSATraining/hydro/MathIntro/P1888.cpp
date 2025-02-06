/*
#P1888. 三角函数
题目描述
输入一组勾股数 a, b, c（a != b != c），用分数格式输出其较小锐角的正弦值。（要求约分。）

输入格式
一行，包含三个正整数，即勾股数 a,b,c（无大小顺序）。

输出格式
一行，包含一个分数，即较小锐角的正弦值
*/

#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    int max = a[0], min = a[0];
    for (int i = 1; i < 3; i++)
    {
        if (max < a[i])
            max = a[i];
        if (min > a[i])
            min = a[i];
    }
    int g = gcd(max, min);
    max /= g, min /= g;
    cout << min << "/" << max;
}