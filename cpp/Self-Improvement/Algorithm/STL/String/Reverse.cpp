#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "Fuck you, world!";
    string s1(s.rbegin(), s.rend());
    reverse(s.begin(), s.end()); // reverse函数的使用方式 reverse[First, end), 左开右闭
    cout << s << endl;
    cout << s1 << endl;
    char a[20] = "0123456789";
    reverse(a, a + 5);
    cout << a << endl;
    return 0;
}