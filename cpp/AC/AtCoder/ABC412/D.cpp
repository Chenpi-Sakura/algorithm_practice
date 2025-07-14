#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

void solve()
{
    int n; cin >> n;
    vector<int> ap, an;
    for (int i = 0; i < n; i++)
    {
        int ai; cin >> ai;
        if (ai > 0) ap.push_back(ai);
        else an.push_back(ai);
    }
    sort(ap.begin(), ap.end());
    sort(an.begin(), an.end(), greater<int>());
    if (an.empty())
    {
        double r = ap[1] / ap[0];
        for (int i = 1; i < ap.size() - 1; i++)
        {
            if (ap[i] * r != ap[i + 1])
            {
                cout << "No" << endl;
                return;
            }
        }
        cout << "Yes" << endl;
    }
    else
    {
        double r;
        if (an.size() < ap.size() - 1 || an.size() > ap.size() + 1)
        {
            cout << "No" << endl;
            return;
        }
        if (abs(an[0]) > ap[0])
            r = an[0] / ap[0];
        else
            r = ap[0] / an[0];
        for (int i )
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