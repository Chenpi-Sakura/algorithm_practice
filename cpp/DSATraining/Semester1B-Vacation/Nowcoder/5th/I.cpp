/**
 * @Author: Chenpi
 * @Date: 2025-08-01 14:28:37
 * @Link:https://ac.nowcoder.com/acm/contest/108303/L
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
    int s = (1 + n) * n / 2;
    int ans = n;
    // 可以观察到长边一定是大于 n 的
    while(s % ans != 0) ans++;
    cout << (ans + s / ans) * 2 << endl; 
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}