#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 5e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f3f3f3f3fLL;

void solve()
{
    string s; cin >> s;
    int enter = 0;
    if (s[0] != '-')
    {
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] < '1')
            {
                s.insert(s.begin() + i, '1');
                enter = 1;
                break;
            }
        }
        if (!enter) s.push_back('1');
    }
    else 
    {
        int flag = 1;
        if (s[1] != '1')
        {
            s.insert(s.begin() + 1, '1');
        }
        else 
        {
            int idx = -1;
            for (int i = 1; i < s.size(); i++)
            {
                if (s[i] > '1')
                {
                    idx = i;
                    break;
                } 
            }
            if (idx == -1)
            {
                s.push_back('1');
            }
            else 
            {
                s.insert(s.begin() + idx, '1');
            }
        }
    }
    cout << s << endl;
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