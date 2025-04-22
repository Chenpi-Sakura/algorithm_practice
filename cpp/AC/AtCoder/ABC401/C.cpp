#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e6 + 5;
const int M = 1e9;
const int inf = 0x3f3f3f3f;

int a[N], s[N];

void solve()
{
    int n, k; cin >> n >> k;
    for (int i = 1; i <= k; i++)
    {
        a[i] = 1;
        s[i] = (s[i - 1] + a[i]) % M;
    }
    for (int i = k + 1; i <= n + 1; i++)
    {
        a[i] = (s[i - 1] - s[i - k - 1]) % M;
        s[i] = (s[i - 1] + a[i]) % M;
    }
    if (a[n + 1] < 0) cout << M + a[n + 1] << endl;
    else 
    cout << a[n + 1] << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); //cout.tie(0);
    int t; // cin >> t;
    t = 1;
    while (t--) solve();
    return 0;
}