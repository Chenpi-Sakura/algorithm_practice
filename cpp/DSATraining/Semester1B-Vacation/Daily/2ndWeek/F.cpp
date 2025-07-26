/** 
 * @Author: Chenpi
 * @Date: 2025-07-25 10:44:11
 * @Link: https://codeforces.com/gym/624417/problem/F
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 20;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

void solve()
{
    int n, m, k; cin >> n >> m >> k;
    if (k % 2 != (m + n) % 2 || k < (m + n - 2)) cout << "NO" << endl;
    else
    {
        cout << "YES" << endl;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=(m-1);j++)
				if(i==1)
					if(j%2==1)cout<<"R ";
					else cout<<"B ";	
				else cout<<"B ";
			cout<<endl;
		}
		for(int i=1;i<=(n-1);i++){
			for(int j=1;j<=m;j++)
				if(j==m)
					if((m-1)%2==0)
						if(i%2==1)cout<<"R ";
						else cout<<"B ";
					else
						if(i%2==1)cout<<"B ";
						else cout<<"R ";
				else cout<<"R ";
			cout<<endl;
		}
    }
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
    return 0;
}