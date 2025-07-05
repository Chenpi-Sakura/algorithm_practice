#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int a[55];

void solve()
{
    int n; cin >> n;
    for (int i = 1; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++)
    {
        int c = 0;
        for (int j = i; j < n; j++)
        {
            c += a[j];
            cout << c << " ";
        }
        cout << endl;
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