/*
有 C 头奶牛进行日光浴，第 i 头奶牛需要 minSPF[i] 到 maxSPF[i] 单位强度之间的阳光。

每头奶牛在日光浴前必须涂防晒霜，防晒霜有 L 种，涂上第 i 种之后，身体接收到的阳光强度就会稳定为 SPF[i]，第 i 种防晒霜有 cover[i] 瓶。

求最多可以满足多少头奶牛进行日光浴。

输入格式
第一行输入整数 C 和 L。

接下来的 C 行，按次序每行输入一头牛的 minSPF 和 maxSPF 值，即第 i 行输入 minSPF[i] 和 maxSPF[i]。

再接下来的 L 行，按次序每行输入一种防晒霜的 SPF 和 cover 值，即第 i 行输入 SPF[i] 和 cover[i]。
每行的数据之间用空格隔开。

输出格式
输出一个整数，代表最多可以满足奶牛日光浴的奶牛数目。

数据范围
1≤C,L≤2500,
1≤minSPF≤maxSPF≤1000,
1≤SPF≤1000
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 3e3;
typedef pair<int, int> PII;
vector<PII> c(N), l(N);

bool cmp(PII a, PII b)
{
    return a.first > b.first;
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> c[i].first >> c[i].second;
    for (int i = 0; i < m; i++) cin >> l[i].first >> l[i].second;
    sort(c.begin(), c.end(), cmp); sort(l.begin(), l.end(), cmp);
    
    // for (int i = 0; i < n; i++) cout << c[i].first << " " << c[i].second << endl;
    // cout << endl;
    // for (int i = 0; i < m; i++) cout << l[i].first << " " << l[i].second << endl;
    
    int ans = 0;
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++)
        {
            if (l[j].second != 0 && l[j].first <= c[i].second && l[j].first >= c[i].first)
            {
                ans++;
                l[j].second--;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}