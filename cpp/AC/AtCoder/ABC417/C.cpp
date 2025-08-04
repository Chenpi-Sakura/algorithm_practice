#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 1e6 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int p[N], d[N];

void solve()
{
    int n; cin >> n;
    int m = 0;
    for (int i = 1; i <= n; i++)
    {
        int a; cin >> a;
        p[a + i]++;
        if (i - a >= 0) d[i - a]++;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans += p[i] * d[i];
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}