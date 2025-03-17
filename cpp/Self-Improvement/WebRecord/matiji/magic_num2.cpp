/*
MT1173 魔数

一个数字，把他乘以二，会得到一个新的数字，如果这个新数字依然由原数中那些数字组成，就称原数为一个魔数。输入正整数N，检查它是否是一个魔数，输出YES或者NO。
*/

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    int n1, n2;
    string num1, num2;
    cin >> n1;
    n2 = n1 * 2;
    num1 = to_string(n1);
    num2 = to_string(n2);

    sort(num1.begin(), num1.end());
    sort(num2.begin(), num2.end());

    cout << (num1 == num2 ? "YES" : "NO") << endl;

    return 0;
}