#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int fa[N];

int find(int x)
{
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

void solve()
{
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 0; i < k; i++)
    {
        int x, y; cin >> x >> y;
        fa[find(x)] = fa[find(y)];
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) if (fa[i] == i) cnt++;
    cout << k - (n - cnt) << endl;
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