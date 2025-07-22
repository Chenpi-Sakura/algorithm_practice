/*
 * @Author: Chenpi
 * @Date: 2025-07-21 12:49:10
 * @Link: https://www.luogu.com.cn/problem/P3865
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 1e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int n, q;
int f[N][20], a[N];

void pre()
{
    for (int i = 1; i <= n; i++) f[i][0] = a[i];
    int t = log2(n) + 1;
    for (int j = 1; j < t; j++)
        for (int i = 1; i <= n - (1 << j) + 1; i++)
            f[i][j] = max(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
}

int query(int l, int r)
{
    int k = log2(r - l + 1);
    return max(f[l][k], f[r - (1 << k) + 1][k]);
}

void solve()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    pre();
    while (q--)
    {
        int l, r; cin >> l >> r;
        cout << query(l, r) << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}