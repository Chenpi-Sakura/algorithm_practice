/** 
 * @Author: Chenpi
 * @Date: 2025-08-07 20:31:57
 * @Link: https://www.luogu.com.cn/problem/P3372
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
{int l, r, sum, add;} tr[N * 4];
int w[N];

void pushup(int p)
{// 向上更新
    tr[p].sum = tr[lc].sum + tr[rc].sum;
}

void pushdown(int p)
{
    if (tr[p].add)
    {
        tr[lc].sum += tr[p].add * (tr[lc].r - tr[lc].l + 1);
        tr[rc].sum += tr[p].add * (tr[rc].r - tr[rc].l + 1);
        tr[lc].add += tr[p].add;
        tr[rc].add += tr[p].add;
        tr[p].add = 0;
    }
}

void build(int p, int l, int r)
{
    tr[p] = {l, r, 0, 0};
    if (l == r)
    {
        tr[p].sum = w[l];
        return;
    } 
    int m = (l + r) / 2;
    build(lc, l, m);
    build(rc, m + 1, r);
    pushup(p);
}

void update(int p, int x, int y, int k)
{
    if (x <= tr[p].l && tr[p].r <= y)
    {
        tr[p].sum += (tr[p].r - tr[p].l + 1) * k;
        tr[p].add += k;
        return;
    }
    int m = (tr[p].l + tr[p].r) / 2;
    pushdown(p);
    if (x <= m) update(lc, x, y, k);
    if (y > m) update(rc, x, y, k);
    pushup(p);
}

int query(int p, int x, int y)
{
    if (x <= tr[p].l && tr[p].r <= y) 
    {
        return tr[p].sum;
    }
    int m = (tr[p].l + tr[p].r) / 2;
    pushdown(p);
    int sum = 0;
    if (x <= m) sum += query(lc, x, y);
    if (y > m) sum += query(rc, x, y);
    return sum;
}

void solve()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> w[i];
    build(1, 1, n);
    while (m--)
    {
        int op, x, y, k; cin >> op >> x >> y;
        if (op == 1) {cin >> k, update(1, x, y, k);}
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