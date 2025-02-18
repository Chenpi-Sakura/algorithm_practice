/*
    桶排序
    本质是一种对于在一定数据范围内的数据分组后的排序，
    在算法中的体现就是运用数组来模拟桶，进而降低时间复杂度
*/

#include<bits/stdc++.h>
using namespace std;

const int N = 1e7 + 100;
int a[N], cnt[N]; // 数组 桶
int tot = 0;

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp; cin >> temp;
        cnt[temp]++;
    }

    for (int i = 0; i <= 10000000; i++)
    {
        for (int j = 0; j < cnt[i]; j++)
        {
            a[tot++] = i;
        }
    }

    for (int i = 0; i < tot; i++) cout << a[i] << " ";

    return 0;
}