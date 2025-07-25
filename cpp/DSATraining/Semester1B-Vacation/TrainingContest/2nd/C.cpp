/** 
 * @Author: Chenpi
 * @Date: 2025-07-23 19:37:11
 * @Link: https://codeforces.com/gym/624051/problem/C
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
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        ans = max(x, ans);
    }
    cout << ans << endl;
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