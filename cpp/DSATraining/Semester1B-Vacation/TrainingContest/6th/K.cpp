#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 5e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f3f3f3f3fLL;

void solve()
{
    int sx, sy, tx, ty; cin >> sx >> sy >> tx >> ty;
    queue<pair<PII, int>> q;
    q.push({{sx, sy}, 0});
    int ans = inf;
    while (q.size())
    {
        auto [p, c] = q.front(); q.pop();
        auto [x, y] = p;
        if (x == tx && y == ty)
        {
            ans = min(ans, c);
            continue;
        }
        if (x + max(x, y) <= tx) q.push({{x + max(x, y), y}, c + 1});
        if (y + max(x, y) <= ty) q.push({{x, y + max(x, y)}, c + 1});
    }
    if (ans >= inf) cout << -1;
    else cout << ans << endl;
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