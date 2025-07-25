/** 
 * @Author: Chenpi
 * @Date: 2025-07-25 14:38:11
 * @Link: https://codeforces.com/gym/624417/problem/K
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 5e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

int lcm(int a, int b)
{
    return a / gcd(a, b) * b;
}

void solve()
{
    int n; cin >> n;
    int ans = n, clcm = 1;
    for (int i = 1; clcm <= n; i++)
    {
        clcm = lcm(clcm, i);
        ans = (ans + n / clcm) % M;
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