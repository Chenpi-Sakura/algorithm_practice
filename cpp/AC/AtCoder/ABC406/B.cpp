#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

typedef pair<int, int> PII;
const int N = 1e7 + 5;
const int M = 1e9 + 7;

void solve()
{
    int n, k; cin >> n >> k;
    int limit = 1;
    for (int i = 0; i < k; i++) limit *= 10;
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
        if (ans >= (limit + a - 1) / a) ans = 1;
        else ans *= a;
    }

    cout << ans << endl;
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