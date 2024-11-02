/*
#P5638. 【CSGRound2】光骓者的荣耀

题目描述
小K打下的江山一共有n个城市，城市i和城市i+1有一条双向高速公路连接，走这条路要耗费时间ai。
小K为了关心人民生活，决定定期进行走访。他每一次会从1号城市到n号城市并在经过的城市进行访问。其中终点必须为城市n。
不仅如此，他还有一个传送器，传送半径为k，也就是可以传送到i-k和i+k。如果目标城市编号小于1则为1，大于n则为n。
但是他的传送器电量不足，只能传送一次，况且由于一些原因，他想尽量快的完成访问，于是就想问交通部部长您最快的时间是多少。
注意：他可以不访问所有的城市，使用传送器不耗费时间。

输入格式
两行，第一行n,k。
第二行n—1个整数，第i个表示ai。

Reflection:
找到[i, i+k]区间内数字之和最小的区间
再加上s[i] 和 s[n] - s[i + k]
*/

#include <iostream>
using namespace std;

int main()
{
    long long n, k, t;
    cin >> n >> k;
    long long a[n + 1] = {0}, s[n + 1] = {0};
    for (long long i = 1; i <= n - 1; i++)
    {
        cin >> a[i];
        s[i] = a[i] + s[i - 1];
    }
    long long max = -1;

    for (long long i = 0; (i + k) <= n - 1; i++) // i从0开始防止第一个城市不能跳过
    {
        if ((s[i + k] - s[i] > max))
        {
            max = s[i + k] - s[i];
        }
    }
    t = s[n - 1] - max;

    cout << t;

    return 0;
}