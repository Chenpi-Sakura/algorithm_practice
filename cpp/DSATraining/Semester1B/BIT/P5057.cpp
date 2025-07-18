/*
题目描述

有一个 n 个元素的数组，每个元素初始均为 0。有 m 条指令，每条指令为两种操作中的一种：

1.让一段连续序列数字反转（即 0 变 1，1 变 0）
2.询问某个元素的值

输入格式
第一行包含两个整数 n, m，表示数组的长度和指令的条数。
接下来 m 行，每行的第一个数 t 表示操作的种类：

1.若 t = 1，则接下来有两个数 L, R，表示反转区间 [L, R] 的每个数；
2.若 t = 2，则接下来只有一个数 i，表示询问的下标。

输出格式
每个操作 2 输出一行（非 0 即 1），表示每次操作 2 的回答。
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 5e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int tree[N], n, m;

int lowbit(int x) {return x & (-x);}

void change(int x, int k)
{
    while (x <= n)
    {
        tree[x] += k;
        x += lowbit(x);
    }
}

int query(int x)
{
    int t = 0;
    while (x)
    {
        t += tree[x];
        x -= lowbit(x);
    }
    return t;
}

void solve()
{
    cin >> n >> m;
    while (m--)
    {
        int t, l; cin >> t >> l;
        if (t == 1)
        {
            int r; cin >> r;
            change(l, 1);
            change(r + 1, -1);
        }
        else
        {
            int sum = query(l);
            cout << (sum & 1) << endl;
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); //cout.tie(0);
    int t; // cin >> t;
    t = 1;
    while (t--) solve();
    return 0;
}