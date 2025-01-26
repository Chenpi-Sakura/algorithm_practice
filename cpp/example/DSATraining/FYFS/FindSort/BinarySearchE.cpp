#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l, r;
    cin >> l >> r; // 左右边界
    int x;
    cin >> x; // 查找值
/*     while (l < r)
    {
        int mid = (l + r) / 2; // 向下取整，目的是把数据往左边靠，防止死循环
        if (mid < x)
            l = mid + 1; // 数据在右半部分，注意这里是mid+1，因为mid已经被排除了
        else
            r = mid; // 数据在左半部分
    }
    cout << l; */
    while (l < r)
    {
        int mid = (l + r + 1) / 2; // 向上取整，目的是把数据往右边靠，防止死循环
        if (mid > x)
            r = mid - 1; // 数据在左半部分，注意这里是mid-1，因为mid已经被排除了
        else
            l = mid; // 数据在右半部分
    }
    cout << l;
    return 0;
}