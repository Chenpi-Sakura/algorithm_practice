/** 
 * @Author: Chenpi
 * @Date: 2025-07-28 18:54:23
 * @Link: https://www.luogu.com.cn/problem/P2895
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 3e2 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int dis[N][N], tim[N][N];
int ud[4] = {1, -1, 0, 0}, lr[4] = {0, 0, 1, -1};

void solve()
{
    int n; cin >> n;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            {dis[i][j] = inf; tim[i][j] = inf;}
    for (int i = 0; i < n; i++)
    {
        int x, y, t; cin >> x >> y >> t;
        tim[x][y] = min(tim[x][y], t);
        for (int i = 0; i < 4; i++)
            if (x + lr[i] >= 0 && y + ud[i] >= 0)
                tim[x + lr[i]][y + ud[i]] = min(tim[x + lr[i]][y + ud[i]], t);
    }
    queue<PII> q;
    q.push({0, 0}); dis[0][0] = 0;
    int ans = -1;
    if (tim[0][0] == 0) {cout << ans << endl; return;}
    while (q.size())
    {
        auto [x, y] = q.front(); q.pop();
        if (tim[x][y] == inf) {ans = dis[x][y]; break;}
        for (int i = 0; i < 4; i++)
        {
            if (x + lr[i] >= 0 && y + ud[i] >= 0 && dis[x][y] + 1 < dis[x + lr[i]][y + ud[i]])
            {
                if (dis[x][y] + 1 < tim[x + lr[i]][y + ud[i]])
                {
                    dis[x + lr[i]][y + ud[i]] = dis[x][y] + 1;
                    q.push({x + lr[i], y + ud[i]});
                }
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