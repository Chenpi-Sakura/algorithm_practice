#include <iostream>
using namespace std;

const int N = 6;

int Iteration(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        int current = 1, last = 0;
        for (int i = 2; i <= n; i++)
        {
            int temp = last;
            last = current;
            current += temp;
        }
        return current;
    }
}
// 这是迭代

int Recursion(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1)
    {
        return 1;
    }
    else
    {
        return Recursion(n - 1) + Recursion(n - 2);
    }
}
// 这是递归

int main()
{
    cout << "这是迭代结果：" << endl;
    for (int i = 0; i <= N; i++)
    {
        cout << Iteration(i) << " ";
    }
    cout << endl << "这是递归结果：" << endl;
    for (int i = 0; i <= N; i++)
    {
        cout << Recursion(i) << " ";
    }
}