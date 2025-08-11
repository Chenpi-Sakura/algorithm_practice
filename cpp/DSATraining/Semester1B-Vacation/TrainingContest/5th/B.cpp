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
    for (int i = 0; i < s.size() - 2; i++)
    {
        if (s[i] == 'c' && s[i + 1] == 'j' && s[i + 2] == 'b')
        { 
            s.insert(s.begin() + i + 3, ',');
            i += 3;
        }
    }
    cout << s << endl;
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