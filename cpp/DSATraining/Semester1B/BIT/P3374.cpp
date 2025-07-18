/*
P3374 模板 树状数组 1

题目描述
如题，已知一个数列，你需要进行下面两种操作：
1.将某一个数加上 x
2.求出某区间每一个数的和

输入格式
第一行包含两个正整数 n, m，分别表示该数列数字的个数和操作的总个数。
第二行包含 n 个用空格分隔的整数，其中第 i 个数字表示数列第 i 项的初始值。
接下来 m 行每行包含 3 个整数，表示一个操作，具体如下：   
1 x k 含义：将第 x 个数加上 k
2 x y 含义：输出区间 [x, y] 内每个数的和

输出格式
输出包含若干行整数，即为所有操作 2 的结果。
输入输出样例 #1   

输入 #1

5 5
1 5 4 2 3
1 1 3
2 2 5
1 3 -1
1 4 2
2 1 4

输出 #1

14
16

说明/提示
数据范围
对于 30% 的数据，1 <= n <= 8，1 <= m <= 10；
对于 70% 的数据，1 <= n, m <= 10^4；
对于 100% 的数据，1 <= n, m <= 5*10^5。
数据保证对于任意时刻，a 的任意子区间（包括长度为 1 和 n 的子区间）和均在 [-2^31, 2^31) 范围内。

样例说明：
初始数列：1 5 4 2 3
操作 1 1 3：数列变为 4 5 4 2 3
操作 2 2 5：求区间 [2, 5] 的和，5 + 4 + 2 + 3 = 14。输出 14。
操作 1 3 -1：数列变为 4 5 3 2 3
操作 1 4 2：数列变为 4 5 3 4 3
操作 2 1 4：求区间 [1, 4] 的和，4 + 5 + 3 + 4 = 16。输出 16。
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

// 修改当前位和区间和大小 （向后修）
void change(int x, int k)
{ 
    while (x <= n) s[x] += k, x += lowbit(x);
}

// 求前缀和，向前查
int query(int x)
{
    int t = 0;
    while (x) t += s[x], x -= lowbit(x);
    return t;
}

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        change(i, x);
    }
    while (m--)
    {
        int q, x, y; cin >> q >> x >> y;
        if (q == 1) change(x, y);
        else cout << query(y) - query(x - 1) << endl;
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