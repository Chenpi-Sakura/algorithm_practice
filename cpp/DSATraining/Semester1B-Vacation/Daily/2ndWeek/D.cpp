/** 
 * @Author: Chenpi
 * @Date: 2025-07-25 09:19:13
 * @Link: https://codeforces.com/gym/624417/problem/D
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
    int n, m; cin >> n >> m;
    vector<int> a(n), b(m), c;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < m; j++) cin >> b[j];
    sort(b.rbegin(), b.rend());
    int p = 0;
    for (int i = 0; i < n; i++)
    {
        while (p < m && b[p] >= a[i]) {c.push_back(b[p]); p++;}
        c.push_back(a[i]);
    }
    while (p < m) {c.push_back(b[p]); p++;}
    for (auto x : c) cout << x << ' ';
    cout << endl;
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