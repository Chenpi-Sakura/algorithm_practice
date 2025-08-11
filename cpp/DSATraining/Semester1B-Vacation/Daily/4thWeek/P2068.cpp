/** 
 * @Author: Chenpi
 * @Date: 2025-08-09 20:20:15
 * @Link: https://www.luogu.com.cn/problem/P2068
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
{int l, r, sum, add;} tr[4 * N];

void pushup(int p)
{
    tr[p].sum = tr[lc].sum + tr[rc].sum;
}

void build(int p, int l, int r)
{
    tr[p] = {l, r, 0, 0};
    if (l == r) return;
    int mid = (l + r) / 2;
    build(lc, l, mid);
    build(rc, mid + 1, r);
}

void update(int p, int i, int k)
{
    if (tr[p].l == tr[p].r)
    {
        tr[p].sum += k;
        return;
    }
    int mid = (tr[p].l + tr[p].r) / 2;
    if (i <= mid) update(lc, i, k);
    else update(rc, i, k);
    pushup(p);
}

int query(int p, int l, int r)
{
    if (l <= tr[p].l && tr[p].r <= r) return tr[p].sum;
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
        char op; int a, b; 
        cin >> op >> a >> b;
        if (op == 'x') update(1, a, b);
        else cout << query(1, a, b) << endl;;
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