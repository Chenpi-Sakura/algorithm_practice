#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int a[N], s[N], f[N], d[N];
int q[N], head = 0, tail = 1;

void solve()
{
    int n, k; cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> a[i], s[i] = s[i - 1] + a[i];
    for (int i = 1; i <= n; i++)
    {
        d[i] = f[i - 1] - s[i];
        while (head <= tail && d[q[tail]] < d[i]) tail--;
        q[++tail] = i;
        while (head <= tail && q[head] < i - k) head++;
        f[i] = d[q[head]] + s[i];
    }
    cout << f[n] << endl;
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