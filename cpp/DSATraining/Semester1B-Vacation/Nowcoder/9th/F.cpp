/** 
 * @Author: Chenpi
 * @Date: 2025-08-12 12:44:24
 * @Link: https://ac.nowcoder.com/acm/contest/108306/F
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 1e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

void solve()
{
    int sx1, sy1, sx2, sy2;
    int tx1, ty1, tx2, ty2;
    cin >> sx1 >> sy1 >> sx2 >> sy2 >> tx1 >> ty1 >> tx2 >> ty2;

    int csx = sx1 + sx2;
    int csy = sy1 + sy2;
    int cty = tx1 + tx2;
    int ctyy = ty1 + ty2;

    int dx = abs(csx - cty);
    int dy = abs(csy - ctyy);

    cout << max(dx, dy) << endl;
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
