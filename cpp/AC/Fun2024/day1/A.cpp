#include <bits/stdc++.h>
using namespace std;

int main()
{
    int month, day, hour, minute, v = 0;
    cin >> month >> day >> hour >> minute;
    if (month == 11 && day == 1)
    {
        if (hour >= 23 && minute >= 30)
        {
            v = 1;
        }
    }
    if (month == 4 && day == 30)
    {
        if (hour <= 6 && minute <= 30)
        {
            v = 1;
        }
    }
    if ((month <= 4 && day < 30) || (month >= 11 && day > 1))
    {
        if ((hour <= 6 && minute <= 30) || (hour >= 23 && minute >= 30))
        {
            v = 1;
        }
    }
    string message;
    char remove1 = 'E', remove2 = 'e';
    cin >> message;
    if (v)
    {
        message.erase(remove(message.begin(), message.end(), remove1), message.end());
        message.erase(remove(message.begin(), message.end(), remove2), message.end());
    }
    if (message == "")
    {
        cout << "What does Vingying say?";
    }
    else
        cout << message;
    return 0;
}