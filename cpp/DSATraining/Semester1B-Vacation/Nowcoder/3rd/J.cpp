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
    int x, y; cin >> x >> y;
    if ((x + y) % 2 == 1) {cout << -1 << endl; return;}
    if (x > y) swap(x, y);
    int ans = 1;
    set<PII> s;
    while (1)
    {
        if (x == y) {cout << ans << endl; return;}
        if (s.find({x, y}) != s.end()) {cout << -1 << endl; return;}
        s.insert({x, y});
        y -= x; x += x; 
        if (x > y) swap(x, y);
        ans++;
    }
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