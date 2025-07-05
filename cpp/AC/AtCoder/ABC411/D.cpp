#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 2e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

string s[N];
int op[N], p[N];

void solve()
{
    int n, q; cin >> n >> q;
    for (int i = 1; i <= q; i++)
    {
        cin >> op[i] >> p[i];
        if (op[i] == 2)
        {
            cin >> s[i];
            reverse(s[i].begin(), s[i].end());
        }
    }

    int c = 0;
    string ans = "";

    for (int i = q; i > 0; i--)
    {
        if (op[i] == 1)
        {
            if (c == p[i])
            {
                c = 0;
            }
        }
        else if (op[i] == 2)
        {
            if (c == p[i])
            {
                ans += s[i];
            }
        }
        else
        {
            if (c == 0)
            {
                c = p[i];
            }
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans << endl;
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