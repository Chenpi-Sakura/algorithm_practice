/** 
 * @Author: Chenpi
 * @Date: 2025-08-11 12:54:21
 * @Link: https://www.luogu.com.cn/problem/P3870
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

#define lc p * 2
#define rc p * 2 + 1

typedef pair<int, int> PII;
const int N = 1e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f3f3f3f3fLL;

struct Node
{int l, r, s, t;} tr[N * 4];

void pushup(int p)
{
    tr[p].s = tr[lc].s + tr[rc].s;
}

void pushdown(int p)
{
    if (tr[p].t)
    {
        tr[lc].s = tr[lc].r - tr[lc].l + 1 - tr[lc].s;
        tr[rc].s = tr[rc].r - tr[rc].l + 1 - tr[rc].s;
        tr[lc].t = !tr[lc].t;
        tr[rc].t = !tr[rc].t;
        tr[p].t = 0;
    }
}

void build(int p, int l, int r)
{
    tr[p] = {l, r, 0, 0};
    if (l == r) return;
    int mid = (l + r) / 2;
    build(lc, l, mid);
    build(rc, mid + 1, r);
}

void update(int p, int l, int r)
{
    if (l <= tr[p].l && tr[p].r <= r)
    {
        tr[p].s = tr[p].r - tr[p].l + 1 - tr[p].s;
        tr[p].t = !tr[p].t;
        return;
    }
    pushdown(p);
    int mid = (tr[p].l + tr[p].r) / 2;
    if (l <= mid) update(lc, l, r);
    if (r > mid) update(rc, l, r);
    pushup(p);
}

int query(int p, int l, int r)
{
    if (l <= tr[p].l && tr[p].r <= r) return tr[p].s;
    pushdown(p);
    int res = 0, mid = (tr[p].l + tr[p].r) / 2;
    if (l <= mid) res += query(lc, l, r);
    if (r > mid) res += query(rc, l, r);
    return res;
}

void solve()
{
    int n, q; cin >> n >> q;
    build(1, 1, n);
    while (q--)
    {
        int op, a, b; cin >> op >> a >> b;
        if (!op) update(1, a, b);
        else cout << query(1, a, b) << endl;
    }
    // cout << 1 << endl;
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