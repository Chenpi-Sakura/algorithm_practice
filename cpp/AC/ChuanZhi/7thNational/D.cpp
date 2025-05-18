#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

vector<int> v;

int toNum(vector<int> &vt)
{
    int ans = 0;
    for (int i : vt)
    {
        ans = ans * 10 + i;
    }
    return ans;
}

void init()
{
    for (int i = 1; i <= 9; i++)
    {
        vector<int> temp;
        for (int j = 1; j <= i; j++)
        {
            temp.push_back(j);
        }

        do 
        {
            v.push_back(toNum(temp));
        }
        while (next_permutation(temp.begin(), temp.end()));
    }
    sort(v.begin(), v.end());
}

void solve()
{
    init();
    int l, r; cin >> l >> r;
    auto it = lower_bound(v.begin(), v.end(), l);
    if (it != v.end() && *it <= r) cout << l << endl;
    else cout << -1 << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); //cout.tie(0);
    int t; // cin >> t;
    t = 1;
    while (t--) solve();
    return 0;
}