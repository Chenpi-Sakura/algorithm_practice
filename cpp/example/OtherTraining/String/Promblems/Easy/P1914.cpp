/*
凯撒密码
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    string s;

    cin >> n >> s;
    int len = 'z' - 'a' + 1;
    while (n >= (len))
    {
        n -= len;
    }
    int length = s.size();   
    for (int i = 0; i < length; i++)
    {
        if (s[i] + n > 'z')
        {
            s[i] = s[i] + n - len;
            cout << s[i];
        }
        else
        {
            s[i] += n;
            cout << s[i];
        }
    }
    
    return 0;
}