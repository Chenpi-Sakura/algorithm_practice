/** 
 * @Author: Chenpi
 * @Date: 2025-07-25 17:04:52
 * @Link: https://codeforces.com/gym/624417/problem/G
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
    int n, q; cin >> n >> q;
    for (int i = 1; i < n; i++) cout << i << ' ' << i + 1 << endl;
    int p = n - 1;
    while (q--)
    {
        int d; cin >> d;
        if (d == p) cout << -1 << ' ' << -1 << ' ' << -1 << endl;
        else 
        {
            cout << n << ' ' << p << ' ' << d << endl;
            p = d;
        }
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