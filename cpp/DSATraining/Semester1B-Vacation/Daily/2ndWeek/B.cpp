/** 
 * @Author: Chenpi
 * @Date: 2025-07-23 16:09:12
 * @Link: https://codeforces.com/gym/624417/problem/B
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
    vector<int> a(n), vis(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a. begin(), a.end());
    int ans = 0, x = 0, l = 0, r = n - 1;
    while (l < r)
    {
        if (x + a[l] > a[r])
        {
            ans += (a[r] - x + 1);
            a[l] -= (a[r] - x);
            vis[r] = 1;
            x = 0; r--;
        }
        else if (x + a[l] == a[r])
        {
            ans += a[l] + 1;
            vis[l] = 1;
            vis[r] = 1;
            x = 0; r--; l++;
        }
        else
        {
            ans += a[l];
            x += a[l];
            vis[l] = 1;
            l++;
        }
    }
    if (!vis[l])
    {
        if (x > a[l] || a[l] == 1) ans++;
        else
        {
            ans += ((a[l] - x + 1) / 2) + 1;
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