/*
公路维修问题
题目描述
由于长期没有得到维修，A国的高速公路上出现了 n 个坑。为了尽快填补好这 n 个坑，A国决定对 m 处地段采取交通管制。为了求解方便，假设A国的高速公路只有一条，而且是笔直的。现在给出 n 个坑的位置，请你计算，最少要对多远的路段实施交通管制？

输入格式
输入数据共两行，第一行为两个正整数 n,m(2≤m≤n≤15000)。
第二行给出了 n 个坑的坐标（坐标值均在长整范围内，按从小到大的顺序给出，且不会有两个点坐标相同）。

输出格式
仅一行，为最小长度和。
*/
#include<bits/stdc++.h> 
using namespace std;

const int N = 1e7;
int a[N], d[N];

int main( )
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i < n; i++)
    {
        d[i] = a[i + 1] - a[i];
    }
    int ans = a[n] - a[1] + 1;
    sort(d + 1, d + n, greater<int>());

    for (int i = 1; i < m; i++) ans -= d[i] - 1;

    cout << ans << endl;
    return 0;
}