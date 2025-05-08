/*
    运用差分的知识，实现了一个支持区域查询和区域修改的树状数组
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int a[N], tree1[N], tree2[N];
int n, f;

int lowbit(int x) {return x & (-x);}

void add(int x, int k)
{
    int i = x - 1;
    while (x <= n)
    {
        tree1[x] += k;
        tree2[x] += k * i;
        x += lowbit(x);
    }
}

void range_add(int l, int r, int k)
{
    add(l, k);
    add(r + 1, -k);
}

int range_query(int x)
{
    int s = 0;
    int r = x;
    while (x)
    {
        s += r * tree1[x] - tree2[x];
        x -= lowbit(x);
    }
    return s;
}

int query(int l, int r)
{
    return range_query(r) - range_query(l - 1);
}

void solve()
{
    cin >> n >> f;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        add(i, a[i] - a[i - 1]);
    }
    while (f--)
    {
        int t; cin >> t;
        if (t == 1)
        {
            int l, r, k; cin >> l >> r >> k;
            range_add(l, r, k);
        }
        else if (t == 2)
        {
            int k; cin >> k;
            range_add(1, 1, k);
        }
        else if (t == 3)
        {
            int k; cin >> k;
            range_add(1, 1, -k);
        }
        else if (t == 4)
        {
            int l, r; cin >> l >> r;
            cout << query(l, r) << endl;
        }
        else 
        {
            cout << query(1, 1) << endl;
        }
    }
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