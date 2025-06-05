#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int ps[N];

void solve()
{
    string s; cin >> s;
    int len = s.size();
    for (int i = 1; i <= len; i++)
    {
        if (s[i - 1] == '(') ps[i] = ps[i - 1] + 1;
        else ps[i] = ps[i - 1] - 1;
    }

    int ans = 0;

    if (ps[len] < 0)
    {
        for (int i = 1; i <= len; i++)
        {
            if (s[i] == ')' && ps[i] - 1 >= 0) ans++;
        }
    }
    else
    {
        for (int i = 1; i <= len; i++)
        {
            if (s[i] == '(' && ps[i] + 1 >= 0) ans++;
        }
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