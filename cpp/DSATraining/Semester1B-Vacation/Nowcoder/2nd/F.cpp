#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

int a[N];

void solve()
{
    vector<int> a;
    int n, t; cin >> n >> t;
    string s; cin >> s; s = s + s;
    int bgn = 0;
    while (s[bgn] == '0') bgn++;
    int maxA = 0, left = 0;
    for (int i = bgn; i < bgn + n; i++)
    {
        if (s[i] == '0')
        {
            int j = i;
            while (s[i] == '0' && i < bgn + n) i++;
            a.push_back(i - j);
            left += i - j;
            maxA = max(maxA, i - j);
        }
    }
    for (int x : a)
    {
        if (x == maxA)
        {
            maxA = -1;
            if (t >= x) left -= x;
            else left -= t + 1;
        }
        else 
        {
            if (t * 2 >= x) left -= x;
            else left -= 2 * t;
        }
    }
    cout << left << endl;
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