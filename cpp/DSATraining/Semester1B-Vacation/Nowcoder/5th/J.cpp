#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 5e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int n, m;
vector<int> a[N], dis[N];

bool check(int d)
{
    int lx = -inf, rx = inf, ly = -inf, ry = inf;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++)
        {
            if (dis[i][j] > d)
            {
                lx = max(lx, i + j - d);
                rx = min(rx, i + j + d);
                ly = max(ly, i - j - d);
                ry = min(ry, i - j + d);
            }
        }
    }
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++)
        {
            if (i + j >= lx && i + j <= rx && i - j >= ly && i - j <= ry)
            {
                return true;
            }
        }
    }
    return false;
}

void solve()
{
    cin >> n >> m;
    queue<PII> q;
    for (int i = 0; i < n; i++)
    {
        a[i] = vector<int> (m, 0);
        dis[i] = vector<int>(m, inf);
        for (int j = 0; j < m; j++) 
        {
            cin >> a[i][j];
            if (a[i][j])
            {
                dis[i][j] = 0;
                q.push({i, j});
            }
        }
    }

    while (q.size())
    {
        auto [x, y] = q.front(); q.pop();
        for (int i = 0; i < 4; i++)
        {
            int cx = x + dx[i], cy = y + dy[i];
            if (cx >= 0 && cx < n && cy >= 0 && cy < m && dis[cx][cy] > dis[x][y] + 1)
            {
                dis[cx][cy] = dis[x][y] + 1;
                q.push({cx, cy});
            }
        }
    }

    int l = 0, r = inf;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    }
    cout << l << endl;
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
