#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    string ans = "";
    if (n % 2 == 0)
    {
        for (int i = 1; i <= n / 2 - 1; i++) ans += "-";
        ans += "=";
        cout << ans; 
        reverse(ans.begin(), ans.end());
        cout << ans;
    }
    else
    {
        for (int i = 1; i <= n / 2; i++) ans += "-";
        cout << ans << '=';
        reverse(ans.begin(), ans.end());
        cout << ans;
    }
    return 0;
}