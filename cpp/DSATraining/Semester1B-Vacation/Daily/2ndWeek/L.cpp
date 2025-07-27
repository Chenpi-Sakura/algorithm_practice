/** 
 * @Author: Chenpi
 * @Date: 2025-07-26 19:22:32
 * @Link: https://codeforces.com/gym/624417/problem/L
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

string s;
int pre[N][30];

void solve()
{
    int l, r; cin >> l >> r;
    if (l == r) {cout << "Yes" << endl; return;}
    if (s[l - 1] != s[r - 1]) {cout << "Yes" << endl; return;}
    int x = 0;
    for (int i = 0; i < 26; i++) if (pre[r][i] - pre[l - 1][i] > 0) x++;
    if (x >= 3) cout << "Yes" << endl;
    else cout << "No" << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    int T = 1;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < 26; j++)
        {
            pre[i + 1][j] = pre[i][j];
        }
        pre[i + 1][s[i] - 'a']++;
    }
    cin >> T;
    while (T--) solve();
    return 0;
}