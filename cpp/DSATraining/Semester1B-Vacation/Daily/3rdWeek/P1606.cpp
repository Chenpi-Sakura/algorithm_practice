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
int g[N][N], ways[N * N], dis[N * N];
vector<PII> adj[N * N];

int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[] = {1, -1, 2, -2, 2, -2, 1, -1};


// 二维坐标转化为一维坐标
int point(int r, int c)
{
    return r * m + c;
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

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (g[i][j] == 1 || g[i][j] == 2) continue;

            queue<PII> q; q.push({i, j});
            vector<int> vis(n * m);

            int u = point(i, j);
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
                    else adj[u].push_back({v, (g[nx][ny] == 0)});
                }
            }
        }
    }

    for (int i = 0; i < n * m; i++) dis[i] = inf;
    priority_queue<PII> pq;
    vector<int> vis(n * m);
    dis[s] = 0;
    ways[s] = 1;
    pq.push({0 , s});

    while (pq.size())
    {
        int u = pq.top().second; pq.pop();
        if (vis[u]) continue;
        vis[u] = 1;

        for (auto [v, w] : adj[u])
        {
            if (dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                ways[v] = ways[u];
                pq.push({-dis[v], v});
            }
            else if (dis[u] + w == dis[v]) ways[v] += ways[u];
        }
    }

    if (dis[e] == inf) cout << -1 << endl;
    else 
    {
        cout << dis[e] << endl;
        cout << ways[e] << endl;
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
