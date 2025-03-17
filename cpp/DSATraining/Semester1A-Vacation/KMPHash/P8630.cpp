/*
[蓝桥杯 2015 国 B] 密文搜索
题目描述
福尔摩斯从 X 星收到一份资料，全部是小写字母组成。
他的助手提供了另一份资料：许多长度为 8 的密码列表。
福尔摩斯发现，这些密码是被打乱后隐藏在先前那份资料中的。
请你编写一个程序，从第一份资料中搜索可能隐藏密码的位置。要考虑密码的所有排列可能性。

输入格式
输入第一行：一个字符串 s，全部由小写字母组成，长度小于 1024×1024。
紧接着一行是一个整数 n, 表示以下有 n 行密码，1≤n≤1000。
紧接着是 n 行字符串，都是小写字母组成，长度都为 8。

输出格式
一个整数，表示每行密码的所有排列在 s 中匹配次数的总和。
*/
#include<bits/stdc++.h> 
using namespace std;

const int N = 1e7;
char s[N];

int main( )
{
    cin >> s;

    int n; cin >> n;
    int ans = 0;
    while (n--)
    {
        int cnt1[26] = {0};
        char code[9]; cin >> code;
        for (int i = 0; code[i]; i++)
        {
            int j = code[i] - 'a';
            cnt1[j]++;
        }
        for (int i = 0; s[i + 7]; i++)
        {
            int cnt2[26] = {0};
            for (int j = i; j < i + 8; j++)
            {
                int k = s[j] - 'a';
                cnt2[k]++;
            }

            bool check = true;
            for (int i = 0; i < 26; i++)
            {
                if (cnt1[i] != cnt2[i]) 
                {
                    check = false;
                    break;
                }
            }
            if (check) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}