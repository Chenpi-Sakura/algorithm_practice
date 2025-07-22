/*
 * @Author: Chenpi
 * @Date: 2025-07-21 09:38:52
 * @Link: https://oj.saikr.com/problem/2360
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 35;
const int M = 998244353;
const int inf = 0x3f3f3f3f;

int d[N][N], a[3][N], w[3][N];

void solve()
{
    int n, c; cin >> n >> c;
    for (int i = 1; i <= c; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            cin >> d[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x; cin >> x;
            a[(i + j) % 3][x]++;
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            for (int k = 1; k <= c; k++)
            {
                w[i][k] += a[i][j] * d[j][k];
            }
        }
    }
    
    int ans = inf;
    for(int i = 1; i <= c; i++)
    {
        for (int j = 1; j <= c; j++)
        {
            if (i == j) continue;
            for (int k = 1; k <= c; k++)
            {
                if (i == k || j == k) continue;
                ans = min(ans, w[0][i] + w[1][j] + w[2][k]);
            }
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
    // cin >> T;
    while (T--) solve();
    return 0;
}