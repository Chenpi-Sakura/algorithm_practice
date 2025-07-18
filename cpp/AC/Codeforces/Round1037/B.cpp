#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

typedef pair<int, int> PII;
const int N = 1e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

void solve()
{
    int n, k; cin >> n >> k;
    int ans = 0, con = 0, res = 0;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        if (res == 1) {res = 0; continue;}
        if (x == 0) con++;
        else con = 0;
        if (con == k) ans++, con = 0, res = 1;
    }
    cout << ans << endl;
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