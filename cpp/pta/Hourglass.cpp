/*
本题要求你写个程序把给定的符号打印成沙漏的形状。例如给定17个“*”，要求按下列格式打印

*****
 ***
  *
 ***
*****

所谓“沙漏形状”，是指每行输出奇数个符号；各行符号中心对齐；相邻两行符号数差2；符号数先从大到小顺序递减到1，再从小到大顺序递增；首尾符号数相等。

给定任意N个符号，不一定能正好组成一个沙漏。要求打印出的沙漏能用掉尽可能多的符号。

输入格式:
输入在一行给出1个正整数N（≤1000）和一个符号，中间以空格分隔。

输出格式:
首先打印出由给定符号组成的最大的沙漏形状，最后在一行中输出剩下没用掉的符号数。
*/

#include <iostream>
using namespace std;

int main()
{
    int n, row = 0, col = 1, t = 1;
    char ch;
    cin >> n >> ch;
    for (int i = 7, row_num = 6; i <= n; row_num += 4, i += row_num)
    {
        row++;
        t = i;
        col += 2;
    }
    t = n - t;
    if (n == 0)
        col = 0;

    for (int j = col, k = 0; j >= 1; j -= 2, k += 1)
    {
        for (int temp = k; temp > 0; temp--)
        {
            cout << " ";
        }
        for (int temp = j; temp > 0; temp--)
        {
            cout << ch;
        }
        cout << endl;
    }

    for (int j = 3, k = col / 2 - 1; j <= col; j += 2, k -= 1)
    {
        for (int temp = k; temp > 0; temp--)
        {
            cout << " ";
        }
        for (int temp = j; temp > 0; temp--)
        {
            cout << ch;
        }
        cout << endl;
    }

    cout << t;
    return 0;
}