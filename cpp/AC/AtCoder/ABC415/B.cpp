#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 1e3 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

void solve()
{
    vector<PII> ans;
    string s; cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '#')
        {
            int x = i;
            i++;
            while (s[i] != '#') i++;
            ans.push_back({x + 1, i + 1});
        }
    }
    for (auto x : ans) cout << x.first << ',' << x.second << endl;
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