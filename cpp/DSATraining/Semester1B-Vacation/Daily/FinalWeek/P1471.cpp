/** 
 * @Author: Chenpi
 * @Date: 2025-08-11 19:21:10
 * @Link: https://www.luogu.com.cn/problem/P1471
 */


// 重要的是推出方差方程与平方更新方程

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
{int l, r; double s, ss, add;} tr[N * 4];
double a[N];

void pushup(int p)
{
    tr[p].s = tr[lc].s + tr[rc].s;
    tr[p].ss = tr[lc].ss + tr[rc].ss;
}

void pushdown(int p)
{
    if (tr[p].add)
    {
        double k = tr[p].add;
        int llen = tr[lc].r - tr[lc].l + 1;
        int rlen = tr[rc].r - tr[rc].l + 1;
        tr[lc].ss += k * k * llen + 2 * tr[p].add * tr[lc].s;
        tr[rc].ss += k * k * rlen + 2 * tr[p].add * tr[rc].s;
        tr[lc].s += tr[p].add * llen;
        tr[rc].s += tr[p].add * rlen;
        tr[lc].add += tr[p].add;
        tr[rc].add += tr[p].add;
        tr[p].add = 0;
    }
}

void build(int p, int l, int r)
{
    tr[p] = {l, r, 0, 0, 0};
    if (l == r)
    {
        tr[p].s = a[l];
        tr[p].ss = a[l] * a[l];
        return;
    }
    int mid = (l + r) / 2;
    build(lc, l, mid);
    build(rc, mid + 1, r);
    pushup(p);
}

void update(int p, int l, int r, double k)
{
    if (l <= tr[p].l && tr[p].r <= r)
    {
        int len = tr[p].r - tr[p].l + 1;
        tr[p].ss += len * k * k + 2 * k * tr[p].s;
        tr[p].s += len * k;
        tr[p].add += k;
        return;
    }
    pushdown(p);
    int mid = (tr[p].r + tr[p].l) / 2;
    if (l <= mid) update(lc, l, r, k);
    if (r > mid) update(rc, l, r, k);
    pushup(p);
}

double query1(int p, int l, int r)
{
    if (l <= tr[p].l && tr[p].r <= r) return tr[p].s;
    pushdown(p);
    double res = 0; int mid = (tr[p].r + tr[p].l) / 2;
    if (l <= mid) res += query1(lc, l, r);
    if (r > mid) res += query1(rc, l, r);
    return res;
}

double query2(int p, int l, int r)
{
    if (l <= tr[p].l && tr[p].r <= r) return tr[p].ss;
    pushdown(p);
    double res = 0; int mid = (tr[p].r + tr[p].l) / 2;
    if (l <= mid) res += query2(lc, l, r);
    if (r > mid) res += query2(rc, l, r);
    return res;
}

void solve()
{
    int n, q; cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while (q--)
    {
        int op, x, y, k; cin >> op >> x >> y;
        if (op == 1)
        {
            double k; cin >> k;
            update(1, x, y, k);
        }
        else if (op == 2) printf("%.4lf\n", query1(1, x, y) / (y - x + 1));
        else printf("%.4lf\n", query2(1, x, y) / (y - x + 1) - pow(query1(1, x, y) / (y - x + 1), 2));
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    // cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}