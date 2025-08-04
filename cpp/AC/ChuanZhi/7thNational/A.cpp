/**
 * @Author: Chenpi
 * @Date: 2025-08-02 16:41:54
 * @Link: https://ac.nowcoder.com/acm/contest/108576/A
 */
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
    int odd = inf, eve = inf;
    for (int i = 1; i <= n; i++)
    {
        int a; cin >> a;
        if (i % 2 == 0) odd = min(odd, a);
        else eve = min(eve, a);
    }
    if ((odd + eve) % 2 == 0) cout << "GEGE" << endl;
    else cout << "BEN" << endl; 
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