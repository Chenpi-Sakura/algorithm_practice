#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 5e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

void solve()
{
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> cnt1(n);
    int ans = 0;
    for (int k = 0; k <= 27; k++)
    {
        int cnt[2][2] = {{0, 0}, {0, 0}};
        for (int i = 0; i < n; i++)
        {
            cnt[(a[i] >> k) & 1][cnt1[i]]++;
            if ((a[i] >> k) & 1) cnt1[i] ^= 1;
        }
        int x = cnt[0][0] * cnt[1][0] + cnt[0][1] * cnt[1][1];
        ans += x * (1LL << k);
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
    while (T--) solve();
    return 0;
}