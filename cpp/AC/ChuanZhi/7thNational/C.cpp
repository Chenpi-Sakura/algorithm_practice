#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

void solve()
{
    int x; cin >> x;
    int y = 0;
    for (int i = 30; i >= 0; i--)
        if (!(x >> i & 1)) 
            y |= 1 << i;
    if (y == 0) y = -1;
    cout << y << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); //cout.tie(0);
    int t; // cin >> t;
    t = 1;
    while (t--) solve();
    return 0;
}