#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e6 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int n, k;
string s;
int p0[N], p1[N];

bool check(int L)
{
    if (L == 0) return true;

    int d = max(0LL, k - (n - L));
    int u = k;

    for (int i = 0; i + L <= n; i++)
    {
        int j = i + L;
        int o = p1[j] - p1[i];
        if (o >= d && o <= u) return true;
    }

    for (int i = 0; i + L <= n; i++)
    {
        int j = i + L;
        int z = p0[j] - p0[i];
        if (z >= d && z <= u) return true;
    }
    return false;
}

void solve()
{
    cin >> n >> k >> s;
    for (int i = 0; i < n; i++)
    {
        p0[i + 1] = p0[i] + (s[i] == '0');
        p1[i + 1] = p1[i] + (s[i] == '1');
    }

    int l = 0, r = n;

    while (l < r)
    {
        int mid = (l + r + 1) / 2;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    // t = 1;
    while (t--) solve();
    return 0;
}