#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int a[N];

void solve()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n, greater<int>());
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        int c = a[i] - i + 1;
        if (c <= 0)
        {
            ans = 0;
            break;
        }
        ans = ans * c % M;
    }
    cout << ans << endl;
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