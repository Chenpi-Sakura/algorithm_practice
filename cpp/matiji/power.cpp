/*
MT1174 A的B次方

输入正整数N，判断它是否可以表示为A的B次方，其中B>1，A>0，都是整数。输出YES或者NO。
*/

/*
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n == 1){
        cout << "YES" << endl;
        return 0;
    }
    for (int a = 2; a <= (int)sqrt(n); a++)
    {
        for (int b = 2, t = pow(a, b); t <= n; b++)
        {
            if (t == n)
            {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";

    return 0;
}
*/

#include <iostream>
using namespace std;

int main()
{
    long long n;
    cin >> n;

    if (n == 1)
    {
        cout << "YES" << endl;
        return 0;
    }

    for (long long a = 2; a * a <= n; a++) // a 的平方不超过 n
    {
        long long power = a * a; // 从 a 的平方开始
        for (long long b = 2; power <= n; b++)
        {
            if (power == n)
            {
                cout << "YES" << endl;
                return 0;
            }
            power *= a; // 计算 a 的 b 次方
        }
    }

    cout << "NO" << endl;
    return 0;
}

// cha桑的代码直接少了超多数学计算，速度和便捷是要做选择的。