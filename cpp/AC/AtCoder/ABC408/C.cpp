#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e6 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int d[N];

void solve()
{
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int l, r; cin >> l >> r;
        d[l]++, d[r + 1]--;
    }
    int ans = inf;
    for (int i = 1; i <= n; i++)
    {
        d[i] = d[i - 1] + d[i];
        ans = min(ans, d[i]);
    }
    // for (int i = 1; i <= n; i++) cout << d[i] << ' ';
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}