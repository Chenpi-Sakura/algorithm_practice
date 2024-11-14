#include <iostream>
using namespace std;

int cal(int d)
{
    int total = 1;
    for (int i = 1; i <= d; i++)
    {
        total = (total + 1) * 2;
    }
    return total;
}

int main()
{
    int N;
    cin >> N;
    cout << cal(N);
}