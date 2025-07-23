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
    int n, a; cin >> n >> a;
    string s; cin >> s;
    vector<PII> rbs;
    for (int i = 0; i < s.size(); i++)
    {
        if (rbs.empty()) rbs.push_back({s[i] - '0', 1});
        else
        {
            if (rbs.back().first == s[i] - '0') rbs.back().second++;
            else rbs.push_back({s[i] - '0', 1});
        }
    }
    for (int i = 0; i < rbs.size(); i++)
    {
        if ()
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