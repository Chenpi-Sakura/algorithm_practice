/*
题目大意
对于一个仅含小写字母的字符串 a，p 为 a 的前缀且 p ≠ a，那么我们称 p 为 a 的 proper 前缀。
规定字符串 Q 表示 a 的周期，当且仅当 Q 是 a 的 proper 前缀且 a 是 Q+Q 的前缀。若这样的字符串不存在，则 a 的周期为空串。
例如 ab 是 abab 的一个周期，因为 ab 是 abab 的 proper 前缀，且 abab 是 ab+ab 的前缀。
 求给定字符串所有前缀的最大周期长度之和。
*/

#include<bits/stdc++.h> 
using namespace std;

const int N = 1e7;
int Next[N];
char s[N];

int main( )
{
    int n; cin >> n >> s;
    int j = 0;
    Next[0] = j;
    for (int i = 1; i < n; i++)
    {
        while (j > 0 && s[i] != s[j]) j = Next[j];
        if (s[i] == s[j]) j++;
        Next[i + 1] = j;
        // cout << j << " ";
    }

    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        j = i;
        while (Next[j]) j = Next[j];
        if (Next[i]) Next[i] = j;
        ans += i - j;
        // cout << ans << i << j << endl;
    }

    cout << ans << endl;
    return 0;
}