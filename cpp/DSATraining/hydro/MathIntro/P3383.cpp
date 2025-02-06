/*
P3383【模板】线性筛素数
题目背景
本题已更新，从判断素数改为了查询第 k 小的素数
提示：如果你使用 cin 来读入，建议使用 std::ios::sync_with_stdio(0) 来加速。

题目描述
如题，给定一个范围 n，有 q 个询问，每次输出第 k 小的素数。

输入格式
第一行包含两个正整数 n,q，分别表示查询的范围和查询的个数。

接下来 q 行每行一个正整数 k，表示查询第 k 小的素数。

输出格式
输出 q 行，每行一个正整数表示答案。
*/

#include <bits/stdc++.h>
using namespace std;

const int N = 1e8;
bool b[N];
int prime[N];
int tot;

void sieve(int n)
{
    fill(b, b + n + 1, true);
    b[0] = b[1] = false;
    for (int i = 2; i <= n; i++)
    {
        if (b[i])
        {
            prime[tot++] = i;
        }
        for (int j = 0; i * prime[j] <= n; j++)
        {
            b[i * prime[j]] = false;
            if (i % prime[j] == 0)
                break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    int n, q;
    cin >> n >> q;
    sieve(n);
    for (int i = 0; i < q; i++)
    {
        int k;
        cin >> k;
        cout << prime[k - 1] << '\n';
    }
    return 0;
}
