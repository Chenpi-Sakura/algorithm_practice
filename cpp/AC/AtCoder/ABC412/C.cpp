#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

void solve()
{
    deque<PII> record;
    int q; cin >> q;
    while (q--)
    {
        int op, k; cin >> op >> k;
        if (op == 1)
        {
            int x; cin >> x;
            record.push_back({k, x});
        }
        else
        {
            int cur = 0, ans = 0;
            while (record.size())
            {
                if (cur + record.front().first < k)
                {
                    cur += record.front().first;
                    ans += record.front().first * record.front().second;
                    record.pop_front();
                }
                else if (cur + record.front().first == k)
                {
                    ans += record.front().first * record.front().second;
                    record.pop_front();
                    break;
                }
                else
                {
                    ans += (k - cur) * record.front().second;
                    record.front().first -= k - cur;
                    break;
                }
            }
            cout << ans << endl;
        }
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