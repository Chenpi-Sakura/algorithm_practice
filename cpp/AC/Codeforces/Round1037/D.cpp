#include <bits/stdc++.h>
using namespace std;
#define int unsigned long long

typedef pair<int, int> PII;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

struct dc {int l, r, w;};

bool cmp(dc a, dc b)
{
    return a.l < b. l;
}

void solve()
{
    int n, k; cin >> n >> k;
    vector<dc> dcs(n);
    int maxW = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> dcs[i].l >> dcs[i].r >> dcs[i].w;
        maxW = max(maxW, dcs[i].w);
    }
    sort(dcs.begin(), dcs.end(), cmp);
    for (int i = 0; i < n; i++)
    {
        if (k >= dcs[i].l)
        {
            if (k <= dcs[i].r && k < dcs[i].w)
            {
                k = dcs[i].w;
            }
        }
        else
        {
            break;
        }
    }
    cout << k << endl;
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