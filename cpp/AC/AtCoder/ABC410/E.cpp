#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 3e3 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int dp[N];
int a[N], b[N];

void solve()
{
    int n, h, m; cin >> n >> h >> m;
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];
    memset(dp, -1, sizeof(dp));
    for (int i = 0; i < n; i++)
    {
        
    }
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
