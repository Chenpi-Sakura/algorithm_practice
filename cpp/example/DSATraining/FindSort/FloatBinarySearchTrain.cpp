/*
P1024 [NOIP2001 提高组] 一元三次方程求解

题目描述
有形如：ax^3 + bx^2 + cx + d =0这样的一个一元三次方程。给出该方程中各项的系数（a，b，c，d均为实数），并约定该方程存在三个不同实根（根的范围在-100至100之间），且根与根之差的绝对值≥1。  ⌈重点，我们可以间隔一个数字一个数字找⌋  要求由小到大依次在同一行输出这三个实根(根与根之间留有空格)，并精确到小数点后2位。
提示：记方程 f(x)=0，若存在2个数x1和x2，且x1<x2，f(x1)×f(x2)<0，则在（x1,x2)之间一定有一个根。

输入格式
一行，4个实数a,b,c,d。

输出格式
一行，3个实根，从小到大输出，并精确到小数点后2位。
*/

#include <bits/stdc++.h>
using namespace std;

#define esp 1e-8
double a, b, c, d;
double fx(double x)
{
    return a * x * x * x + b * x * x + c * x + d;
} // a,b,c,d为全局变量故不需要接收a,b,c,d的值

int main()
{
    cin >> a >> b >> c >> d;
    for (int i = -100; i <= 100; i++)
    {
        double x1 = i, x2 = i + 1;
        double y1 = fx(x1), y2 = fx(x2);
        if (!y1)
            printf("%.2lf ", x1); // 若有刚好满足的点则直接输出，避免出现重复输出的问题
        if (y1 * y2 < 0)
        {
            while (x2 - x1 > esp)
            {
                double mid = (x2 + x1) / 2;
                if (fx(mid) * fx(x2) <= 0)
                    x1 = mid;
                else
                    x2 = mid;
            }
            printf("%.2lf ", x1); // 若有解则一定在两个点之间，用二分法找根
        }
    }
}