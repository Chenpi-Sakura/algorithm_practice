#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if ((a + b) <= c || (b + c) <= a || (a + c) <= b)
    {
        cout << "These sides do not correspond to a valid triangle";
    }
    else
    {
        double s = a + b + c, s1 = s / 2;
        double area = sqrt(s1 * (s1 - a) * (s1 - b) * (s1 - c));
        printf("area = %.2lf; perimeter = %.2lf", area, s);
    }

    return 0;
}