#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e6 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

char a[N];

void solve()
{
    int n, k; cin >> n >> k;
    cin >> a;
    int x = 0;
    for (int i = 0; i < n; i++) 
    {
        a[i] -= '0';
        if (a[i] == 0) x++;
    }
    if (x > k)
    {
        int l = 0, r = 0, cnt = 0, maxLen = 0;
        while (r < n)
        {
            r++;
            if (a[r] == 0) cnt++;
            while (cnt > k && l <= r)
            {
                if (a[l] == 0) cnt--;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
        }
        cout << maxLen << endl;
    }
    else
    {
        
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int t; cin >> t;
    // t = 1;
    while (t--) solve();
    return 0;
}