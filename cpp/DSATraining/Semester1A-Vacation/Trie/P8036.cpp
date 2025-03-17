/*
题目描述
给定 n 个模式串 s1, s2, …, sn 和 q 次询问，每次询问给定一个文本串 ti ，请回答 s1 ∼ sn 中有多少个字符串 sj 满足 ti 是 sj 的前缀。
一个字符串 t 是 s 的前缀当且仅当从 s 的末尾删去若干个（可以为 0 个）连续的字符后与 t 相同。
输入的字符串大小敏感。例如，字符串 Fusu 和字符串 fusu 不同。

输入格式
本题单测试点内有多组测试数据。
输入的第一行是一个整数，表示数据组数 T。
对于每组数据，格式如下：
第一行是两个整数，分别表示模式串的个数 n 和询问的个数 q。
接下来 n 行，每行一个字符串，表示一个模式串。
接下来 q 行，每行一个字符串，表示一次询问。

输出格式
按照输入的顺序依次输出各测试数据的答案。
对于每次询问，输出一行一个整数表示答案。

输入输出样例
输入 #1

3
3 3
fusufusu
fusu
anguei
fusu
anguei
kkksc
5 2
fusu
Fusu
AFakeFusu
afakefusu
fusuisnotfake
Fusu
fusu
1 1
998244353
9
输出 #1

2
1
0
1
2
1
说明/提示
数据规模与约定
对于全部的测试点，保证 1≤T,n,q≤10^5 ，且输入字符串的总长度不超过 3×10^6 。输入的字符串只含大小写字母和数字，且不含空串。
*/
#include<bits/stdc++.h> 
using namespace std;

const int N = 3e6 + 5;
char s[N];
int ch[N][65], cnt[N], idx;

int getNum(char x)
{
    if (x >= 'A' && x <= 'Z') return x - 'A';
    else if (x >= 'a' && x <= 'z') return x - 'a' + 26;
    else return x - '0' + 52;
}

void insert()
{
    int p = 0;
    for (int i = 0; s[i]; i++)
    {
        int j = getNum(s[i]);
        if (ch[p][j] == 0) ch[p][j] = ++idx;
        p = ch[p][j];
        cnt[p]++;
    }
}

int query()
{
    int p = 0; 
    for (int i = 0; s[i]; i++)
    {
        int j = getNum(s[i]);
        if (ch[p][j] == 0) return 0;
        p = ch[p][j];
    }
    return cnt[p];
}

int main( )
{
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--)
    {
        for (int i = 0; i <= idx; i++)
            for (int j = 0; j < 65; j++)
                ch[i][j] = 0;
        for (int i = 0; i <= idx; i++) cnt[i] = 0;
        idx = 0;

        int n, q; cin >> n >> q;
        while (n--)
        {
            cin >> s;
            insert();
        }
        while (q--)
        {
            cin >> s;
            cout << query() << endl;
        }
    }
    return 0;
}