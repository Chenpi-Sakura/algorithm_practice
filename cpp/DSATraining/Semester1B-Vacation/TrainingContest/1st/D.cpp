#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

void solve()
{
    int n, s; cin >> n >> s;
    string t = to_string(n);
    reverse(t.begin(), t.end());
    int cur = 0;
    for (int i = 0; i < t.size(); i++) cur += t[i] - '0';
    if (cur == s)
    {
        cout << 0 << endl;
        return;
    }
    if (cur < s)
    {
        int le = s - cur;
        int i = 0;
        for (; le >= 9 - (t[i] - '0'); i++)
        {
            le -= 9 - (t[i] - '0');
            t[i] = '9';
        }
        t[i] += le;
        reverse(t.begin(), t.end());
        int temp = stoll(t);
        cout << temp - n << endl;
    }
    else
    {
        // int ans = 0;
        int le = cur - s;
        int idx = 0;
        int tmp = n;
        while (1)
        {
            if (t[idx] == '0') {idx++; continue;}
            int x = min(le, 10 - (int)(t[idx] - '0'));
        //     ans += x;
            tmp += x * ;
        //     string temp = to_string(tmp);
        //     for (int i = 0; i < temp.size(); i++) cur += temp[i] - '0';
        //     if (cur <= s)
        //     {
        //         ans += s - cur;
        //         break;
        //     } 
        //     idx++;
        //     le = cur - s;
        }
        // cout << ans << endl;
        return;
    }
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