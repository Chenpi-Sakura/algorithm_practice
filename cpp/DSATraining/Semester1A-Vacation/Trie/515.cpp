/*
【模板】字典树 2
题目描述
Macesuted 给了你 n 个整数。
他想要知道任意两数异或和最大是多少。

输入格式
第一行一个整数 n，表示输入整数的数量。
接着一行 n 个整数，表示 ai。

输出格式
一行一个整数，表示任意两数异或和的最大值。

输入数据 1
10
2 3 9 4 8 2 1 3 5 7
输出数据 1
15
说明
8⊕7=15
*/

#include<bits/stdc++.h> 
using namespace std;

const int N = 1e6 + 10;
int a[N];
int ch[N * 31][2], idx;

void insert(int x)
{
    int p = 0;
    for (int i = 30; i >= 0; i--)
    {
        int j = (x >> i) & 1;
        if (ch[p][j] == 0) ch[p][j] = ++idx;
        p = ch[p][j];
    } 
}

int query(int x)
{
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i--)
    {
        int j = (x >> i) & 1;
        if (ch[p][!j])
        {
            res += 1 << i;
            p = ch[p][!j];
        }
        else p = ch[p][j];
    }
    return res;
}

int main( )
{
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i]; 
        insert(a[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, query(a[i]));
    }

    cout << ans << endl;
    return 0;
}