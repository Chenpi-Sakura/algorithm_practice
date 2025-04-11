#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

void solve()
{
    int n; string s, t; cin >> n >> s >> t;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] != t[i]) ans++;
    }
    cout << ans << endl;
}

signed main()
{
    int t; t = 1;
    while (t--) solve();
    return 0;
}