#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 5e5 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f3f3f3f3fLL;


PII times(PII a, PII b)
{
    PII res = {0, 0};
    res.first = a.first * b.first + a.second * b.second * -2;
    res.second = a.first * b.second + a.second * b.first;
    return res;
}

PII add(PII a, PII b)
{
    PII res {0, 0};
    res.first = a.first + b.first;
    res.second = a.second + b.second;
    return res;
}

void solve()
{
    string a, b; cin >> a >> b;
    PII x = {0, 0}, y = {0, 0};

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    PII cur = {1, 0}, xs = {0, 1};
    for (int i = 0; i < a.size(); i++)
    {
        if (a[i] == '1') x = add(x, cur);
        cur = times(cur, xs);
    }
    cur = {1, 0}, xs = {0, 1};
    for (int i = 0; i < b.size(); i++)
    {
        if (b[i] == '1') y = add(y, cur);
        cur = times(cur, xs);
    }
    PII res = times(x, y);
    
    vector<int> ans;
    while (res.first != 0 || res.second != 0)
    {
        int c = (res.first % 2 + 2) % 2;
        ans.push_back(c);
        int aa = res.second, bb = -(res.first - c) / 2;
        res.first = aa, res.second = bb;
    }
    if (ans.empty()) cout << 0 << endl;
    else 
    {
        reverse(ans.begin(), ans.end());
        for (int an : ans) cout << an;
        cout << endl;
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