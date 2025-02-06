#include <iostream>
using namespace std;

int main()
{
    int a, b;
    char op;
    cin >> a >> op >> b;
    if (op == '+' || op == '-' || op == '*' || op == '/' || op == '%')
    {
        switch (op)
        {
        case '+':
            cout << a + b;
            break;
        case '-':
            cout << a - b;
            break;
        case '*':
            cout << a * b;
            break;
        case '/':
            cout << a / b;
            break;
        case '%':
            cout << a % b;
            break;
        }
    }
    else
    {
        cout << "ERROR";
    }

    return 0;
}