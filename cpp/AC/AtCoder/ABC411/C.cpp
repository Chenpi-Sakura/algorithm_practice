#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 5e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int a[N], ans;
set<int> s;

void solve()
{
    int n, q; cin >> n >> q;
    while (q--)
    {
        int x; cin >> x;
        if (a[x] == 0)
        {// white
            a[x] = 1;
            s.insert(x);
            if (s.find(x + 1) == s.end() && s.find(x - 1) == s.end()) ans++;
            else if (s.find(x + 1) != s.end() && s.find(x - 1) != s.end()) ans--;
        }
        else
        {// black
            a[x] = 0;
            s.erase(x);
            if (s.find(x + 1) == s.end() && s.find(x - 1) == s.end()) ans--;
            else if (s.find(x + 1) != s.end() && s.find(x - 1) != s.end()) ans++;
        }
        cout << ans << endl;
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