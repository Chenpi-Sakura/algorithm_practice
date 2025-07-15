#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

typedef pair<int, int> PII;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

void solve()
{
    int a, b; cin >> a >> b;
    if (a < b) swap(a, b);
    if (a == 2 && b == 1) {cout << 1 << endl; return;}
    int x = a * a - b * b;
    int ans = x / 2 - 1;
    if (x % 4 == 0) ans += (x - 1) / 4 - 1;
    else ans += x / 4 - 1;
    cout << ans + 1 << endl;
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