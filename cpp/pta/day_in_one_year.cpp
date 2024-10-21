#include <iostream>
using namespace std;

int main()
{
    int y, m, d, feb, sum;
    scanf("%d/%d/%d", &y, &m, &d);
    if ((y % 4) == 0 && (y % 100) != 0 || (y % 400) == 0)
    {
        feb = 29;
    }
    else
    {
        feb = 28;
    }

    switch (m)
    {
    case 1:
        sum = d;
        cout << sum;
        break;
    case 2:
        sum = 31 + d;
        cout << sum;
        break;
    case 3:
        sum = 31 + feb + d;
        cout << sum;
        break;
    case 4:
        sum = 62 + feb + d;
        cout << sum;
        break;
    case 5:
        sum = 92 + feb + d;
        cout << sum;
        break;
    case 6:
        sum = 123 + feb + d;
        cout << sum;
        break;
    case 7:
        sum = 153 + feb + d;
        cout << sum;
        break;
    case 8:
        sum = 184 + feb + d;
        cout << sum;
        break;
    case 9:
        sum = 215 + feb + d;
        cout << sum;
        break;
    case 10:
        sum = 245 + feb + d;
        cout << sum;
        break;
    case 11:
        sum = 276 + feb + d;
        cout << sum;
        break;
    case 12:
        sum = 306 + feb + d;
        cout << sum;
        break;
    }

    return 0;
}