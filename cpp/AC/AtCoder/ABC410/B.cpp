#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int box[105], in[105];
priority_queue<PII> pq;

void solve()
{
    int n, q; cin >> n >> q;
    for (int i = 1; i <= q; i++)
    {
        int x; cin >> x;
        if (x != 0)
        {
            in[i] = x;
            box[x]++;
        }
        else
        {
            for (int j = 1; j <= n; j++)
            {
                pq.push({-box[j], -j});
            }
            box[-pq.top().second]++;
            in[i] = -pq.top().second;
            while (pq.size()) pq.pop();
        }
    }
    for (int i = 1; i <= q; i++) cout << in[i] << ' ';
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