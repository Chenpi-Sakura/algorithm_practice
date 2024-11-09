#include <bits/stdc++.h>
using namespace std;

string s1, s2;
void f(string b, string s)
{
   if (b.find(s) != string::npos)
   {
    cout << s << " is substring of " << b;
   }
   else
   {
        cout << "No substring";
   }
}
int main()
{
    cin >> s1;
    cin >> s2;
    if (s1 == "" || s2 == "")
    {
        cout << "No substring";
    }
    else if (s1.size() > s2.size())
    {
        f(s1, s2);
    }
    else if (s1.size() < s2.size())
    {
        f(s2, s1);
    }
    else
    {
        if (s1 == s2)
        {
            cout << s1 << " is substring of " << s1;
        }
        else 
        {
            cout << "No substring";
        }
    }
    return 0;
}