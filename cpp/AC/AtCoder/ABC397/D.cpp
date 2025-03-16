/*
    Math problems, dare to think, dare to do!
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n; cin >> n;
    for (ll i = 1; i <= 1e6; i++)
    {
        ll l = 1, r = 1e12;
        while (l <= r)
        {
            ll m = (l + r) >> 1;
            __int128 A = (__int128)m, B = A + i;
            __int128 res = B * B * B - A * A * A;
            if (res == n)
            {
                cout << m + i << ' ' << m << endl;
                return 0;
            }
            if (res > n) r = m - 1;
            else if (res < n) l = m + 1;
        }
    }
    cout << -1 << endl;
    return 0;
}