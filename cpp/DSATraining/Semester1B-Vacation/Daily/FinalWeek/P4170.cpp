/** 
 * @Author: Chenpi
 * @Date: 2025-08-11 20:43:17
 * @Link: https://www.luogu.com.cn/problem/P4170
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 55;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f3f3f3f3fLL;

int f[N][N];

void solve()
{
    string s; cin >> s;
    int n = s.size();
    s = " " + s;
    for (int i = n; i > 0; i--) for (int j = i; j <= n; j++)
    {
        if (i == j) f[i][j] = 1;
        else if (s[i] == s[j]) f[i][j] = f[i][j - 1];
        else
        {
            f[i][j] = n;
            for (int k = i; k < j; ++k)
            {
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j]);
            }
        }
    }
    cout << f[1][n] << endl;
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