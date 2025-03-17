/*
题目描述
我们称一个字符串 S 包含字符串 T 是指 T 是 S 的一个子序列，即可以从字符串 S 中抽出若干个字符，它们按原来的顺序组合成一个新的字符串与 T 完全一样。

给定两个字符串 S 和 T，请问最少修改 S 中的多少个字符，能使 S 包含 T。

输入格式
输入两行，每行一个字符串。第一行的字符串为 S，第二行的字符串为 T。两个字符串均非空而且只包含大写英文字母。

输出格式
输出一个整数，表示答案。
*/

/*
    编辑距离的变种题目
    这道题目的本质：只有替换与删除操作，
    替换代价 + 1
    删除无代价
*/

#include<bits/stdc++.h> 
using namespace std;

const int N = 1e3 + 5;
const int inf = 0x3f3f3f3f;
string s, t;
int f[N][N];
int lens, lent;

void dp()
{
    memset(f, inf, sizeof(f));
    for (int i = 0; i <= lens; i++) f[i][0] = 0;
    for (int i = 1; i <= lens; i++) for (int j = 1; j <= lent; j++)
    {
        if (s[i] == t[j]) f[i][j] = f[i - 1][j - 1];
        else f[i][j] = min(f[i - 1][j - 1] + 1, f[i - 1][j]);
    }
}

int main( )
{
    cin >> s >> t;
    s = " " + s, t = " " + t;
    lens = s.size(), lent = t.size();
    dp();
    cout << f[lens][lent] << endl;
    return 0;
}