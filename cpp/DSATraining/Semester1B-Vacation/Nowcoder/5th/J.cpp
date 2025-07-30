// #include <bits/stdc++.h>
// using namespace std;
// #define int long long
// #define endl "\n"

// typedef pair<int, int> PII;
// const int N = 5e5 + 5;
// const int M = 1e9 + 7;
// const int inf = 0x3f3f3f3f;

// int dx[] = {1, -1, 0, 0};
// int dy[] = {0, 0, 1, -1};

// void solve()
// {
//     int n, m; cin >> n >> m;
//     vector<vector<int>> g(n, vector<int>(m)), dis(n, vector<int>(m));
//     queue<PII> q;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < m; j++)
//         {
//             cin >> g[i][j];
//             if (g[i][j] == 1) 
//             {
//                 q.push({i, j});
//                 dis[i][j] = 0;
//             }
//         }
//     }

//     int maxT = 0;
//     vector<PII> p;

//     while (q.size())
//     {
//         auto [x, y] = q.front(); q.pop();
//         for (int i = 0; i < 4; i++)
//         {
//             int cx = x + dx[i], cy = y + dy[i];
//             if (cx >= 0 && cx < n && cy >= y && cy < m)
//             {
//                 if (dis[cx][cy]) continue;
//                 else 
//                 {
//                     dis[cx][cy] = dis[x][y] + 1;
//                     if (dis[cx][cy] > maxT)
//                     {
//                         p.clear();
//                         p.push_back({cx, cy});
//                     }
//                     else if (dis[cy][cx] == maxT) p.push_back({cx, cy});
//                     q.push({cx, cy});
//                 }
//             }
//         }
//     }
//     for (auto [xx, yy] : p)
//     {
        
//     }
// }

// signed main()
// {
//     ios::sync_with_stdio(0);
//     cin.tie(0); 
//     cout.tie(0);
//     int T = 1;
//     // cin >> T;
//     while (T--) solve();
//     return 0;
// }


#include <bits/stdc++.h>
#define int long long
#define endl '\n'
const int mod = 1000000007;
using namespace std;
void solve() 
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    vector<vector<int>> dist(n, vector<int>(m, -1));
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j] == 1)
            {
                dist[i][j] = 0;
                q.push({ i, j });
            }
        }
    }
    if (q.empty())
    {
        cout << 0 << endl;
        return;
    }
    //6 6
    //    1 0 0 0 0 0
    //    0 0 0 0 0 0
    //    0 0 0 0 0 0
    //    0 0 0 0 0 0
    //    0 0 0 0 0 0
    //    0 0 0 0 0 1

    vector<int> dx = { 0, 0, 1, -1 };
    vector<int> dy = { 1, -1, 0, 0 };
    while (!q.empty())
    {
        auto cell = q.front();
        q.pop();
        int x = cell.first;
        int y = cell.second;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] == -1)
            {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({ nx, ny });
            }
        }
    }
    int max1 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dist[i][j] > max1)
            {
                max1 = dist[i][j];
            }
        }
    }
    vector<pair<int,int>>pos;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dist[i][j] == max1)
            {
                pos.push_back({ i,j });
                
            }
            //cout << dist[i][j] << ' ';
        }
        //cout << endl;
    }
    //for (auto& [u, v] : pos)cout << u << ' ' << v << endl;
    int min1 = 1145141919810;
    for (auto& [u, v] : pos)
    {
        vector<vector<int>> dist2(n, vector<int>(m, -1));
        for (int a = 0; a < n; a++)
        {
            for (int b = 0; b < m; b++)
            {
                dist2[a][b] = dist[a][b];
            }
        }
        q.push({ u,v });
        while (!q.empty())
        {
            auto cell = q.front();
            q.pop();
            int x = cell.first;
            int y = cell.second;
            for (int i = 0; i < 4; i++)
            {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && dist[nx][ny] == -1)
                {
                    dist[nx][ny] = dist[x][y] + 1;
                    q.push({ nx, ny });
                }
            }
        }
        int max2 = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (dist[i][j] > max2)
                {
                    max2 = dist[i][j];
                }
            }
        }
        min1 = min(min1, max2);
    }
    cout << min1 << endl;

}
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    //linear_sieve(10000000);
    int t=1;
    //cin >> t;
    while(t--) solve();

}
【