#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 5e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f3f3f3f3fLL;

priority_queue<int> q1;
priority_queue<int, vector<int>, greater<int>> q2;

void solve()
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int x; cin >> x;
        if (q1.empty() || x <= q1.top()) q1.push(x);
        else q2.push(x);
        while (q1.size() < (i + 1) / 2)
        {
            int y = q2.top(); q2.pop();
            q1.push(y);
        }
        while (q1.size() > (i + 1) / 2)
        {
            int y = q1.top(); q1.pop();
            q2.push(y);
        }
        if (i % 2 == 1) cout << q1.top() << ' ';
        else cout << (q1.top() + q2.top()) / 2 << ' ';
    }
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