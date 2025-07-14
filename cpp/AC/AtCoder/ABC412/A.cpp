#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

void solve()
{
    int n, m; cin >> n >> m;
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
        total += a;
    }
    if (total <= m) cout << "Yes" << endl;
    else cout << "No" << endl;
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