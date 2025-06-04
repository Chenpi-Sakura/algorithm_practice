#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

void solve()
{
    int n; double s; cin >> n >> s;
    int flag = 0;
    double lastT = 0;
    for (int i = 0; i < n; i++)
    {
        int cur; cin >> cur;
        if (lastT + s + 0.5 < cur) flag = 1;
        lastT = cur;
    }
    if (flag) cout << "No" << endl;
    else cout << "Yes" << endl;
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