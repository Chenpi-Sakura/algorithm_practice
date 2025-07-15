#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

PII hg[35];
int vis[35], n, v, a, b, ans = inf;

void dfs(int d)
{
    if (a + b > v) ans = min(ans, abs(a - b));
    if (!ans) return;
    for (int i = d; i < n; i++)
    {
        if (!vis[i])
        {
            vis[i] = 1;
            a += hg[i].first;
            b += hg[i].second;
            dfs(i + 1);
            a -= hg[i].first;
            b -= hg[i].second;
            vis[i] = 0;
        }
    }
}

void solve()
{
    cin >> n >> v;
    for (int i = 0; i < n; i++)
    {
        int a, b; cin >> a >> b;
        hg[i] = {a, b};
    }
    dfs(0);
    cout << (ans == inf ? -1 : ans) << endl;
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