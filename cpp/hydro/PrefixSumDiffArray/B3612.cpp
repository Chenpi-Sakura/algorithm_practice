/*
#B3612. 【深进1.例1】求区间和

题目描述
给定n个正整数组成的数列a1，a2,··,an和m个区间[li，ri]，分别求这m个区间的区间和。

输入格式
第一行，为一个正整数n。
第二行，为 n 个正整数a1，a2,··,an
第三行，为一个正整数m。
接下来m行，每行为两个正整数li，ri，满足1 ≤ li ≤ ri ≤n

输出格式
共m行
第i行为第i组答案的询问。

Pay Attention!
这是一个闭区间li也要加上结果！！
*/

#include <iostream>
using namespace std;

int main()
{
    int n, m;
    cin >> n;
    int a[n + 1], s[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        s[i] = a[i] + s[i - 1];
    }
    cin >> m;
    int b[m + 1][2];
    for (int i = 1; i <= m; i++)
    {
        cin >> b[i][0] >> b[i][1];
    }

    for (int i = 1; i <= m; i++)
    {
        cout << s[b[i][1]] - s[b[i][0] - 1] << endl;
    }

    return 0;
}