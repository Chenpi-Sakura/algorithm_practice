#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 5e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

void solve()
{
    int n; cin >> n;
    int cur = 0;
    vector<int> p2;
    // 得到目前的2的次方
    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
        while (a % 2 == 0)
        {
            cur++;
            a /= 2;
        }
    }
    // 假如此时2的次方不为0且2的次方的个数大于等于n个
    if (cur != 0 && cur >= n) 
    { 
        cout << 0 << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        int x = 0;
        int t = i;
        while (t % 2 == 0)
        {
            x++;
            t /= 2;
        } 
        p2.push_back(x);
    }
    // 遍历，查找，看是否能满足大于等于n个
    sort(p2.rbegin(), p2.rend());
    // for (int x : p2) cout << x << endl;
    int ans = 0;
    for (int x : p2)
    {
        if (cur >= n) break;
        cur += x;
        ans++;
    }
    // for (int i = n; i >= 1; i--)
    // {
    //     if (i % 2 == 0)
    //     {
    //         int x = i;
    //         while(x % 2 == 0)
    //         {
    //             cur++;
    //             x /= 2;
    //         }
    //         ans++;
    //     }
    //     // cout << i << ' ' << cur << endl;
    //     if (cur >= n) break;
    // }
    if (cur >= n) cout << ans << endl;
    else cout << -1 << endl;
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