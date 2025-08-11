/** 
 * @Author: Chenpi
 * @Date: 2025-08-09 10:13:50
 * @Link: https://www.luogu.com.cn/problem/P1531
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

#define lc p * 2
#define rc p * 2 + 1

typedef pair<int, int> PII;
const int N = 5e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f3f3f3f3fLL;

struct Node
{int l, r, m;} tr[N * 4];
int f[N][20], a[N];

void pushup(int p)
{
    tr[p].m = max(tr[lc].m, tr[rc].m);
}

void build(int p, int l, int r)
{
    tr[p] = {l, r};
    if (l == r)
    {
        tr[p].m = a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    pushup(p);
}

int query(int p, int l, int r)
{
    if (l <= tr[p].l && tr[p].r <= r) return tr[p].m;
    int res = 0, mid = (tr[p].l + tr[p].r) / 2;
    if (l <= mid) res = max(res, query(lc, l, r));
    if (r > mid) res = max(res, query(rc, l, r));
    return res;
}

void update(int p, int i, int k)
{
    if (tr[p].l == tr[p].r)
    {
        tr[p].m = k;
        return;
    }
    int mid = (tr[p].l + tr[p].r) / 2;
    if (i <= mid) update(lc, i, k);
    else update(rc, i, k);
    pushup(p);
}

void solve()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while (m--)
    {
        char op; int x, y;
        cin >> op >> x >> y;
        if (op == 'Q') cout << query(1, x, y) << endl;
        else if (a[x] < y) update(1, x, y), a[x] = y;
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