#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> numbers(3);
    for (int i = 0; i < 3; i++)
    {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());

    for (int i = 0; i < 3; i++)
    {
        cout << numbers[i];
    }

    return 0;
}