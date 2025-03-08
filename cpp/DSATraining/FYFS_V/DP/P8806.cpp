/*
[蓝桥杯 2022 国 B] 搬砖
题目描述
这天，小明在搬砖。
他一共有 n 块砖，他发现第 i 砖的重量为 wi，价值为 vi。他突然想从这些砖中选一些出来从下到上堆成一座塔，并且对于塔中的每一块砖来说，它上面所有砖的重量和不能超过它自身的价值。
他想知道这样堆成的塔的总价值（即塔中所有砖块的价值和）最大是多少。

输入格式
输入共 n+1 行, 第一行为一个正整数 n, 表示砖块的数量。
后面 n 行, 每行两个正整数 wi,vi 分别表示每块砖的重量和价值。

输出格式
一行，一个整数表示答案。
*/

/*
    贪心与01背包的结合
*/

#include<bits/stdc++.h> 
using namespace std;

const int N = 2e4 + 5;
typedef pair<int, int> PII;
PII a[N];
int f[N];

bool cmp(PII x, PII y)
{
    return x.first + x.second <= y.first + y.second;
}

int main( )
{
    int n; cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
    sort(a + 1, a + n + 1, cmp);
    memset(f, -0x3f, sizeof(f));
    f[0] = 0;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    { // 第 i 块砖
        for (int j = a[i].first + a[i].second; j >= a[i].first; j--) // 约束条件 j - a[i].first <= a[i].second
        {
            f[j] = max(f[j], f[j - a[i].first] + a[i].second);
            ans = max(ans, f[j]);
        }
    }
    cout << ans << endl;
    return 0;
}