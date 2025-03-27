#include <bits/stdc++.h>
using namespace std;

int a[20];

int main()
{
    for (int i = 1; i <= 7; i++)
    {
        int card; cin >> card;
        a[card]++;
    }
    bool three = false, two = false;
    for (int i = 1; i <= 13; i++)
    {
        if (!three && a[i] >= 3) three = true;
        else if (a[i] >= 2) two = true;
    }
    if (three && two) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}