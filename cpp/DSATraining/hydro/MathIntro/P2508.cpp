/*
[HAOI2008] 圆上的整点
题目描述
求一个给定的圆(x^2+y^2=r^2)，在圆周上有多少个点的坐标是整数。

输入格式
r

输出格式
整点个数

提示
r≤2000000000


这里的区域 以后再来探索吧
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

int main()
{
    LL r, n = 0;
    cin >> r;
    for (LL i = 0; i * i < r * r; i++)
    {
        LL y = r * r - i * i;
        LL qy = sqrt(y);
        if (y == qy * qy)
            n++;
    }
    n *= 4;
    cout << n;
    return 0;
}