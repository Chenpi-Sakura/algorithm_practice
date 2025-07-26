/** 
 * @Author: Chenpi
 * @Date: 2025-07-25 14:03:43
 * @Link: https://codeforces.com/gym/624417/problem/H
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
    int a = 0, b = inf;
    for (int i = 0; i < n; i++) 
    {
        int x; cin >> x;
        a = max(a, x);
        b = min(b, x);
    }
    int ans = 0;
    while (a != b)
    {
        a = (b + a) / 2;
        ans++;
    }
    cout << ans << endl;
    if (ans <= n)
    {
        for (int i = 0; i < ans; i++) cout << b << ' ';
        cout << endl;
    }
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