#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

void solve()
{   
    int n; cin >> n;
    bool isLog = false;
    int ans = 0;
    while (n--)
    {
        string s; cin >> s;
        if (s == "login") isLog = true;
        else if (s == "logout") isLog = false;
        else if (s == "public") continue;
        else if (!isLog) ans++;
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); //cout.tie(0);
    int t; // cin >> t;
    t = 1;
    while (t--) solve();
    return 0;
}