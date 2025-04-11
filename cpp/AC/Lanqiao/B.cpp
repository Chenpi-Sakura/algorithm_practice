#include<bits/stdc++.h> 
using namespace std;
#define int long long

signed main( )
{
    int a, b, n; cin >> a >> b >> n;
    int weeks = n / (5 * a + 2 * b);
    int left = n % (5 * a + 2 * b);
    int ans = weeks * 7;
    if (left > 5 * a) ans += 6;
    else ans += (left + a - 1) / a;
    cout << ans << endl;
    return 0;
}