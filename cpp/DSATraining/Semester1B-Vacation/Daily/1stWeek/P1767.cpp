#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 200 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

char mp[N][N];
int vis[N][N];
int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};
int n;

void dfs(int i, int j)
{
    vis[i][j] = 1;
    for (int k = 0; k < 4; k++)
    {
        int x = i + dr[k], y = j + dc[k];
        if (x >= 0 && x < n && y >= 0 && y < N && islower(mp[x][y]) && !vis[x][y]) dfs(x, y);    
    }
}

void solve()
{
    cin >> n; cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    for (int i = 0; i < n; i++)
        for (int j = 0; j < N; j++)
            mp[i][j] = ' ';
    for (int i = 0; i < n; i++)
    {
        string s; getline(cin, s);
        for (int j = 0; j < s.size(); j++) mp[i][j] = s[j];
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (islower(mp[i][j]) && !vis[i][j]) 
            {
                dfs(i, j);
                ans++;
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
    //cin >> T;
    while (T--) solve();
    return 0;
}