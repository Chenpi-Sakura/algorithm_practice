
/*
#P1923. 【深基9.例4】求第 k 小的数

题目描述
输入 n (1 <= n <= 5000000 且 n 为奇数)个数字 ai (1 <= ai < 10^9), 输出这些数字的第k小的数。最小的数是第 0 小。
*/

#include <bits/stdc++.h>
using namespace std;

int n, k;

void quick_sort(vector<int> &a, int l, int r)
{
    if (l >= r)
        return;
    int i = l - 1;
    int j = r + 1;
    int mid = a[(i + j) >> 1];
    while (i < j)
    {
        do
            i++;
        while (a[i] < mid);
        do
            j--;
        while (a[j] > mid);
        if (i < j)
            swap(a[i], a[j]);
    }
    if (k < j)
        quick_sort(a, l, j);
    else if (k > j)
        quick_sort(a, j + 1, r);
}

int main()
{
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quick_sort(arr, 0, n - 1);
    cout << arr[k];
}