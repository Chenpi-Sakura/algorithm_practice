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
    int l = 0, r = 0, len = s.size();
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(') l++;
        else r++;
    }
    if (l == r && l < 2) cout << "()" << endl;
    else if (l == r) cout << "There are multiple solutions" << endl;
    else cout << -1 << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); //cout.tie(0);
    int t; cin >> t;
    // t = 1;
    while (t--) solve();
    return 0;
}