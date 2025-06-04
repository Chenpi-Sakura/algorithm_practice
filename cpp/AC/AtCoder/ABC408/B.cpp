#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

unordered_set<int> s;
vector<int> a;

void solve()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int c; cin >> c;
        if (s.find(c) == s.end())
        {
            a.push_back(c);
            s.insert(c);
        }
    }
    sort(a.begin(), a.end());
    cout << a.size() << endl;
    for (int x : a) cout << x << ' ';
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