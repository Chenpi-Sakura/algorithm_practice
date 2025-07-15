#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

void solve()
{
    int n, q; cin >> n >> q;
    int x = (n - 1) / 2 + (n - 1) % 2;
    vector<int> a; a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    while (q--)
    {
        int p, v; cin >> p >> v;
        a[p - 1] += v;
        int ans = 0;
        vector<int> b = {a.begin(), a.end()};
        sort(b.begin(), b.end());
        int l = 0, r = n;
        for (int i = 0; i < b.size(); i++)
        {

            int j = i;
            while (j + 1 < b.size() && b[j] == b[j + 1]) j++;
            if (b.size() - j - 1 >= x) ans += j - i + 1;
            // cout << b[j] << ' ' << ans << endl;
            i = j;
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