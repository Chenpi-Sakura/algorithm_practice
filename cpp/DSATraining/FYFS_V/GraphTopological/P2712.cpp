/*

*/
#include<bits/stdc++.h> 
using namespace std;

const int N = 1e4;
vector<int> e[N], camList;
int din[N], dout[N];

int toposort(int ans)
{
    int n = 100;
    queue<int> q;
    for (int x : camList)
    {
        if (din[x] == 0 && dout[x] != 0) q.push(x);
    }
    while (q.size())
    {
        int x = q.front(); q.pop();
        dout[x] = 0;
        for (int y : e[x])
            if (--din[y] == 0 && dout[y] != 0) q.push(y);
    }
    for (int x : camList) if (din[x] == 0 && dout[x] == 0) ans--;
    return ans;
}

int main( )
{
    int n; cin >> n;
    int v = n;
    while (n--)
    {
        int x, m; cin >> x >> m;
        camList.push_back(x);
        while (m--)
        {
            int y; cin >> y;
            e[x].push_back(y);
            din[y]++; dout[x]++;
        }
    }
    int ans = toposort(v);
    if (!ans) cout << "YES" << endl;
    else cout << ans << endl;

    return 0;
}