/*
    单调队列/滑动窗口
    一个长为 n 的序列 a, 一个大小为 k 的窗口, 现在从左向右滑动窗口, 每滑动一个单位, 求每次滑动后窗口中的最小值和最大值。
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e7;
int a[N], q[N];

int main()
{
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];

    int h = 1, t = 0;
    for (int i = 1; i <= n; i++)
    {
        while (h <= t && a[q[t]] >= a[i]) t--; // 队尾出队(队列不空且新元素更优)
        q[++t] = i;                            // 队尾入队
        if (q[h] < i - k + 1) h++;             // 队头出队(队头滑出窗口)
        if (i >= k) printf("%d ", a[q[h]]);    // 输出最值
    }
    cout << endl;
    
    h = 1, t = 0;
    for (int i = 1; i <= n; i++)
    {
        while (h <= t && a[q[t]] <= a[i]) t--;
        q[++t] = i;
        if (q[h] < i - k + 1) h++;
        if (i >= k) printf("%d ", a[q[h]]);
    }
    return 0;
}