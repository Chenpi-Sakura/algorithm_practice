#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 5e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int n;
PII a[N];
int b[N], c[N];

int lowbit(int x) {return x & (-x);}

void add(int x, int k)
{
    while (x <= n)
    {
        c[x] += k;
        x += lowbit(x);
    }
}

int query(int x)
{
    int s = 0;
    while (x)
    {
        s += c[x];
        x -= lowbit(x);
    }
    return s;
}

bool cmp(PII x, PII y)
{
    if (x.second == y.second) return x.first < y.first;
    return x.second < y.second;
}

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++) 
    {
        int t; cin >> t;
        a[i] = {i, t};
    }
    sort(a + 1, a + n + 1, cmp);
    for (int i = 1; i <= n; i++)
        b[a[i].first] = i; // 离散化

    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        add(b[i], 1);
        ans += i - query(b[i]);
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