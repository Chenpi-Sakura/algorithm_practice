#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

unordered_map<int, int> amap;
int a[N];

void solve()
{
    memset(a, 0, sizeof(a));
    int n; cin >> n;
    for (int i = 1; i <= 2 * n; i++) cin >> a[i];
    int ans = 0;
    for (int i = 1; i <= 2 * n - 1; i++)
    {
        if (a[i] == a[i + 1])
        {
            i++;
            continue;
        }
        int x = a[i], y = a[i + 1];
        //if (amap[x] == y || amap[y] == x) continue;
        for (int j = i + 2; j <= 2 * n - 1; j++)
        {
            if (a[j] == x)
            {
                if (a[j + 1] == y || a[j - 1] == y) ans++;
                break;
            }
        }
        // amap[x] = y, amap[y] = x;
    }
    cout << ans << endl;
}

signed main()
{
    int t; cin >> t;
    while (t--) solve();
    return 0;
}