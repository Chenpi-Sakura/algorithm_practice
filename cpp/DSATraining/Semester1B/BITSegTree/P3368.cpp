/*
P3368 【模板】树状数组 2

题目描述
如题，已知一个数列，你需要进行下面两种操作：
1. 将某区间每一个数加上 x；
2. 求出某一个数的值。

输入格式
第一行包含两个整数 N M，分别表示该数列数字的个数和操作的总个数。
第二行包含 N 个用空格分隔的整数，其中第 i 个数字表示数列第 i 项的初始值。
接下来 M 行每行包含 2 或 4个整数，表示一个操作，具体如下：
操作 1： 格式：1 x y k 含义：将区间 [x,y] 内每个数加上 k；
操作 2： 格式：2 x 含义：输出第 x 个数的值。

输出格式
输出包含若干行整数，即为所有操作 2 的结果。
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;
int n, m, s[N];

int lowbit(int x) {return x & -x;}

void change(int x, int k)
{
    while (x <= n) s[x] += k, x += lowbit(x);
}

int query(int x)
{
    int t = 0;
    while (x) t += s[x], x -= lowbit(x);
    return t;
}

void solve()
{
    cin >> n >> m;
    int last = 0;
    for (int i = 1; i <= n; i++)
    {
        int k; cin >> k;
        change(i, k - last);
        last = k;
    }
    while (m--)
    {
        int q, x; cin >> q >> x;
        if (q == 1)
        {
            int y, k; cin >> y >> k;
            change(x, k);
            change(y + 1, -k);
        }
        else cout << query(x) << endl;
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