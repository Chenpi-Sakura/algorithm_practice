#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int ans[N];
vector<int> adj[N];
map<int, int> label[N];
int vis[N][4];

void solve()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int d; cin >> d;
        for (int j = 1; j <= d; j++)
        {
            int v; cin >> v;
            adj[i].push_back(v);
            label[i][v] = j;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= adj[i].size(); j++)
        if (!vis[i][j])
        {
            vector<PII> paths;
            set<PII> app;

            int cu = i, cd = j;

            while (!vis[cu][cd])
            {
                vis[cu][cd] = 1;
                paths.push_back({cu, cd});

                int cv = adj[cu][cd - 1];
                app.insert({min(cu, cv), max(cu, cv)});

                cd = label[cv][cu] % adj[cv].size() + 1;
                cu = cv;
            }
            for (auto p : paths)
            {
                if (p.second == 1)
                {
                    ans[p.first] = app.size();
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << endl;
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