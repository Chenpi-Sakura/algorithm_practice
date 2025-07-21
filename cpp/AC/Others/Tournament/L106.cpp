/*
L1-6 字符串糕手

题目描述:
YFffffff 在学完字符串有关算法后觉得自己成为了字符串糕手，于是他找了一道字符串来练练手，题目大意：
给定一个只由小写字母构成的字符串，你可以进行的操作是在该字符串末尾添加任意一个字母，问需要进行最少多少次操作才能使其变成回文字符串?
YFffffff 没多久便想出了解决办法，你知道他是怎么解决的么？
PS:回文字符串满足正读和反读都一样。例如，“level”或“noon”都是回文串,而"hello"不是回文字符串

输入格式:
第一行一个整数 n(1≤n≤10^3),代表字符串长度.
第二行一个字符串。

输出格式:
输出一个整数表示需要最少多少次操作。
*/

// 一道很简单的字符串题目，巧妙的运用了反转的检查

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n; cin >> n;
    string s; cin >> s;
    string rs(s.rbegin(), s.rend());
    int i = 0;
    for (; i < n; i++)
    {
        if (s[i] == rs[0])
        {
            bool isRev = true;
            for (int j = 1; i + j < n; j++)
            {
                if (s[i + j] != rs[j])
                {
                    isRev = false;
                    break;
                }
            }
            if (isRev) break;
        }
    }
    cout << i << endl;
    return 0;
}