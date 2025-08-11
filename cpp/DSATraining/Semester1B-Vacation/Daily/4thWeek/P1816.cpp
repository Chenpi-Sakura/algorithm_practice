/** 
 * @Author: Chenpi
 * @Date: 2025-08-09 09:30:17
 * @Link: https://www.luogu.com.cn/problem/P1816
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 1e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f3f3f3f3fLL;

// SegTree.ver

#define lc p * 2
#define rc p * 2 + 1

struct Node
{int l, r, m;} tr[N * 4];

int a[N];

void pushup(int p)
{
    tr[p].m = min(tr[lc].m, tr[rc].m);
}

void build(int p, int l, int r)
{
    tr[p] = {l, r};
    if (l == r)
    {
        tr[p].m = a[l];
        return;
    }
    int m = (l + r) / 2;
    build(lc, l, m);
    build(rc, m + 1, r);
    pushup(p);
}

int query(int p, int l, int r)
{
    if (l <= tr[p].l && tr[p].r <= r) return tr[p].m;
    int m = (tr[p].l + tr[p].r) / 2, res = inf;
    if (l <= m) res = min(res, query(lc, l, r));
    if (r > m) res = min(res, query(rc, l, r));
    return res;
}

void solve()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    for (int i = 1; i <= m; i++)
    {
        int l, r; cin >> l >> r;
        cout << query(1, l, r) << ' ';
    }
}

// ST.ver

// int n, m;
// int f[N][20], a[N];

// void pre()
// {
//     for (int i = 1; i <= n; i++) f[i][0] = a[i];
//     int t = log2(n) + 1;
//     for (int j = 1; j < t; j++)
//     {
//         for (int i = 1; i <= n - (1 << j) + 1; i++)
//         {
//             f[i][j] = min(f[i][j - 1], f[i + (1 << (j - 1))][j - 1]);
//         }
//     }
// }

// int query(int l, int r)
// {
//     int j = log2(r - l + 1);
//     return min(f[l][j], f[r - (1 << j) + 1][j]);
// }

// void solve()
// {
//     cin >> n >> m;
//     for (int i = 1; i <= n; i++) cin >> a[i];
//     pre();
//     for (int i = 1; i <= m; i++)
//     {
//         int l, r; cin >> l >> r;
//         cout << query(l, r) << ' ';
//     }
// }

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