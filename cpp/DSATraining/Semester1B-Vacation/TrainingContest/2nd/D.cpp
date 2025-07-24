#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

void solve()
{
    int n; cin >> n;
    vector<int> a(n);
    vector<PII> b;
    int isSame = 0, ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (b.empty()) b.push_back({a[i], a[i]});
        else if (a[i] == b.back().second) continue;
        else if (a[i] < b.back().second && b.back().second <= b.back().first) b.back().second = a[i];
        else if (a[i] > b.back().second && b.back().second >= b.back().first) b.back().second = a[i];
        else b.push_back({a[i], a[i]});
    }
    for (auto x : b)
    {
        
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