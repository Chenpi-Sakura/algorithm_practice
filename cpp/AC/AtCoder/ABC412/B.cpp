#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

void solve()
{
    int n; cin >> n;
    set<string> s;
    vector<string> vs;
    for (int i = 0; i < n; i++)
    {
        string st; cin >> st;
        vs.push_back(st);
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            s.insert(vs[i] + vs[j]);
            s.insert(vs[j] + vs[i]);
        }
    }
    cout << s.size() << endl;
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