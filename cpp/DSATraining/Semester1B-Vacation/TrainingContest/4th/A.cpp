#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 5e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

unordered_map<int, int> mp;

void solve()
{
    int n; cin >> n;
    int maxX = 0, minX = inf;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        mp[x]++;
        maxX = max(maxX, x);
        minX = min(minX, x);
    }
    int ans = 0;
    for (int i = minX * 2; i <= maxX * 2; i++)
    {
        int res = 0;
        for (int j = minX; j <= i / 2; j++)
        {
            if (j != i - j) res += min(mp[j], mp[i - j]);
            else res += mp[j] / 2;
            
        }
        ans = max(ans, res);
    }
    cout << ans * 2 << endl;
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