#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e5 + 5;
int a[N];

unsigned main()
{
    int t; cin >> t;
    while (t--)
    {
        memset(a, 0, sizeof(a));
        int n, x; cin >> n >> x;
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (a[i] >= (n - i + x - 1) / x)
            {  
                int left = ()
            }
        }
    }
    return 0;
}