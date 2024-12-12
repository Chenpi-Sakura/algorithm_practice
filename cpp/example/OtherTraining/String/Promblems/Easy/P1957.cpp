/*
输入格式
第一行一个整数 i。

接着的 i 行为需要输入的算式，每行可能有三个数据或两个数据。
若该行为三个数据则第一个数据表示运算类型，a 表示加法运算，b 表示减法运算，c 表示乘法运算，接着的两个数据表示参加运算的运算数。
若该行为两个数据，则表示本题的运算类型与上一题的运算类型相同，而这两个数据为运算数。

输出格式
输出 2×i 行。对于每个输入的算式，输出完整的运算式及结果，第二行输出该运算式的总长度。
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    cin.ignore();
    char op;
    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);
        int length = s.size();
        int n1, n2;
        if (s[0] == 'a' || s[0] == 'b' || s[0] == 'c')
        {
            op = s[0];
            sscanf(s.c_str() + 2, "%d %d", &n1, &n2);
        }
        else
        {
            sscanf(s.c_str(), "%d %d", &n1, &n2);
        }

        int result;
        if (op == 'a')
        {
            result = n1 + n2;
        }
        else if (op == 'b')
        {
            result = n1 - n2;
        }
        else if (op == 'c')
        {
            result = n1 * n2;
        }
        string output = to_string(n1) + (op == 'a' ? '+' : op == 'b' ? '-'
                                                                     : '*') +
                        to_string(n2) + '=' + to_string(result);
        int len = output.size();
        cout << output << endl
             << len << endl;
    }
}


int main()
{

}
