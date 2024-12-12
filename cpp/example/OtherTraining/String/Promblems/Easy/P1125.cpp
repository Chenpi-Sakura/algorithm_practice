/*
P1125 [NOIP2008 提高组] 笨小猴

题目描述
笨小猴的词汇量很小，所以每次做英语选择题的时候都很头疼。但是他找到了一种方法，经试验证明，用这种方法去选择选项的时候选对的几率非常大！

这种方法的具体描述如下：假设 maxx 是单词中出现次数最多的字母的出现次数，minx 是单词中出现次数最少的字母的出现次数，如果 maxn - minn 是一个质数，那么笨小猴就认为这是个 Lucky Word，这样的单词很可能就是正确的答案。

输入格式
一个单词，其中只可能出现小写字母，并且长度小于 100。

输出格式

共两行，第一行是一个字符串，假设输入的的单词是 Lucky Word，那么输出 `Lucky Word`，否则输出 `No Answer`；

第二行是一个整数，如果输入单词是 `Lucky Word`，输出 maxn - minn 的值，否则输出 0。
*/

int isPrime(int n)
{
    if (n < 2)
        return 0;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int length = s.size();
    int alpha[26] = {0};
    for (int i = 0; i < length; i++)
    {
        int j = s[i] - 'a';
        alpha[j]++;
    }
    int max = 0, min = 101;
    for (int i = 0; i < 26; i++)
    {
        if (max < alpha[i])
            max = alpha[i];
        if (min > alpha[i] && alpha[i] != 0)
            min = alpha[i];
    }
    if (isPrime(max - min))
    {
        cout << "Lucky Word" << endl << max - min;
    }
    else 
        cout << "No Answer" << endl << 0;

    return 0;
}