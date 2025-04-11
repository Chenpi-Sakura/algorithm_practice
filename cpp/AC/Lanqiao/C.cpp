#include<bits/stdc++.h> 
using namespace std;
#define int long long

const int N = 1e4 + 5;
int a[N];

signed main( )
{
    int n; cin >> n;
    for (int i = 1; i <= (n + 1) / 2; i++)
    {
        a[i] = (n - i) * 2;
        cout << a[i] << endl;
    }
    for (int i = n / 2; i >= 1; i--)
    {
        cout << a[i] << endl;
    }
    return 0;
}