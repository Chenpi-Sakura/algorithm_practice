#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int a[N], b[N], c[N];

void solve()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    int ans1 = 0;
    for (int i = 1; i <= n / 2; i++) ans1 += abs(abs(a[i]) - abs(a[n - i + 1]));
    for (int i = 1; i <= n / 2; i++)
    {
        b[n / 2 + 1 - i] = (a[n / 2 + 1 - i] + a[n / 2 + 1 + i]) / 2;
        b[n / 2 + 1 + i] = (a[n / 2 + 1 - i] + a[n / 2 + 1 + i]) / 2;
    }
    int ans2 = n;
    for (int i = 1; i <= n; i++) c[i] = a[i] - b[i];
    for (int i = 1; i <= n / 2; i++) ans2 += abs(abs(c[i]) - abs(c[n - i + 1]));
    if (ans1 < ans2)
    {
        cout << 1 << ' ' << ans1 << endl;
        for (int i = 1; i <= n; i++) cout << a[i] << ' ';
    }
    else
    {
        cout << 2 << ' ' << ans2 << endl;
        for (int i = 1; i <= n; i++) cout << b[i] << ' ';
        cout << endl;
        for (int i = 1; i <= n; i++) cout << c[i] << ' ';
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