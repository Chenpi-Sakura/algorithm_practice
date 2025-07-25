/** 
 * @Author: Chenpi
 * @Date: 2025-07-23 19:55:37
 * @Link: https://codeforces.com/gym/624051/problem/D
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

void solve()
{
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int u = inf, l = 0;
    for (int i = 0; i < n - 1; i++) 
    {
        if (a[i + 1] > a[i]) u = min(u, (a[i + 1] + a[i]) / 2);
        else if (a[i + 1] < a[i]) l = max(l, (a[i] + a[i + 1] + 1) / 2);
    }
    if (l <= u) cout << l << endl;
    else cout << -1 << endl;
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