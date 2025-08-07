#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f3f3f3f3fLL;

int b[N], s1[N], s2[N], f1[N], f2[N];

void solve()
{
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        s1[i] = s1[i - 1] + b[i];
        f1[i] = f1[i - 1] + (s1[i - 1] + k - 1) / k;
    }
    for (int i = n; i >= 1; i--)
    {
        s2[i] = s2[i + 1] + b[i];
        f2[i] = f2[i + 1] + (s2[i + 1] + k - 1) / k;
    }
    int ans = inf;
    for (int i = 1; i <= n; i++) ans = min(ans, f1[i] + f2[i]);
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