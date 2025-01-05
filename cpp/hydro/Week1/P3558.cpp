/*
题目大意
给定一个长度为 n 的只包含 −1,0,1 的数列 a，每次操作可以使 ai = ai + ai−1，求最少操作次数使得序列非单调递减。如果不可能通过该操作使得序列非单调递减，请输出 BRAK。

数据范围：1≤n≤10^6。
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int n;
int a[N];

int check()
{
    int times = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i - 1] > a[i])
        {
            if (a[i - 1] <= 0)
            {
                // 无法通过操作使 a[i] 增加到 a[i-1] 或更高
                return -1;
            }
            // 计算需要的操作次数
            int ops = a[i - 1] - a[i];
            times += ops;
            a[i] += ops * a[i - 1];
        }
    }
    return times;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int res = check();
    if (res != -1)
        cout << res << endl;
    else
        cout << "BRAK" << endl;
    return 0;
}