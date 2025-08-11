#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
void solve() 
{
    int n;
    cin >> n;
    vector<int>num(n);
    vector<double>res;
    for (int i = 0; i < n; i++)cin >> num[i];
    sort(num.begin(), num.end());
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        res.push_back(num[i]);
        sum += num[i];
        double ave = sum / (double)(i+1);
        auto it = upper_bound(res.begin(), res.end(), ave);
        int idx = it - res.begin();

        ans = max(ans, i - idx + 1);
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // t = read();  // 如需多组测试可取消注释
    while (t--) solve();
    return 0;
}