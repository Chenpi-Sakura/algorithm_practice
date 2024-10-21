/*
MT1169 平衡数

题目描述：
输入一个正整数，它有N位数，N是大于1的奇数，判断它是不是平衡数。如果左侧的所有数字和等于右侧的所有数字之和，则称为平衡数。不考虑不合理的输入等特殊情况。
*/

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int sum = 0, len;
    string s;
    cin >> s;
    len = s.size();
    for (int i = 0; i < len; i++)
    {
        if (i < (len / 2))
        {
            sum += s[i];
        }
        else if (i > (len / 2))
        {
            sum -= s[i];
        }
    }
    if (sum == 0)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}
