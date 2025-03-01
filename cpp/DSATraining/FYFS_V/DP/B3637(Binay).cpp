/*
最长上升子序列
题目描述
这是一个简单的动规板子题。
给出一个由 n(n≤5000) 个不超过 10^6 的正整数组成的序列。请输出这个序列的最长上升子序列的长度。
最长上升子序列是指，从原序列中按顺序取出一些数字排在一起，这些数字是逐渐增大的。

输入格式
第一行，一个整数 n，表示序列长度。
第二行有 n 个整数，表示这个序列。

输出格式
一个整数表示答案。

输入数据 1
6
1 2 4 1 3 4
输出数据 1
4

*/
#include<bits/stdc++.h>
using namespace std;

const int N = 5e3 + 10;
int a[N], b[N]; // b[N] 储存最长上升子序列
int n, len; // 序列长度，有序子序列长度

int find(int x)
{ // 二分查找第一个大于等于 x 的位置
    int l = 0, r = len + 1;
    while (l + 1 < r)
    {
        int mid = (l + r) / 2;
        if (b[mid] >= x) r = mid;
        else l = mid;
    }

    return r;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    len = 1; b[1] = a[1];
    for (int i = 2; i <= n; i++)
    { // 动态更新 b 数组
        if (a[i] > b[len]) b[++len] = a[i]; // 大于则增加
        else 
        { // 小于等于则替换
            int j = find(a[i]);
            b[j] = a[i];
        }
        
    }
    cout << len << endl;
    return 0;
}