/** 
 * @Author: Chenpi
 * @Date: 2025-07-25 10:13:12
 * @Link: 
 */
/** 
 * @Author: Chenpi
 * @Date: 2025-07-25 10:13:12
 * @Link: https://codeforces.com/gym/624417/problem/E
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
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int last = a[n - 1], ans = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] < last) last = a[i];
        else
        {
            int k = (a[i] + last - 1) / last;
            ans += k - 1;
            last = a[i] / k;
        }
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