/*
P1024 [NOIP2001 提高组] 一元三次方程求解

题目描述
有形如：ax^3 + bx^2 + cx + d = 0这样的一个一元三次方程。给出该方程中各项的系数（a, b , c , d均为实数），并约定该方程存在三个不同实根（根的范围在-100至100之间），且根与根之差的绝对值≥1。要求由小到大依次在同一行输出这三个实根（根与根之间留有空格），并精确到小数点后2位。
提示：记方程f(x)=0，若存在2个x1和x2，且x1<x2，f(x1) × f(x2)< 0，则在（x1，x2)之间一定有一个根。

输入格式
一行，4个实数a,b,c,d.

输出格式
一行，3个实根，从小到大输出，并精确到小数点后2位。
*/
#include <bits/stdc++.h>
using namespace std;
#define esp 1e-8

double a, b, c, d;

double f(double x)
{
    return a * x * x * x + b * x * x + c * x + d;
}

int main()
{
    cin >> a >> b >> c >> d;
    for (int i = -100; i <= 100; i++)
    {
        if (!f(i))
        {
            printf("%.2lf ", (double)i);
        }
        else if (f(i) * f(i + 1) < 0)
        {
            double l = i, r = i + 1;
            while (r - l > esp)
            {
                double mid = (l + r) / 2;
                if (f(mid) * f(r) < 0) // 检测条件不能错啦
                    l = mid;
                else
                    r = mid;
            }
            printf("%.2lf ", l);
        }
    }
}