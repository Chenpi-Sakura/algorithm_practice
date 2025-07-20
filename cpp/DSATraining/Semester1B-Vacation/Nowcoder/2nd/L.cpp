#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 5e5 + 5;
const int M = 998244353;
const int inf = 0x3f3f3f3f;

int p2[N];

void pw2()
{
    p2[0] = 1;
    for (int i = 1; i < N; i++) p2[i] = (p2[i - 1] * 2) % M;
}

void solve()
{
    int n; cin >> n;
    vector<int> a(n + 1), vis(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    vector<int> odd, even;
    int bigeven = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            int len = 0, cur = i;
            while (!vis[cur])
            {
                vis[cur] = 1;
                len++;
                cur = a[cur];
            }
            if (len % 2 == 1) odd.push_back(len);
            else 
            {
                even.push_back(len); 
                if (len > 2) bigeven++;
            }
        }
    }

    int ans = 0;

    if (odd.size() > 2 || odd.size() == 1)
    {
        cout << ans << endl;
        return;
    }
    if (odd.size() == 2)
    {
        ans = (odd[0] * odd[1]) % M;
        ans = (ans * p2[bigeven]) % M;
        cout << ans << endl;
        return;
    }
    for (int len : even)
    {
        int res = ((len / 2) * (len / 2)) % M; // 推导得到公式
        int be = bigeven;
        if (len > 2) be--;
        res = (res * p2[be]) % M;
        ans = (ans + res) % M;
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    pw2();
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}