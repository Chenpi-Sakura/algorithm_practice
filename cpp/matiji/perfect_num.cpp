/*
MT1172 完美数字

输入正整数N，检查它是否完美输出YES或者NO。把一个数字的每一位拆分开，计算他们的阶乘再累加，如果和等于原数字，则该数字是完美的。
*/

#include <iostream>
#include <string>
using namespace std;

int fact(int n)
{
    if (n <= 1){
        return 1;
    }
    return n * fact(n - 1);
}

int main()
{
    string num;
    cin >> num;
    int len = num.size(), sum = 0;
    for (int i = 0; i < len; i++){
        sum += fact(num[i] - '0');
    }
    string res = to_string(sum);
    cout << (res == num ? "YES" : "NO") << endl;

    return 0;
}