#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 5e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int tree[N], ranks[N], n, ans;
struct point{int idx, val;}a[N];

bool cmp(point a, point b)
{
    if (a.val == b.val) return a.idx < b.idx;
    return a.val < b.val;
}

int lowbit(int x) {return x & -x;}

void insert(int x, int k)
{
    while (x <= n)
    {
        tree[x] += k;
        x += lowbit(x);
    }
}

int query(int x)
{
    int res = 0;
    while (x)
    {
        res += tree[x];
        x -= lowbit(x);
    }
    return res;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].val;
        a[i].idx = i;
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++) ranks[a[i].idx] = i;
    for (int i = 1; i <= n; i++)
    {
        insert(ranks[i], 1);
        ans += i - query(ranks[i]);
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); //cout.tie(0);
    int t; // cin >> t;
    t = 1;
    while (t--) solve();
    return 0;
}