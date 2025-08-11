/** 
 * @Author: MyGo!!!
 * @Date: 2025-08-09 13:30:34
 * @Link: https://codeforces.com/gym/628065/problem/M
 */
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

typedef pair<int, int> PII;
const int N = 1e3 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f3f3f3f3fLL;

char ss[N][N];

// char cc[][]={
//     {'#','#','#','#','#','#','#','#','#','#'},
//     {'#','#','#','#','#','#','#','#','#','#'},
//     {'#','#','#','#','#','#','#','#','#','#'},
//     {'#','#','#','#','.','.','#','#','#','#'},
//     {'#','#','#','.','.','.','.','#','#','#'},
//     {'#','#','#','.','.','.','.','#','#','#'},
//     {'#','#','#','#','.','.','#','#','#','#'},
//     {'#','#','#','#','#','#','#','#','#','#'},
//     {'#','#','#','#','#','#','#','#','#','#'},
//     {'#','#','#','#','#','#','#','#','#','#'}
// }

// bool jugde(int x,int y)
// {
//     for(int i=0;i<10;i++)
//     {
//         for(int j=0;j<10;j++)
//         {
//             if(ss[x+i])
//         }
//     }
// }

void solve()
{
    int n, m; cin >> n >> m;
    int b = 0, hole = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> ss[i][j];
            if (ss[i][j] == '#') b++;
        }
    }
    for (int i = 1; i <= n - 6; i++)
    {
        for (int j = 1; j <= m - 6; j++)
        {
            if (ss[i][j] == '#' && 
ss[i][j+1] == '#' && 
ss[i][j+2] == '#' && 
ss[i][j+3] == '#' && 
ss[i][j+4] == '#' && 
ss[i][j+5] == '#' && 

ss[i+1][j] == '#' && 
ss[i+1][j+1] == '#' && 
ss[i+1][j+2] == '.' && 
ss[i+1][j+3] == '.' && 
ss[i+1][j+4] == '#' && 
ss[i+1][j+5] == '#' && 

ss[i+2][j] == '#' && 
ss[i+2][j+1] == '.' && 
ss[i+2][j+2] == '.' && 
ss[i+2][j+3] == '.' && 
ss[i+2][j+4] == '.' && 
ss[i+2][j+5] == '#' && 

ss[i+3][j] == '#' && 
ss[i+3][j+1] == '.' && 
ss[i+3][j+2] == '.' && 
ss[i+3][j+3] == '.' && 
ss[i+3][j+4] == '.' && 
ss[i+3][j+5] == '#' && 

ss[i+4][j] == '#' && 
ss[i+4][j+1] == '#' && 
ss[i+4][j+2] == '.' && 
ss[i+4][j+3] == '.' && 
ss[i+4][j+4] == '#' && 
ss[i+4][j+5] == '#' && 

ss[i+5][j] == '#' && 
ss[i+5][j+1] == '#' && 
ss[i+5][j+2] == '#' && 
ss[i+5][j+3] == '#' && 
ss[i+5][j+4] == '#' && 
ss[i+5][j+5] == '#')
            {
                hole++;
            }
        }
    }
    int c = 0, s = 0;
    for (int i = 0; i <= 10000; i++)
    {
        for (int j = 0; j <= 8000; j++)
        {
            if (i * 100 + j * 146 == b && i + j * 2 == hole)
            {
                c = j, s = i;
                break;
            }
        }
    }
    cout << c << ' ' << s << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
    return 0;
}