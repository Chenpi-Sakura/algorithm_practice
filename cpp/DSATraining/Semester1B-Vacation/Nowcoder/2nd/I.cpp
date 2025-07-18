#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

typedef pair<int, int> PII;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

void solve()
{
    int x, y; cin >> x >> y;
    if (x == 1 || y == 1) cout << -1 << endl;
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