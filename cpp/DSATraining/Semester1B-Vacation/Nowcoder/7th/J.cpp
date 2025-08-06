#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 5e5 + 5;
const int M = 998244353;
const int inf = 0x3f3f3f3f;

int qpow(int a, int b)
{
    int cur = 1, res = 1;
    while (b > 0)
    {
        cur = (cur * a) % M;
        if (b & 1) res = res * cur % M;
        b = b >> 1;
    }
    return res;
}

int gcd(int a, int b)
{
    if (b == 0) return a;
    return gcd(b, a % b);
}

void solve()
{
    int a, b, c, d; cin >> a >> b >> c >> d;
    int x = qpow(a % M, b), y = qpow(c % M, d);
    cout << gcd(x, y) << endl;
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