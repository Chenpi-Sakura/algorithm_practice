/** 
 * @Author: Chenpi
 * @Date: 2025-07-30 19:00:32
 * @Link: https://codeforces.com/gym/626001/problem/H
 */
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
    int n; char c; cin >> n >> c;
    string s; cin >> s;
    s += s;
    int ans = 0;
    for (int i = 0; i < 2 * n; i++)
    {
        if (s[i] == c)
        {
            int cur = 0;
            while (i < 2 * n && s[i] != 'g')
            {
                i++;
                cur++;
            }
            ans = max(ans, cur);
            if (i > n) break;
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
    cin >> T;
    while (T--) solve();
    return 0;
}