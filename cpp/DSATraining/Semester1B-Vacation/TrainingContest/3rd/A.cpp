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
    int n, q; cin >> n >> q;
    int odd = 0, eve = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
        ans += a;
        if (a % 2 == 0) eve++;
        else odd++;
    }
    while (q--)
    {
        int op, x; cin >> op >> x;
        if (op == 0)
        {
            ans += x * eve;
            if (x % 2 == 1)
            {
                odd += eve;
                eve = 0;
            }
        } 
        else
        {
            ans += x * odd;
            if (x % 2 == 1)
            {
                eve += odd;
                odd = 0;
            }
        } 
        cout << ans << endl;
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