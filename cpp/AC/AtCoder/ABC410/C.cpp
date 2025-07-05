#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e6 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int a[N];

void solve()
{
    int n, q; cin >> n >> q;
    for (int i = 0; i < n; i++) a[i] = i + 1;
    int x = 0;
    for (int i = 0; i < q; i++)
    {
        int t, p; cin >> t >> p;
        if (t == 1)
        {
            int y; cin >> y;
            a[(x + p - 1) % n] = y;
        }
        else if (t == 2) cout << a[(x + p - 1) % n] << endl;
        else x = (x + p) % n;
    }
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