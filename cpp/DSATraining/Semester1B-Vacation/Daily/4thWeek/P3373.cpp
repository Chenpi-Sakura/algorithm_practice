/** 
 * @Author: Chenpi
 * @Date: 2025-08-08 10:23:40
 * @Link: https://www.luogu.com.cn/problem/P3373
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

struct node
{int l, r, sum, add, mul;} tr[4 * N];
int w[N], mod;

void pushup(int p)
{
    tr[p].sum = (tr[lc].sum + tr[rc].sum) % mod;
}

void pushdown(int p)
{
    if (tr[p].add || tr[p].mul != 1)
    {
        int llen = tr[lc].r - tr[lc].l + 1;
        int rlen = tr[rc].r - tr[rc].l + 1;
        tr[lc].sum = (tr[lc].sum * tr[p].mul + tr[p].add * llen) % mod;
        tr[lc].mul = (tr[lc].mul * tr[p].mul) % mod;
        tr[lc].add = (tr[lc].add * tr[p].mul + tr[p].add) % mod;
        tr[rc].sum = (tr[rc].sum * tr[p].mul + tr[p].add * rlen) % mod;
        tr[rc].mul = (tr[rc].mul * tr[p].mul) % mod;
        tr[rc].add = (tr[rc].add * tr[p].mul + tr[p].add) % mod;
        tr[p].mul = 1;
        tr[p].add = 0;
    }
}

void build(int p, int l, int r)
{
    tr[p] = {l, r, 0, 0, 1};
    if (l == r) 
    {
        tr[p].sum = w[l] % mod;
        return;
    }
    int m = (l + r) / 2;
    build(lc, l, m);
    build(rc, m + 1, r);
    pushup(p);
}

void pUpdate(int p, int l, int r, int k)
{
    if (l <= tr[p].l && tr[p].r <= r)
    {
        tr[p].sum = (tr[p].sum + k * (tr[p].r - tr[p].l + 1)) % mod;
        tr[p].add = (tr[p].add + k) % mod;
        return;
    }
    int m = (tr[p].l + tr[p].r) / 2;
    pushdown(p);
    if (l <= m) pUpdate(lc, l, r, k);
    if (r > m) pUpdate(rc, l, r, k);
    pushup(p);
}

void tUpdate(int p, int l, int r, int k)
{
    if (l <= tr[p].l && tr[p].r <= r)
    {
        tr[p].sum = (tr[p].sum * k) % mod;
        tr[p].mul = (tr[p].mul * k) % mod;
        tr[p].add = (tr[p].add * k) % mod;
        return;
    }
    pushdown(p);
    int m = (tr[p].l + tr[p].r) / 2;
    if (l <= m) tUpdate(lc, l, r, k);
    if (r > m) tUpdate(rc, l, r, k);
    pushup(p);
}

int query(int p, int l, int r)
{
    if (l <= tr[p].l && tr[p].r <= r) return tr[p].sum;
    int res = 0, m = (tr[p].l + tr[p].r) / 2;
    pushdown(p);
    if (l <= m) res = (res + query(lc, l, r)) % mod;
    if (r > m) res = (res + query(rc, l, r)) % mod;
    return res;
}

void solve()
{
    int n, q; cin >> n >> q >> mod;
    for (int i = 1; i <= n; i++) cin >> w[i];
    build(1, 1, n);
    while (q--)
    {
        int op, x, y, k; cin >> op >> x >> y;
        if (op == 1)
        {
            cin >> k;
            tUpdate(1, x, y, k);
        }
        else if (op == 2)
        {
            cin >> k;
            pUpdate(1, x, y, k);
        }
        else cout << query(1, x, y) << endl;
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