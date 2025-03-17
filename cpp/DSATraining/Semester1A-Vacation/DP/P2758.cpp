/*
编辑距离
题目描述
设 A 和 B 是两个字符串。我们要用最少的字符操作次数，将字符串 A 转换为字符串 B。这里所说的字符操作共有三种：
删除一个字符；
插入一个字符；
将一个字符改为另一个字符。
A,B 均只包含小写字母。

输入格式
第一行为字符串 A；
第二行为字符串 B；
字符串 A,B 的长度均小于 2000。

输出格式
只有一个正整数，为最少字符操作次数。
*/
#include<bits/stdc++.h> 
using namespace std;

const int N = 2005;
char a[N], b[N];
int f[N][N];
int n, m;

int main( )
{
    cin >> a >> b;
    n = strlen(a);
    m = strlen(b);
    for (int i = 1; i <= n; i++) f[i][0] = i;
    for (int j = 1; j <= m; j++) f[0][j] = j;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1]) f[i][j] = f[i - 1][j - 1];
            else f[i][j] = min(f[i - 1][j - 1], min(f[i - 1][j], f[i][j - 1])) + 1;
        }
    }

    cout << f[n][m] << endl;
    return 0;
}