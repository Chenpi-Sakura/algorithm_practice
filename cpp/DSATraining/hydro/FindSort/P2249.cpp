/*
#P2249. 【深基13.例1】查找

题目描述
输入n个不超过10^9的单调不减的（就是后面的数字不小于前面的数字）非负整数a1,a2,...，an，然后进行m次询问。对于每次询问，给出一个整数q，要求输出这个数字在序列中第一次出现的编号，如果没有找到的话输出-1。

输入格式
第一行2个整数n和m，表示数字个数和询问次数。
第二行n个整数，表示这些待查询的数字。
第三行m个整数，表示询问这些数字的编号，从1开始编号。

输出格式
输出一行，m 个整数，以空格隔开，表示答案。
*/
#include <bits/stdc++.h>
using namespace std;

int n, m;

int main()
{
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        int t, l, r;
        cin >> t; // 目标
        l = 0;
        r = n;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if(a[mid] < t)
                l = mid + 1;
            else
                r = mid;
        }
        if (a[l] == t)
            cout << l + 1 << " ";
        else 
            cout << "-1 ";
    }
    return 0;
}