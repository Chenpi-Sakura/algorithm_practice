#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PR;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        vector<PR> recorder[10];
        int record = 0; // 记录局数
        int k;          // BO
        string temp;    // 对局数据
        cin >> k >> temp;
        int lr = 0, rr = 0, lw = 0, rw = 0;
        for (int j : temp)
        {
            if (j == '0')
            {
                lr++;
            }
            else if (j == '1')
            {
                rr++;
            }
            if (lr > 12 || rr > 12)
            {
                if (lr == 13 && rr < 12)
                {
                    lw++;
                    record++;
                    recorder[record].push_back(make_pair(lr, rr));
                    lr = 0;
                    rr = 0;
                }
                else if (rr == 13 && lr < 12)
                {
                    rw++;
                    record++;
                    recorder[record].push_back(make_pair(lr, rr));
                    lr = 0;
                    rr = 0;
                }
                else
                {
                    if (lr - rr >= 2)
                    {
                        lw++;
                        record++;
                        recorder[record].push_back(make_pair(lr, rr));
                        lr = 0;
                        rr = 0;
                    }
                    else if (rr - lr >= 2)
                    {
                        rw++;
                        record++;
                        recorder[record].push_back(make_pair(lr, rr));
                        lr = 0;
                        rr = 0;
                    }
                }
            }
        }
        if (lr > 0 || rr > 0)
        {
            recorder[record].push_back(make_pair(lr, rr));
        }
        if (lw == k || rw == k)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
        cout << lw << ":" << rw << " ";
        for (int i = 0; i <= record; i++)
        {
            for (auto &p : recorder[i])
            {
                cout << p.first << ":" << p.second << " ";
            }
        }
        cout << endl;
    }
    return 0;
}