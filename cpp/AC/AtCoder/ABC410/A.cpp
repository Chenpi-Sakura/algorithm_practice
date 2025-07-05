#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int a[105];

void solve()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int k; cin >> k;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (k <= a[i]) ans++;
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