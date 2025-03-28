/*
[传智杯 #4 决赛] 小智的疑惑
题目描述
传智专修学院给了小智一个仅包含小写字母的字符串 s，他想知道，里面出现了多少次子串 chuanzhi 呢。
我们称一个字符串 t 是 s 的子串，当且仅当将 s 的开头若干个（可以为 0 个）连续字符和结尾若干个（可以为 0 个）连续字符删去后，剩下的字符串和 t 相同。例如，我们称 ab 是 abc 的子串，但 ac 不是 abc 的子串。

输入格式
输入只有一行一个字符串，表示字符串 s。

输出格式
输出一行一个整数表示答案。
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin >> s;
    int ans = 0;

    string target = "chuanzhi";
    int count = 0;
    size_t pos = 0;

    while ((pos = s.find(target, pos)) != string::npos)
    {
        count++;
        pos++;
    }
    
    cout << count <<endl;
    return 0;
}