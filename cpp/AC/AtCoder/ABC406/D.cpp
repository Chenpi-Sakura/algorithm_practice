#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

void solve()
{
    int h, w, n; cin >> h >> w >> n;

    vector<vector<int>> a(h + 1);
    vector<vector<int>> b(w + 1);
    vector<bool> ux(h + 1, false);
    vector<bool> uy(w + 1, false);
    vector<bool> used(n, false);

    for (int i = 0; i < n; i++)
    {
        int x, y; cin >> x >> y;
        a[x].push_back(i);
        b[y].push_back(i);
    }

    int q; cin >> q;
    while (q--)
    {
        int t; cin >> t;
        if (t == 1)
        {
            int x; cin >> x;
            if (ux[x]) cout << 0 << '\n';
            else
            {
                int ans = 0;
                for (int e : a[x])
                {
                    if (!used[e])
                    {
                        used[e] = true;
                        ans++;
                    }
                }
                ux[x] = true;
                cout << ans << '\n';
            }
        }
        else
        {
            int y; cin >> y;
            if (uy[y]) cout << 0 << '\n';
            else
            {
                int ans = 0;
                for (int e : b[y])
                {
                    if (!used[e])
                    {
                        used[e] = true;
                        ans++;
                    }
                }
                uy[y] = true;
                cout << ans << '\n';
            }
        }
    }
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

