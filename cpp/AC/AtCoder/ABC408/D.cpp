#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int a[N], po[N], pz[N];

void solve()
{
    memset(po, 0, sizeof(po));
    memset(pz, 0, sizeof(pz));
    int n; string s;
    cin >> n >> s;
    for (int i = 0; i <= n; i++) 
    {
        a[i + 1] = s[i] - '0';
        po[i + 1] = po[i];
        pz[i + 1] = pz[i];
        if (a[i + 1] == 0) pz[i + 1]++;
        else po[i + 1]++;
    }

    if (po[n] == n || pz[n] == n)
    {
        cout << 0 << endl;
        return;
    }

    int ans = min(po[n], pz[n]);
    int minL = po[0] - pz[0];

    for (int i = 1; i <= n; i++)
    {
        ans = min(ans, pz[i] - po[i] + minL + po[n]);
        minL = min(minL, po[i] - pz[i]);
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}