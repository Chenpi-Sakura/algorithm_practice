/*
P1093 [NOIP2007 普及组] 奖学金

输入n个学生成绩，按照学号顺序从1开始输入。
输出总成绩最好的前五个，若相同按语文，若在相同按学号。
*/
#include <bits/stdc++.h>
using namespace std;

typedef tuple<int, int, int> TUP;
vector<TUP> a;
int n;

bool cmp(TUP x, TUP y)
{
    if (get<2>(x) != get<2>(y))
    {
        return get<2>(x) > get<2>(y);
    }
    else
    {
        if (get<1>(x) != get<1>(y))
        {
            return get<1>(x) > get<1>(y);
        }
        else
        {
            return get<0>(x) < get<0>(y); // 注意学号小的在上
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int c, m, e;
        cin >> c >> m >> e;
        e += c + m;
        a.push_back(make_tuple(i + 1, c, e));
    }
    sort(a.begin(), a.end(), cmp);
    for (int i = 0; i < min(5, (int)a.size()); i++)
    {
        cout << get<0>(a[i]) << " " << get<2>(a[i]) << endl;
    }
    return 0;
}