/** 
 * @Author: Chenpi
 * @Date: 2025-07-30 21:07:49
 * @Link: https://codeforces.com/gym/626001/problem/C
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
    vector<int> a(n + 1);
    vector<int> c[n + 1];
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        c[a[i]].push_back(i);
    }
    if (c[a[1]].size() < k || c[a[n]].size() < k)
    {
        cout << "NO" << endl;
        return;
    }
    int x = c[a[1]][k - 1], y = c[a[n]][c[a[n]].size() - k];
    if (a[1] == a[n] && c[a[1]].size() >= k) cout << "YES" << endl;
    else if (y > x) cout << "YES" << endl;
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