#include<bits/stdc++.h> 
using namespace std;
#define int long long

const int N = 5e4 + 5;
const int M = 1e9 + 7;

struct bomb
{double x, y, r;};

vector<int> fa(N);

bomb dl[N];
bomb ro[N];

signed main( )
{
    int n, m; cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> dl[i].x >> dl[i].y >> dl[i].r;
    for (int i = 0; i < m; i++) cin >> ro[i].x >> ro[i].y >> ro[i].r;
}