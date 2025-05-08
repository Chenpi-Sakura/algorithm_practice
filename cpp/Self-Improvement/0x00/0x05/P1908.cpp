/*
数组中的逆序对
在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;

long long res;
int a[N], b[N];

void cal(int l, int r)
{
    if (l >= r) return;
    int mid = (l + r) / 2;
    cal(l, mid);
    cal(mid + 1, r);

    int i = l, j = mid + 1, k = l;
    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j]) b[k++] = a[i++];
        else b[k++] = a[j++], res += mid - i + 1;
    }
    while (i <= mid) b[k++] = a[i++];
    while (j <= r) b[k++] = a[j++];
    for (i = l; i <= r; i++) a[i] = b[i];
}

int main()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    cal(1, n);
    cout << res;
    return 0;
}