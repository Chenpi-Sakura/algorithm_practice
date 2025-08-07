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
    set<int> s;
    vector<int> a;
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x; cin >> x;
        s.insert(x);
        a.push_back(x);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (s.find(a[i] | a[j]) == s.end())
            {
                cout << "NO" << endl;
                return;
            }
        }
    }
    cout << "YES" << endl;
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