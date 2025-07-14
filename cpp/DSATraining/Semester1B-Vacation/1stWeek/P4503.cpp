#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 3e4 + 5;
const int M = 205;;
const int inf = 0x3f3f3f3f;
const int p = 2333;

int ha[N][M], t[N], pw[M];

void solve()
{
    int n, l, s; cin >> n >> l >> s;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= l; j++)
        {
            char c; cin >> c;
            ha[i][j] = ha[i][j - 1] * p + c;
        }
    }

    pw[0] = 1;
    for (int i = 1; i <= l; i++) pw[i] = pw[i - 1] * p;

    int ans = 0;
    for (int i = 1; i <= l; i++)
    {// 列举字符位置
        for (int j = 1; j <= n; j++)
        {// 列举字符串
            int pre = ha[j][i - 1];
            int suf = ha[j][l] - ha[j][i] * pw[l - i];
            t[j] = pre * pw[l - i] + suf;
        }
        sort(t + 1, t + n + 1);
        int cnt = 1;
        for (int j = 1; j < n; j++)
        {
            if (t[j] == t[j + 1])
            {
                ans += cnt;
                cnt++;
            }
            else cnt = 1;
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
    //cin >> T;
    while (T--) solve();
    return 0;
}