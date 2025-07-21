#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
string a[N];
int cnt[N];

int main()
{
    int t; cin >> t;
    while (t--)
    {
        //memset(cnt, 0, sizeof(cnt));
        int n, m; cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                int x; x = getchar();
                cnt[j] += x - '0';
            }
        }
        bool needAdd = false;
        for (int i = 0; i < m; i++) 
        {
            if(cnt[i] == 0)
            {
                needAdd = true;
                break;
            }
        }
        if (needAdd) cout << 1 << endl;
        else cout << 0 << endl;
    }
    return 0;
}