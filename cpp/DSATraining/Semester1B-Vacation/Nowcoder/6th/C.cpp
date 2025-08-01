#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 5e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

bool cmp(PII a, PII b)
{
    int xa = a.second - a.first, xb = b.second - b.first;
    if (xa == xb) return a.first < b.first;
    else return xa < xb;
}

void solve()
{
    int n, m; cin >> n >> m;
    vector<PII> ops;
    for (int i = 0; i < m; i++)
    {
        int l, r; cin >> l >> r;
        ops.push_back({l, r});
    }
    sort(ops.begin(), ops.end(), cmp);
    vector<PII> res;
    for (int i = 0; i < m; i++)
    {
        auto [l, r] = ops[i];
        int flag = 1;
        for (auto [ll, rr] : res)
        {
            if (l <= ll && r >= rr)
            {
                flag = 0;
                break;
            }
        }
        if (flag) res.push_back({l, r});
    }
    vector<char> ans(2 * n + 1, ')');
    if (res.size() > n)
    {
        cout << -1 << endl;
        return;
    }
    for (auto [l, r] : res)
    {
        int i = l;
        while (i <= r)
        {
            if (ans[i] == ')')
            {
                ans[i] = '(';
                break;
            }
            i++;
        }
    }
    int cur = n - res.size();
    for (int i = 1; cur > 0; i++)
    {
        if (ans[i] == ')')
        {
            cur--;
            ans[i] = '(';
        }
    }
    string s = "";
    int cnt = 0;
    for (int i = n * 2; i >= 1; i--)
    {
        if (ans[i] == ')') cnt++;
        else cnt--;
        if (cnt < 0)
        {
            cout << -1 << endl;
            return;
        }
        s = ans[i] + s;
    }
    cout << s << endl;
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
