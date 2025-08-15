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
    string s; cin >> s;
    if (s[0] == s[2])
    {
        cout << "No" << endl;
    }
    else
    {
        if (s[1] == '+' || s[1] == '*')
        {
            cout << "Yes" << endl;
        }
        else if (s[0] == '0') cout << "Yes" << endl;
        else
        {
            cout << "No" << endl;
        }
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