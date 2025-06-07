#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 3e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int d[N];

void solve()
{
    int n, l; cin >> n >> l;
    if (l % 3 != 0)
    {
        cout << 0 << endl;
        return;
    }
    int c = 0;
    d[0] = 1;
    for (int i = 1; i < n; i++)
    {
        int x; cin >> x;
        c = (c + x) % l;
        d[c]++;
    }
    int e = l / 3, ans = 0;
    for (int i = 0; i < e; i++)
    {
        ans += d[i] * d[i + e] * d[i + 2 * e];
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    int T = 1;
    //cin >> T;
    while (T--) solve();
    return 0;
}