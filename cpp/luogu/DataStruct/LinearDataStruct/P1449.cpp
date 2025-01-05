/*
P1449 后缀表达式

题目描述
所谓后缀表达式是指这样的一个表达式：式中不再引用括号，运算符号放在两个运算对象之后，所有计算按运算符号出现的顺序，严格地由左而右新进行（不用考虑运算符的优先级）。

本题中运算符仅包含 + - * /。保证对于 / 运算除数不为 0。特别地，其中 / 运算的结果需要向 0 取整（即与 C++ / 运算的规则一致）。

如：3*(5-2)+7 对应的后缀表达式为：3.5.2.-*7.+@。
在该式中，@ 为表达式的结束符号。. 为操作数的结束符号。

输入格式
输入一行一个字符串 s，表示后缀表达式。

输出格式
输出一个整数，表示表达式的值。

初看很难去理解对吧
OK，我来模拟一下计算过程
3.
3.5.
3.5.2.
3.5.2.-  ->  3.3.
3.3.*  ->  9.
9.7.
9.7.+  ->  16.

这与一个数据结构相关，对！
后进先出，栈
接下来，实现他吧！
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

stack<LL> RPN;
int main()
{
    string s;
    cin >> s;
    LL end = 0;
    while (s[end] != '@')
    {
        if (s[end] == '+' || s[end] == '-' || s[end] == '*' || s[end] == '/')
        {
            LL n2 = RPN.top();
            RPN.pop();
            LL n1 = RPN.top();
            RPN.pop();
            if (s[end] == '+')
            {
                RPN.push(n1 + n2);
            }
            else if (s[end] == '-')
            {
                RPN.push(n1 - n2);
            }
            else if (s[end] == '*')
            {
                RPN.push(n1 * n2);
            }
            else if (s[end] == '/')
            {
                RPN.push(n1 / n2);
            }
            end++;
        }
        else if (s[end] != '.')
        {
            string number;
            LL n = 0;
            LL len = 0;

            while (s[end] != '.')
            {
                number += s[end++];
                len++;
            }
            
            for (LL i = 0; i < len; i++)
            {
                LL x = 1;
                for (LL j = 1 + i; j < len; j++)
                {
                    x *= 10;
                }
                n += (number[i] - '0') * x;
            }
            RPN.push(n);
        }
        else
            end++;
    }
    cout << RPN.top() << endl;

    return 0;
}