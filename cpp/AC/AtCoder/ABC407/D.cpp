#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 25;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int a[N];

void solve()
{
    int ans = 0;
    int h, w; cin >> h >> w;
    for (int i = 0; i < h * w; i++) 
    {
        cin >> a[i];
        ans ^= a[i];
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