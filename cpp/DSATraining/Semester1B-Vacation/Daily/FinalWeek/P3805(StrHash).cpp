/** 
 * @Author: Chenpi
 * @Date: 2025-08-12 20:10:39
 * @Link: https://www.luogu.com.cn/problem/P3805
 */
#include <bits/stdc++.h>
using namespace std;
#define ULL unsigned long long // 不要滥用ULL，可能会导致数字下溢！
#define endl "\n"

typedef pair<int, int> PII;
const int N = 1.1e7 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f3f3f3f3fLL;

const int P = 131;

ULL h[N], hr[N], p[N];
int n;

ULL getHash(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}

ULL getRevHash(int l, int r)
{
    return hr[n - l + 1] - hr[n - r] * p[r - l + 1];
}

void solve()
{
    string s; cin >> s;
    n = s.size();
    string rs = {s.rbegin(), s.rend()};

    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + s[i - 1];
        hr[i] = hr[i - 1] * P + rs[i - 1];
    }

    int ans = 1;

    for (int i = 1; i <= n; i++)
    {
        int l = 0, r = min(i - 1, n - i), res = 0;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (getHash(i - mid, i + mid) == getRevHash(i - mid, i + mid))
            {
                res = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        ans = max(ans, res * 2 + 1);

        if (i < n)
        {
            l = 0, r = min(i - 1, n - (i + 1)), res = 0;
            while (l <= r)
            {
                int mid = (l + r) / 2;
                if (getHash(i - mid, i + 1 + mid) == getRevHash(i - mid, i + 1 + mid))
                {
                    res = mid;
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            ans = max(ans, (res + 1) * 2);
        }
    }
    cout << ans << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}