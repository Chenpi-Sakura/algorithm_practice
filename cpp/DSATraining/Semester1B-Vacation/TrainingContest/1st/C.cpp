#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e2 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int a[N], n;
map<int, int> mp;
set<PII> st;

void solve()
{
    mp.clear(); st.clear();
    cin >> n;
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
        mp[a[i]] = i;
    }

    for (int i = 1; i <= n; i++)
    {
        int idx = mp[i];
        if (idx == 0 || a[idx] > a[idx - 1]) continue;
        for (int j = idx; j > 0; j--)
        {
            if (st.count({j - 1, j}) || a[j] > a[j - 1]) continue;
            st.insert({j - 1, j});
            swap(a[j], a[j - 1]);
        }
    }
    for (int i = 0; i < n; i++) cout << a[i] << ' ';
    cout << endl;
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