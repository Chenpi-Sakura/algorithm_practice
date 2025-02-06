#include <bits/stdc++.h>
using namespace std;

vector<string> notice;

int main()
{
    int n, tlen;
    cin >> n;
    notice.resize(n);
    string target = "nailong";
    tlen = target.size();

    for (int i = 0; i < n; i++)
    {
        cin >> notice[i];
    }

    for (int i = 0; i < n; i++)
    {
        int t = 0;
        int len = notice[i].size();
        if (tlen <= len)
        {
            int pos = 0;
            while ((pos = notice[i].find(target, pos)) != string::npos)
            {
                t++;
                pos += 7;
                if (t == 60)
                    break;
            }
        }
        if (t < 60)
            cout << t * 12 << endl;
        else
            cout << "Overflow!" << endl;
    }
    return 0;
}