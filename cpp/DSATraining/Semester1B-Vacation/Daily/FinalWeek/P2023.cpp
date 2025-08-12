/** 
 * @Author: Chenpi
 * @Date: 2025-08-11 14:47:10
 * @Link: https://www.luogu.com.cn/problem/P2023
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
{int l, r, sum, add, mul;} tr[N * 4];
int MOD, a[N];

void pushup(int p)
{
    tr[p].sum = (tr[lc].sum + tr[rc].sum) % MOD;
}

void pushdown(int p)
{
    if (tr[p].add || tr[p].mul != 1)
    {
        int llen = tr[lc].r - tr[lc].l + 1;
        int rlen = tr[rc].r - tr[rc].l + 1;
        tr[lc].sum = (tr[lc].sum * tr[p].mul % MOD + tr[p].add * llen % MOD) % MOD;
        tr[lc].add = (tr[p].add + tr[lc].add * tr[p].mul % MOD) % MOD;
        tr[lc].mul = tr[lc].mul * tr[p].mul % MOD;
        tr[rc].sum = (tr[rc].sum * tr[p].mul % MOD + tr[p].add * rlen % MOD) % MOD;
        tr[rc].add = (tr[p].add + tr[rc].add * tr[p].mul % MOD) % MOD;
        tr[rc].mul = tr[rc].mul * tr[p].mul % MOD;
        tr[p].add = 0;
        tr[p].mul = 1;
    }
}

void build(int p, int l, int r)
{
    tr[p] = {l, r, 0, 0, 1};
    if (l == r) 
    {
        tr[p].sum = a[l] % MOD;
        return;
    }
    int mid = (l + r) / 2;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    pushup(p);
}

void pupdate(int p, int l, int r, int k)
{
    if (l <= tr[p].l && tr[p].r <= r)
    {
        tr[p].sum = (tr[p].sum + (tr[p].r - tr[p].l + 1) * k % MOD) % MOD;
        tr[p].add = (tr[p].add + k) % MOD;
        return;
    }
    pushdown(p);
    int mid = (tr[p].l + tr[p].r) / 2;
    if (l <= mid) pupdate(lc, l, r, k);
    if (r > mid) pupdate(rc, l, r, k);
    pushup(p);
}

void tupdate(int p, int l, int r, int k)
{
    if (l <= tr[p].l && tr[p].r <= r)
    {
        tr[p].sum = (tr[p].sum * k) % MOD;
        tr[p].mul = (tr[p].mul * k) % MOD;
        tr[p].add = (tr[p].add * k) % MOD;
        return;
    }
    pushdown(p);
    int mid = (tr[p].l + tr[p].r) / 2;
    if (l <= mid) tupdate(lc, l, r, k);
    if (r > mid) tupdate(rc, l, r, k);
    pushup(p);
}

int query(int p, int l, int r)
{
    if (l <= tr[p].l && tr[p].r <= r) return tr[p].sum;
    pushdown(p);
    int res = 0, mid = (tr[p].l + tr[p].r) / 2;
    if (l <= mid) res = (res + query(lc, l, r)) % MOD;
    if (r > mid) res = (res + query(rc, l, r)) % MOD;
    return res;
}

void solve()
{
    int n; cin >> n >> MOD;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    int q; cin >> q;
    while (q--)
    {
        int op, a, b, c; cin >> op >> a >> b;
        if (op == 1) 
        {
            cin >> c;
            tupdate(1, a, b, c);
        }
        else if (op == 2)
        {
            cin >> c;
            pupdate(1, a, b, c);
        }
        else cout << query(1, a, b) << endl;
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