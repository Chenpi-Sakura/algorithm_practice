#include <bits/stdc++.h>
using namespace std;

// const int N = 2e5 + 5;
// char a[N], b[N];

void solve()
{
    string a, b;
    cin >> a >> b;
    int h = -1;
    int lena = a.size(), lenb = b.size();
    for (int i = 0; i < lena; i++)
    {
        if (a[i] >= 'A' && a[i] <= 'Z')
        {
            h = i;
            break;
        }
    }
    if (h != -1)
    {
        for (int i = )
    }
    
}

int main()
{
    int t; cin >> t;
    while (t--) solve();
    return 0;
}