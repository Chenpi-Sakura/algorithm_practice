#include <iostream>
using namespace std;

int main()
{
    double n;
    cin >> n;
    if (n <= 0)
    {
        cout << "Invalid Value!";
    }
    else if (n <= 50)
    {
        printf("cost = %.2lf", n * 0.53);
    }
    else
    {
        printf("cost = %.2lf", (50.0 * 0.53) + (n - 50.0) * 0.58);
    }

    return 0;
}