#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    while (n--)
    {
        int l, r, d, u; cin >> l >> r >> d >> u;
        if (l == r && u == d && l == u) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}