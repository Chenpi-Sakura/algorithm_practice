#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 3e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int a[N];

void solve()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<PII> s;
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] < a[i + 1])
        {
            if (s.empty() || s.back().first == 1) s.push_back({0, 1});
            else s.back().second++;
        }
        else
        {
            if (s.empty() || s.back().first == 0) s.push_back({1, 1});
            else s.back().second++;
        }
    }
    int ans = 0;
    for (int i = 1; i < s.size() - 1; i++)
    {
        if (s[i].first == 1) ans += s[i - 1].second * s[i + 1].second;
    }
    cout << ans << endl;
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