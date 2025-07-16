#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e6 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int sed = 2333;
int H[N], h[N], pw[N];
char ans[N], s[N];

int query(int l, int r)
{
    return (H[r] - H[l - 1] * pw[r - l + 1] % M + M) % M;
}

void solve()
{
    int n; cin >> n;
    pw[0] = 1;
    for (int i = 1; i < N; i++) pw[i] = pw[i - 1] * sed % M;
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> (s + 1);
        int len = strlen(s + 1);
        for (int i = 1; i <= len; i++) h[i] = (h[i - 1] * sed % M + s[i]) % M;
        int l;
        for (int j = min(m, len); j >= 0; j--)
        {
            if (h[j] == query(m - j + 1, m))
            {
                l = j;
                break;
            }
        }
        for (int j = l + 1; j <= len; j++)
        {
            ans[++m] = s[j];
            H[m] = (H[m - 1] * sed % M + s[j]) % M;
        }
    }
    for (int i = 1; i <= m; i++) cout << ans[i];
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