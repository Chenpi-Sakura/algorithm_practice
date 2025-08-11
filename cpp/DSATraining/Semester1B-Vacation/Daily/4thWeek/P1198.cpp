/** 
 * @Author: Chenpi
 * @Date: 2025-08-09 19:23:06
 * @Link: https://www.luogu.com.cn/record/229908095
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

#define lc p * 2
#define rc p * 2 + 1

typedef pair<int, int> PII;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f3f3f3f3fLL;

struct Node 
{int l, r, m;} tr[N * 4];
int MOD, t;

void pushup(int p)
{
    tr[p].m = max(tr[lc].m, tr[rc].m);
}

void build(int p, int l, int r)
{
    tr[p] = {l, r, 0};
    if (l == r) return;
    int mid = (l + r) / 2;
    build(lc, l, mid);
    build(rc, mid + 1, r);
}

void update(int p, int i, int k)
{
    if (tr[p].l == tr[p].r)
    {
        tr[p].m = ((k + t) % MOD + MOD) % MOD;
        return;
    }
    int mid = (tr[p].l + tr[p].r) / 2;
    if (i <= mid) update(lc, i, k);
    else update(rc, i, k);
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

void solve()
{
    int q; cin >> q >> MOD;
    build(1, 1, N);
    int siz = 0;
    while (q--)
    {
        char op; int n;
        cin >> op >> n;
        if (op == 'Q') 
        {
            t = query(1, siz - n + 1, siz);
            cout << t << endl;
        }
        else
        {
            update(1, siz + 1, n);
            siz++;
        } 
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