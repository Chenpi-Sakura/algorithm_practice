/*
#P2367. 语文成绩

题目描述
语文老师总是写错成绩，所以当她修改成绩的时候，总是累得不行。她总是要一遍遍地给某些同学增加分数，又要注意最低分是多少。你能帮帮她吗？

输入格式
第一行有两个整数 n，p，代表学生数与增加分数的次数。
第二行有 n 个数，a1∼an ，代表各个学生的初始成绩。
接下来 p 行，每行有三个数，x，y，z，代表给第 x 个到第 y 个学生每人增加 z 分。

输出格式
输出仅一行，代表更改分数后，全班的最低分。
*/

#include <iostream>
#include <algorithm>
using namespace std;

int a[5000001];
int d[5000001];
int main()
{
    int n, p, x, y, z, minSocre = 1e9;
    cin >> n >> p;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= p; i++)
    {
        cin >> x >> y >> z;
        d[x] += z;
        d[y + 1] -= z;
    }

    for (int i = 1; i <= n; i++)
    {
        d[i] += d[i - 1];
        a[i] += d[i];
        minSocre = min(minSocre, a[i]);
    }
    cout << minSocre;

    return 0;
}
