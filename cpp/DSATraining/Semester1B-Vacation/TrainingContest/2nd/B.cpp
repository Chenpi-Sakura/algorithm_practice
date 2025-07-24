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
    int n; cin >> n;
    double p = 0;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        p += log2(x);
    }
    double x = log2(2024);
    if (p == 0) cout << 0 << endl;
    else if (p < x) cout << 1 << endl;
    else 
    {
        int y = p / x;
        if (y * x < p) cout << y + 1 << endl;
        else cout << y << endl;
    }
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