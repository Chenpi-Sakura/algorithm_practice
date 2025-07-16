#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e2 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int a[N];

void solve()
{
    int n; cin >> n;
    int j = 0, o = 0;
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
        if (a[i] % 2 == 1) j++;
        else o++;
    }
    if ((j % 2 == 1 && o % 2 == 0) || (j % 2 == 0 && o % 2 == 1)) 
    {
        cout << "NO" << endl; 
        return;
    }
    if (j % 2 == 0 && o % 2 == 0) 
    {
        cout << "YES" << endl; 
        return;
    }
    sort(a, a + n);
    for (int i = 0; i < n - 1; i++)
    {
        if (a[i] + 1 == a[i + 1])
        {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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