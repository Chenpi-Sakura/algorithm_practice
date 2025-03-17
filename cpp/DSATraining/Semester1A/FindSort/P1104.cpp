/*
题目描述
cjf 君想调查学校 OI 组每个同学的生日，并按照年龄从大到小的顺序排序。但 cjf 君最近作业很多，没有时间，所以请你帮她排序。

输入格式
输入共有 n+1 行，第 1 行为 OI 组总人数 n；
第 2 行至第 n+1 行分别是每人的姓名 s、出生年 y、月 m、日 d。

输出格式
输出共有 n 行，即 n 个生日从大到小同学的姓名。（如果有两个同学生日相同，输入靠后的同学先输出）
*/
#include <bits/stdc++.h>
using namespace std;

struct quad {
    string name;
    int year;
    int mouth;
    int day;
    int index;
};

vector<quad> a;
int n;

bool cmp(quad a, quad b)
{
    if (a.year == b.year)
    {
        if (a.mouth == b.mouth)
        {
            if (a.day == b.day)
            {
                return a.index > b.index; // 指数越大越靠前
            }
            else
            { 
                return a.day < b.day;
            }
        }
        else
        {
            return a.mouth < b.mouth;
        }
    }
    else
    {
        return a.year < b.year;
    }
}

int main()
{
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++)
    {
        string na;
        int ye, mo, da;
        cin >> na >> ye >> mo >> da;
        a[i] = {na, ye, mo, da, i};
    }
    sort(a.begin(), a.end(), cmp);
    for (int i = 0; i < n; i++)
    {
        cout << a[i].name << endl;
    }

    return 0;
}