/** 
 * @Author: Chenpi
 * @Date: 2025-08-08 19:51:44
 * @Link: https://www.luogu.com.cn/problem/P2880
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

#define lc p * 2
#define rc p * 2 + 1

typedef pair<int, int> PII;
const int N = 5e4 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f3f3f3f3fLL;

// SegTree.ver

struct node
{int l, r, maxv, minv;} tr[N * 4];
int a[N], n, q;

void pushup(int p)
{
    tr[p].maxv = max(tr[lc].maxv, tr[rc].maxv);
    tr[p].minv = min(tr[lc].minv, tr[rc].minv);
}

void build(int p, int l, int r)
{
    tr[p] = {l, r, 0, 0};
    if (l == r)
    {
        tr[p].maxv = a[l];
        tr[p].minv = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    pushup(p);
}

PII query(int p, int l, int r)
{
    if (l <= tr[p].l && tr[p].r <= r) return {tr[p].maxv, tr[p].minv};
    int mid = (tr[p].l + tr[p].r) / 2;
    int maxv = -inf, minv = inf;
    if (l <= mid)
    {
        PII res = query(lc, l, r);
        maxv = max(maxv, res.first);
        minv = min(minv, res.second);
    }
    if (r > mid)
    {
        PII res = query(rc, l, r);
        maxv = max(maxv, res.first);
        minv = min(minv, res.second);
    }
    return {maxv, minv};
}

void solve()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while (q--)
    {
        int l, r; cin >> l >> r;
        PII ans = query(1, l, r);
        cout << ans.first - ans.second << endl;
    }
}

// ST.ver

// int n, q;
// int hig[N][20], low[N][20], a[N];

// void pre()
// {
//     for (int i = 1; i <= n; i++) hig[i][0] = low[i][0] = a[i];
//     int t = log2(n) + 1;
//     for (int j = 1; j < t; j++)
//         for (int i = 1; i <= n - (1 << j) + 1; i++)
//         {
//             hig[i][j] = max(hig[i][j - 1], hig[i + (1 << (j - 1))][j - 1]);
//             low[i][j] = min(low[i][j - 1], low[i + (1 << (j - 1))][j - 1]);
//         }
// }

// int query(int l, int r)
// {
//     int k = log2(r - l + 1);
//     return max(hig[l][k], hig[r - (1 << k) + 1][k]) - min(low[l][k], low[r - (1 << k) + 1][k]);
// }

// void solve()
// {
//     cin >> n >> q;
//     for (int i = 1; i <= n; i++) cin >> a[i];
//     pre();
//     while (q--)
//     {
//         int l, r; cin >> l >> r;
//         cout << query(l, r) << endl;
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