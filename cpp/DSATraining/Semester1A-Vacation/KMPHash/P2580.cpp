/*
题目描述
这之后校长任命你为特派探员，每天记录他的点名。校长会提供化学竞赛学生的人数和名单，而你需要告诉校长他有没有点错名。（为什么不直接不让他玩炉石。）

输入格式
第一行一个整数 n，表示班上人数。
接下来 n 行，每行一个字符串表示其名字（互不相同，且只含小写字母，长度不超过 50）。
第 n+2 行一个整数 m，表示教练报的名字个数。
接下来 m 行，每行一个字符串表示教练报的名字（只含小写字母，且长度不超过 50）。

输出格式
对于每个教练报的名字，输出一行。
如果该名字正确且是第一次出现，输出 OK，如果该名字错误，输出 WRONG，如果该名字正确但不是第一次出现，输出 REPEAT。
*/
#include<bits/stdc++.h> 
using namespace std;

unordered_set<string> nameList;
unordered_set<string> checkList;

int main( )
{
    int n; cin >> n;
    while(n--)
    {
        string s; cin >> s;
        nameList.insert(s);
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s; cin >> s;
        if (nameList.find(s) == nameList.end()) cout << "WRONG" << endl;
        else if (checkList.find(s) == checkList.end())
        { 
            cout << "OK" << endl;
            checkList.insert(s);
        }
        else cout << "REPEAT" << endl;
    }

    return 0;
}