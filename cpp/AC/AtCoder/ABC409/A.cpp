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
    string t, a; cin >> t >> a;
    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        if (t[i] == 'o' && a[i] == 'o')
        {
            flag = 0;
            break;
        }
    }
    if (flag) cout << "No";
    else cout << "Yes";
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