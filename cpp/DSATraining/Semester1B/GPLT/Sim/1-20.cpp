#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

double a[N], b[N], c[N];

void solve()
{
    int hi1 = 0, hi2 = 0;
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        int pos, val; cin >> pos >> val;
        hi1 = max(hi1, pos);
        a[pos] = val;
    }
    int m; cin >> m;
    for (int i = 0; i < m; i++)
    {
        int pos, val; cin >> pos >> val;
        hi2 = max(hi2, pos);
        b[pos] = val;
    }
    int high = hi1;
    for (int i = 0; hi1 >= hi2; i++)
    {
        if (a[hi1] == 0)
        {
            hi1--;
            continue;
        } 
        c[hi1 - hi2] = a[hi1] / b[hi2];
        for (int i = 0; i <= hi2; i++)
        {
            a[hi1 - i] -= b[hi2 - i] * c[hi1 - hi2];
        }
        hi1--;
    }

    int isNotZero = 0;
    for (int i = high; i >= 0; i--)
    {
        if (abs(c[i]) >= 5e-2) isNotZero++;
    }
    printf("%lld ", isNotZero);
    if (!isNotZero) cout << 0 << ' ' << "0.0";
    else
    {
        bool isFirst = true;
        for (int i = high; i >= 0; i--)
        {
            if (abs(c[i]) >= 5e-2)
            {
                if (isFirst)
                {
                    printf("%lld %.1lf", i, c[i]);
                    isFirst = false;
                }
                else printf(" %lld %.1lf", i, c[i]);
                // cout << i << ' ' << c[i] << ' ';
            }
        }
    }
    cout << endl;
    isNotZero = 0;
    for (int i = high; i >= 0; i--)
    {
        if (abs(a[i]) >= 5e-2) isNotZero++;
    }
    printf("%lld ", isNotZero);
    if (!isNotZero) cout << 0 << ' ' << "0.0";
    else
    {
        bool isFirst = true;
        for (int i = high; i >= 0; i--)
        {
            if (abs(a[i]) >= 5e-2)
            {
                if (isFirst) 
                {
                    printf("%lld %.1lf", i, a[i]);
                    isFirst = false;
                }
                else printf(" %lld %.1lf", i, a[i]);
                // cout << i << ' ' << a[i] << ' ';
            }
        }
    }
}

signed main()
{
    // ios::sync_with_stdio(0);
    cin.tie(0); //cout.tie(0);
    int t; // cin >> t;
    t = 1;
    while (t--) solve();
    return 0;
}