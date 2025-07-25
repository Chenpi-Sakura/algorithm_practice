/** 
 * @Author: Chenpi
 * @Date: 2025-07-23 16:24:25
 * @Link: https://codeforces.com/gym/624417/problem/C
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
    int n, k; cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int p = n - 1;
    for (int i = 0; i < min(n, k); i++)
    {
        int shift = a[p];
        if (shift < 1 || shift > n) {cout << "No" << endl; return;}
        else p = (p - shift + n) % n;
    }
    cout << "Yes" << endl;
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