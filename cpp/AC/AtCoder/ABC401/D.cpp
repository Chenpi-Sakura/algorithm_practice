#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

void solve()
{
    int n, k; cin >> n >> k;
    string s, cp; cin >> s;
    cp = s;
    int len = s.size();
    for (int i = 0; i < len; i++)
    {
        if (cp[i] == '?')
        {
            if (i - 1 >= 0 && cp[i - 1] == 'o')
                cp[i] = '.';
            while (i < len && cp[i] == '?')
                i++;
            if (i < len && cp[i] == 'o')
                cp[i - 1] = '.';
        }
    } 
    int qj = 0, no = 0;
    bool kb = false;
    for (int i = 0; i < len; i++)
    {
        if (cp[i] == '?')
        {
            int cd = 0;
            if (i == 0) kb = true;
            while (i < len && cp[i] == '?') 
            {
                i++; cd++;
            }
            qj += (cd + 1) / 2;
            if (i == len) kb = true;
        }
        if (i < len && cp[i] == 'o') no++;
    }
    if (qj + no > k) cout << cp << endl;
    else
    {
        for (int i = 0; i < len; i++)
        {
            if (i - 1 < 0 && cp[i] == '?') cp[i] = 
        }
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); //cout.tie(0);
    int t; // cin >> t;
    t = 1;
    while (t--) solve();
    return 0;
}