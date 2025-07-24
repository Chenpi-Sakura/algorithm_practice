/** 
 * @Author: Chenpi
 * @Date: 2025-07-23 14:17:49
 * @Link: https://codeforces.com/gym/624417/problem/A
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
    int n, c; cin >> n >> c;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<PII> others;
    for (int i = 1; i < n; i++) others.push_back({(i + 1) * c - a[i], a[i]});
    sort(others.begin(), others.end());
    int cur = a[0];
    for (auto [x, p] : others)
    {
        if (cur < x) {cout << "No" << endl; return;}
        cur += p;
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