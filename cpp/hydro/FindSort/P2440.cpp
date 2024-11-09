/*
题目描述
木材厂有 n 根原木，现在想把这些木头切割成 k 段长度均为 l 的小段木头（木头有可能有剩余）。
当然，我们希望得到的小段木头越长越好，请求出l的最大值。
木头长度的单位是cm，原木的长度都是正整数，我们要求切割得到的小段木头的长度也是正整数。
例如有两根原木长度分别为11和21，要求切割成等长的6段，很明显能切割出来的小段木头长度最长为5。

输入格式
第一行是两个正整数n，k，分别表示原木的数量，需要得到的小段的数量。
接下来 n 行，每行一个正整数Li，表示一根原木的长度。

输出格式
仅一行，即l的最大值。
如果连1cm长的小段都切不出来，输出0。
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e8;
int n, k;
int a[N];

bool check(int mid)
{
    long long cnt = 0;
    for (int i = 0; i < n; i++)
    {
        cnt += a[i] / mid;
    }
    if (cnt >= k)
        return true; // 说明长度短了，可以增长长度
    else
        return false;
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int l = 1, r = N;
    if (!check(1)) // 如果连1cm长的小段都切不出来
    {
        cout << 0;
        return 0;
    }
    while (r > l)
    {
        int mid = (l + r + 1) / 2; // 向上取整
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    cout << l;
}