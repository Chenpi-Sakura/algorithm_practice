#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s; cin >> s;
    int ans = 0;
    for (int i = 0; i < s.size(); i++)
    {  
        if (i % 2 == 0 && s[i] == 'o')
            {s = s.substr(0, i) + 'i' + s.substr(i); ans++;}
        else if (i % 2 == 1 && s[i] == 'i')
            {s = s.substr(0, i) + 'o' + s.substr(i); ans++;}
    }
    if (s.size() % 2 == 1) {s += 'o'; ans++;}
    cout << ans << endl;
    return 0;
}