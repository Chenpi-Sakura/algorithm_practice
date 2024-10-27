/*
MT1171 幻数
一个数字，把他的各位数累加会得到一个新的数字，再把这个新数字的每一位加起来，重复这个过程，直到只剩下一位数字，如果最后剩下的数字是1，就称原数为一个幻数。输入正整数N，检查它是否是一个幻数，输出YES或者NO。
*/

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string n;
    cin >> n;
    int t;
    while (n.length() != 1)
    {
        t = 0;
        for (int i = 0, len = n.length(); i < len; i++)
        {
            t += n[i] - '0';
        }
        n = to_string(t);
    }
    cout << (n == "1" ? "YES" : "NO") << endl;

    return 0;
}
