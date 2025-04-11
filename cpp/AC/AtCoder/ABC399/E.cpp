#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

unordered_map<char, char> amap;
map<pair<char, char>, bool> bmap;
//unordered_map<char,vector<char>> ammp;

void solve()
{
    int n; cin >> n;
    string s, t; cin >> s >> t;
    bool flag = false; int ans = 0;
    for (int i = 0; i < n; i++) 
    {
        if (amap.find(s[i]) != amap.end() && amap[s[i]] != t[i]) flag = true;
        amap[s[i]] = t[i];
        if (s[i] != t[i] && bmap[{s[i], t[i]}] == false) 
        {
            ans++;
            bmap[{s[i], t[i]}] = true;
        }
        //ammp[t[i]].push_back(s[i]);
    }
    if (flag) cout << -1 << endl;
    else cout << ans << endl;
}

signed main()
{
    int t; t = 1;
    while (t--) solve();
    return 0;
}