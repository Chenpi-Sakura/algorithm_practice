/*
[USACO1.2] 挤牛奶Milking Cows
题目描述
三个农民每天清晨 5 点起床，然后去牛棚给三头牛挤奶。
第一个农民在 300 秒 (从 5 点开始计时) 给他的牛挤奶，一直到 1000 秒。
第二个农民在 700 秒开始，在 1200 秒结束。
第三个农民在 1500 秒开始，2100 秒结束。

期间最长的至少有一个农民在挤奶的连续时间为 900 秒 (从 300 秒到 1200 秒)，
而最长的无人挤奶的连续时间(从挤奶开始一直到挤奶结束)为 300 秒 (从 1200 秒到 1500 秒)。

你的任务是编一个程序，读入一个有 n 个农民挤 n 头牛的工作时间列表，计算以下两点(均以秒为单位):
最长至少有一人在挤奶的时间段。
最长的无人挤奶的时间段。（从有人挤奶开始算起）

输入格式
第一行一个正整数 n
接下来 n 行，每行两个非负整数 l,r，表示一个农民的开始时刻与结束时刻。

输出格式
一行，两个整数，即题目所要求的两个答案。
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;
int a[N];

int main()
{
    int n; cin >> n;
    int TimeRange = -1;
    for (int i = 1; i <= n; i++)
    {
        int l, r;
        cin >> l >> r;
        a[l + 1]++; a[r + 1]--; // 挤奶时间区间左开右闭
        TimeRange = max(TimeRange, r);
    }

    for (int i = 1; i <= TimeRange; i++)
    {
        a[i] += a[i - 1];
    }

    int i = 0;
    while (a[i] == 0) i++;

    int LMT = 0, LUT = 0, l, r;
    while (i <= TimeRange)
    {
        if(a[i] > 0)
        {
            l = i;
            while (a[i] > 0 && i <= TimeRange) i++;
            r = i;
            LMT = max(LMT, r - l);
        }
        else if (a[i] == 0)
        {
            l = i;
            while (a[i] == 0 && i <= TimeRange) i++;
            r = i;
            LUT = max(LUT, r - l);
        }
    }

    cout << LMT << " " << LUT;
    return 0;
}