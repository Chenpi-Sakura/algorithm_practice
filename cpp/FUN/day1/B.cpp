#include <bits/stdc++.h>
using namespace std;

int main()
{
    int length;
    cin >> length;
    char to_replace, be_replace;
    cin >> to_replace;
    string artcle;
    cin >> artcle;
    cin >> be_replace;
    for (char& ch : artcle)
    {
        if (ch == to_replace)
        {
            ch = be_replace;
        }
        else if (ch == to_replace + ('a' - 'A'))
        {
            ch = be_replace + ('a' - 'A');
        }
    }
    cout << artcle;
    return 0;
}