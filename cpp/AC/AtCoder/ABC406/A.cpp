#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

void solve()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a > c) cout << "Yes" << endl;
    else if (a == c) 
    {
        if (b >= d) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else cout << "No" << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    // cout.tie(0);
    int T = 1; 
    // cin >> T;
    while (T--) solve();
    return 0;
}