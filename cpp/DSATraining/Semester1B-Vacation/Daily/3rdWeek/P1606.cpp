/** 
 * @Author: Chenpi
 * @Date: 2025-07-29 11:03:18
 * @Link: https://www.luogu.com.cn/problem/P1606
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 35;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int n, m;
int g[N][N], ways[N][N], vis[N * N];
PII dis[N][N];
vector<int> adj[N * N];

int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {1, -1, 2, -2, 2, -2, 1, -1};


// 二维坐标转化为一维坐标
int point(int r, int c)
{
    return r * n + c;
}

void solve()
{
    cin >> n >> m;
    int sx, sy, ex, ey;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> g[i][j];
            if (g[i][j] == 3) sx = i, sy = j;
            if (g[i][j] == 4) ex = i, ey = j;
        }
    }

    int s = point(sx, sy), e = point(ex, ey);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (g[i][j] == 1 || g[i][j] == 2) continue;
            int u = point(i, j);

            queue<PII> q; q.push({i, j});
            vis[u] = 1;

            while (q.size())
            {
                auto [x, y] = q.front(); q.pop();

                for (int i = 0; i < 8; i++)
                {
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx < 0 || nx >= n || ny < 0 || ny >= m || g[nx][ny] == 2) continue;
                    int v = point(nx, ny);
                    if (vis[v]) continue;
                    vis[v] = 1;
                    if (g[nx][ny] == 1) q.push({nx, ny});
                    else 
                    {
                        
                    }
                }
            }
        }
    }


    dis[sx][sy] = {0, 0};
    ways[sx][sy] = 1;
    priority_queue<pair<PII, PII>, vector<pair<PII, PII>>, greater<pair<PII, PII>>> pq;
    pq.push({{0, 0}, {sx, sy}});

    while (pq.size())
    {
        auto t = pq.top(); pq.pop();
        PII d = t.first;
        auto [x, y] = t.second;
        if (d > dis[x][y]) continue;

        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || g[nx][ny] == 2) continue;

            int cost = (g[nx][ny] == 0);
            PII ndis = {d.first + cost, d.second + 1};

            if (ndis < dis[nx][ny])
            {
                dis[nx][ny] = ndis;
                ways[nx][ny] = ways[x][y];
                pq.push({dis[nx][ny], {nx, ny}});
            }
            else if (ndis == dis[nx][ny])
            {
                ways[nx][ny] += ways[x][y];
            }
        }   
    }
    if (dis[ex][ey].first == inf) cout << -1 << endl;
    else 
    {
        cout << dis[ex][ey].first << endl;
        cout << ways[ex][ey] << endl;
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
