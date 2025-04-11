#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> PII;
const int N = 1e7 + 5;
const int M = 1e9 + 7;
const int inf = 0x3f3f3f3f;

string fh = ".,?!;:'";
bool isDe(char x)
{
    return x == ' ' || fh.find(x) != string::npos;
}

void solve()
{
    string s; getline(cin, s);
    cout << s << endl;
    while (!s.empty() && s.back() == ' ') s.pop_back();
    while (!s.empty() && s.front() == ' ') s.erase(0, 1);
    // cout << s << endl;
    string ss = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (isupper(s[i]))
        {
            if (s[i] != 'I') ss += tolower(s[i]);
            else ss += s[i];
        }
        else if (s[i] == ' ')
        {
            while (ss.empty() || ss.back() != ' ')
                ss += ' ';
        }
        else if (fh.find(s[i]) != string::npos)
        {
            if (!ss.empty() && ss.back() == ' ') ss.pop_back();
            if (s[i] == '?') ss += '!';
            else ss +=  s[i];
        }
        else ss += s[i];
    }
    s = " " + ss + " ";
    string words[] = {"I", "me", "can you", "could you", "temp"};
    string repla[] = {"temp", "temp", "I can", "I could", "you"};

    for (int i = 0; i < 5; i++)
    {
        string beRe = words[i];
        string reTo = repla[i];
        int pos = 0;
        while ((pos = s.find(beRe, pos)) != string::npos)
        {
            bool isIn = true;
            int si = pos - 1;
            int ei = pos + beRe.size();
            if (!isDe(s[si])) isIn = false;
            if (!isDe(s[ei])) isIn = false;
            if (isIn)
            {
                s.replace(pos, beRe.size(), reTo);
                pos += beRe.size();
            }
            else pos++;
        }
    }
    s.pop_back();
    cout << "AI:" << s << endl;
}

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); //cout.tie(0);
    int t; cin >> t; cin.ignore();
    // t = 1;
    while (t--) solve();
    return 0;
}