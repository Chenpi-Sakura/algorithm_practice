/** 
 * @Author: Chenpi
 * @Date: 2025-07-22 22:40:37
 * @Link: 
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

void solve()
{
    int a, b, k; cin >> a >> b >> k;
    int c = gcd(a, b);
    if (a / c > k || b / c > k) cout << 2 << endl;
    else cout << 1 << endl;
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