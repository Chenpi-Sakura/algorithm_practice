#include<bits/stdc++.h> 
using namespace std;

vector<int> add(vector<int> a, vector<int> b)
{
    vector<int> c;
    int lena = a.size();
    int lenb = b.size();
    int len = min(lena, lenb);
    int t = 0;
    for (int i = 0; i < len; i++)
    {
        t += a[i] + b[i];
        c.push_back(t % 10);
        t /= 10;
    }
    if (lena > lenb)
    {
        while (len < lena)
        {
            t += a[len];
            c.push_back(t % 10);
            t /= 10;
            len++;
        }
    }
    else if (lenb > lena) 
    {
        while (len < lenb)
        {
            t += b[len];
            c.push_back(t % 10);
            t /= 10;
            len++;
        }
    }
    while (t)
    {
        c.push_back(t % 10);
        t /= 10;
    }
    return c;
}

int main( )
{
    string a, b; cin >> a >> b;
    vector<int> num1, num2;
    for (int i = a.size() - 1; i >= 0; i--) num1.push_back(a[i] - '0');
    for (int i = b.size() - 1; i >= 0; i--) num2.push_back(b[i] - '0');
    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    vector<int> result = add(num1, num2);
    int length = result.size();
    for (int i = result.size() - 1; i >= 0; i--) cout << result[i];

    return 0;
}