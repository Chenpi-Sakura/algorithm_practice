#include<bits/stdc++.h>
using namespace std;

unordered_map<string, bool> f;
unordered_set<string> s;

int main()
{
    int n; cin >> n;
    while (n--)
    {
        int k; cin >> k;
        for (int i = 0; i < k; i++)
        {
            string id; cin >> id;
            if (k != 1) f[id] = true;
        }
    }
    
    int handsome = 0;
    int m; cin >> m;
    while (m--)
    {
        string id; cin >> id;
        if (!f[id] && s.find(id) == s.end())
        {
            handsome++;
            s.insert(id);
            if (handsome > 1) cout << ' ';
            cout << id;
        }
    }
    if (!handsome) cout << "No one is handsome";
    cout << endl;
    return 0;
}