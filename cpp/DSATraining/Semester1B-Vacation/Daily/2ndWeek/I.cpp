/** 
 * @Author: Chenpi
 * @Date: 2025-07-25 19:36:07
 * @Link: https://codeforces.com/gym/624417/problem/I
 */
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
    vector<int> a(n + 1), pre(n + 1), suf(n + 2);
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) pre[i] = max(pre[i - 1], a[i] + n - i);
    for (int i = n; i >= 1; i--) suf[i] = max(suf[i + 1], a[i] + i - 1);
    int ans = inf;
    for (int i = 1; i <= n; i++) ans = min(ans, max({a[i], pre[i - 1], suf[i + 1]}));
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