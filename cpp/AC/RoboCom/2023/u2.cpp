/** 
 * @Author: Chenpi
 * @Date: 2025-08-13 20:01:56
 * @Link: https://pintia.cn/problem-sets/1680597991209951232/exam/problems/type/7?problemSetProblemId=1680598077168017409
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 5e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f3f3f3f3fLL;

unordered_map<string, string> mp;
    
void solve()
{
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s, g; cin >> s >> g;
        mp[s] = g;
    }
    for (int i = 0; i < m; i++)
    {
        string s, ans = ""; cin >> s;
        if (mp.count(s))
        {
            cout << mp[s] << endl;
            continue;
        }
        for (int i = 0; i < s.size(); i++)
        {
            if (mp.count(s.substr(0, i)) && mp.count(s.substr(i)))
            {
                if (ans != "") {ans = ""; break;}
                else ans = mp[s.substr(0, i)] + mp[s.substr(i)];
            }
        }
        if (ans != "") cout << ans << endl;
        else cout << "D" << endl;
    }
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