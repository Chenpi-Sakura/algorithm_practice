#include <bits/stdc++.h>
using namespace std;

// 直接模拟烟雾绝对会超时， 转换思路，不妨把烟雾的移动转换为Taka的移动？
// 这样模拟的方式似乎也不太行，我们把{0, 0}的移动轨迹也加上？
typedef pair<int, int> PII;
map<PII, bool> startSet;

int main()
{
    int n, r, c; cin >> n >> r >> c;
    PII Taka = {r, c}, start = {0, 0};
    startSet[start] = true;  
    string s; cin >> s;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        if (s[i] == 'N') x = 1, y = 0;
        else if (s[i] == 'W') x = 0, y = 1;
        else if (s[i] == 'S') x = -1, y = 0;
        else if (s[i] == 'E') x = 0, y = -1;
        Taka.first += x, Taka.second += y;
        start.first += x, start.second += y;
        startSet[start] = true;
        if (startSet[Taka]) cout << 1;
        else cout << 0;
    }
    cout << endl;
    return 0;
}

// typedef pair<int, int> PII;
// vector<PII> smoke;

// int main()
// {
//     int n, r, c; cin >> n >> r >> c;
//     PII Taka = {r, c}, start = {0, 0};
//     string s; cin >> s;

//     bool startS = false;
//     for (int i = 0; i < n; i++)
//     {
//         if (!startS) smoke.push_back({0, 0});
//         int x, y;
//         if (s[i] == 'N') x = -1, y = 0;
//         else if (s[i] == 'W') x = 0, y = -1;
//         else if (s[i] == 'S') x = 1, y = 0;
//         else if (s[i] == 'E') x = 0, y = 1;
//         bool smoked = false; startS = false;
//         int len = smoke.size();
//         for (int j = 0; j < len; j++)
//         {
//             smoke[j].first += x; smoke[j].second += y;
//             if (smoke[j] == Taka && !smoked)
//             {
//                 cout << 1;
//                 smoked = true;
//             }
//             else if (smoke[j] == start) startS = true;
//         }
//         if (!smoked) cout << 0;
//     }
//     cout << endl;
//     return 0;
// }