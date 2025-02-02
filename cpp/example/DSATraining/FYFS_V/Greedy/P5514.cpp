/*
题目描述
蓬莱山 辉夜(Kaguya)手里有一堆数字。
辉夜手里有 n 个非负整数 a1, a2 ... an，由于辉夜去打 Gal Game 去了，她希望智慧的你来帮忙。
你需要将这些数分成若干组，满足 n 个数中的每一个数都恰好被分到了一个组中，且每一组至少包含一个数。
定义一组数的权值为该组内所有数的异或和。请求出一种分组方案，使得分出的所有组数的权值之和最小，输出权值之和的最小值。

输入格式
输入的第一行包含一个正整数 n，表示给定的非负整数的数量。
接下来一行包含 n 个非负整数 a1, a2 ... an。

输出格式
输出一行一个整数表示答案。
*/
/*
重点是理解到 a XOR b <= a + b
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;
int a[N];
int ans = 0;

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
        ans ^= a[i];
    }

    cout << ans << endl;
    return 0;
}