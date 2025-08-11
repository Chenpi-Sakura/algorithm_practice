#include <bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
void solve() 
{
    int n;
    cin >> n;
    int a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        if (a == b)cout << 0 << endl;
        else if (a < b)
        {
            if (a % 2 != b % 2)cout << 1 << endl;
            else cout << (((b - a)/2) % 2 == 1 ? 2 : 3) << endl;
            // cout << b - a << endl;
        }
        else
        {
            if (a % 2 != b % 2)cout << 2 << endl;
            else cout << 1 << endl;
        }
    }

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    // t = read();  // 如需多组测试可取消注释
    while (t--) solve();
    return 0;
}