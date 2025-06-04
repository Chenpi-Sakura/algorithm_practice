#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

void solve()
{
    string s; cin >> s;
    int len = s.size();
    int t = 0, ans = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        int current = s[i] - '0';
        if (t > current) current = current - t + 10;
        else current -= t;
        ans += current + 1;
        t = (t + current) % 10;
    }
    cout << ans << endl;
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