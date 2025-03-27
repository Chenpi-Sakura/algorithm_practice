#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5;
int cnt[N];

bool check()
{
    if (cnt[2] >= 2 && cnt[1] >= 1 && cnt[0] >= 3 && cnt[3] >= 1 && cnt[5] >= 1) return true;
    return false;
}

int main()
{
    int t; cin >> t;
    while (t--)
    {
        memset(cnt, 0, sizeof(cnt));
        int n; cin >> n;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int x; cin >> x; cnt[x]++;
            if (!ans && check()) ans = i;
        }
        cout << ans << endl;
    }
    return 0;
}