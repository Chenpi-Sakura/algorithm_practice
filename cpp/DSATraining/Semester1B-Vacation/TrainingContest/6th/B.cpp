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
    int n; cin >> n;
    int minX = inf, maxX = 0;
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
        minX = min(a[i], minX);
        maxX = max(a[i], maxX);
    }
    cout << (maxX + minX) / 2 << endl;;
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