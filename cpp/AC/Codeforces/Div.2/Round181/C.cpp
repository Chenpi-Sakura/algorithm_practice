/** 
 * @Author: Chenpi
 * @Date: 2025-07-22 22:42:16
 * @Link: https://codeforces.com/contest/2125/problem/C
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 5e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

vector<PII> a = {{6, 1}, {10, 1}, {14, 1}, {15, 1}, {21, 1}, {30, -1}, {35, 1}, {42, -1}, {70, -1}, {105, -1}, {210, 1}};

void solve()
{
    int l, r; cin >> l >> r;
    int ans = r - l + 1;
    ans = ans - r / 2 + (l - 1) / 2;
    ans = ans - r / 3 + (l - 1) / 3;
    ans = ans - r / 5 + (l - 1) / 5;
    ans = ans - r / 7 + (l - 1) / 7;
    for (auto i : a) ans = ans + (r / i.first - (l - 1) / i.first) * i.second;
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