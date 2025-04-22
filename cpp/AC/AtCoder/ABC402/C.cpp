#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 3e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

unordered_set<int> pl[N], nc; // 第 i 种配料所存在的菜肴
int cy[N]; // 第 i 种菜肴拥有的不喜欢的配料数

void solve()
{
    int n, m; cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        int k; cin >> k;
        cy[i] = k;
        for (int j = 1; j <= k; j++)
        {
            int te; cin >> te;
            pl[te].insert(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int te; cin >> te;
        for (int x : pl[te])
        {
            if (--cy[x] == 0) nc.insert(x);
        }
        cout << nc.size() << endl;
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); //cout.tie(0);
    int t; // cin >> t;
    t = 1;
    while (t--) solve();
    return 0;
}