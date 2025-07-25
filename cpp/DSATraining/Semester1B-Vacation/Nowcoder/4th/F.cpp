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
    int n, k, c; cin >> n >> k >> c;
    vector<int> a(n + 1), w(n);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        w[i - 1] = a[i] - c * (i - 1);
    }
    sort(w.begin(), w.end(), greater<int>());
    int ans = 0;
    for (int i = 0; i < k; i++) ans += w[i] + i * c;
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