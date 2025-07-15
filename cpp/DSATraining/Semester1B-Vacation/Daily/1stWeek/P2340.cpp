#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 4e5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int dp[2*N + 5];

void solve()
{
    int n; cin >> n;
    fill(dp, dp + 2 * N + 5, -inf);
    dp[N] = 0;

    for (int i = 0; i < n; i++)
    {
        int s, f; cin >> s >> f;
        if (s >= 0)
        {
            for (int p = N * 2 - s; p >= 0; p--)
            {
                if (dp[p] != -inf)
                {
                    dp[p + s] = max(dp[p + s], dp[p] + f);
                }
            }
        }
        else
        {
            for (int p = -s; p <= N * 2; p++)
            {
                if (dp[p] != -inf)
                {
                    dp[p + s] = max(dp[p + s], dp[p] + f);
                }
            }
        }
    }
    
    int ans = 0;
    for (int s = 0; s <= N; s++)
    {
        int f = dp[s + N];
        if (f >= 0) ans = max(ans, f + s);
    }

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