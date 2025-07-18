#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

void solve()
{
    int n; cin >> n;
    vector<int> p(n), s(n);
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i];
        if (i > 0 && (p[i - 1] % p[i] != 0 || p[i] > p[i - 1]))
        {
            ans = 0;
        }
    }
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = n - 1; i >= 0; i--)
    {
        if (i < n - 1 && (s[i + 1] % s[i] != 0 || s[i] > s[i + 1]))
        {
            ans = 0;
        }
    }
    if (s[0] == 1 && p[0] % s[1] == 0) ans = 0;
    if (p[n - 1] == 1 && s[n - 1] % p[n - 2] == 0) ans = 0;
    if (p[0] % s[0] != 0 || s[n - 1] % p[n - 1] != 0) ans = 0;
    if (ans) cout << "YES" << endl;
    else cout << "NO" << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}