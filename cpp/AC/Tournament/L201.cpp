#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t; cin >> t;
    while(t--)
    {
        int n; string s;
        cin >> n >> s;
        string ans = ""; ans += s[0];
        bool flag = false;
        for (int i = 1; i < n; i++)
        {
            if (s[i] < s[i - 1]) {ans += s[i]; flag = true;}
            else if (flag && s[i] == s[i - 1]) ans += s[i - 1];
            else break;
        }
        cout << ans;
        reverse(ans.begin(), ans.end());
        cout << ans << endl;
    }
    return 0;
}