#include <bits/stdc++.h>
using namespace std;
#define int long long


signed main()
{
    int t; cin >> t;
    while (t--)
    {
        int a, p, l, r; cin >> a >> p >> l >> r;
        int ans = l + (a - l % p);
        if (ans >= l && ans <= r) cout << "Yes" << ' ' << ans << endl;
        else cout << "No" << endl;
    }
    return 0;
}