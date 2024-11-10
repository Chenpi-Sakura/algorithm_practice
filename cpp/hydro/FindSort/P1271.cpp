/* 
#P1271. 【深基9.例1】选举学生会

题目描述
学校正在选举学生会成员，有 n (n≤999）名候选人，每名候选人编号分别从 1 到 n，现在收集到了 m（m≤2000000）张选票，每张选票都写了一个候选人编号。现在想把这些堆积如山的选票按照投票数字从小到大排序。

输入格式
输入 n 和 m 以及 m 个选票上的数字。

输出格式
求出排序后的选票编号。
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> a;

int main(){
    int n, m;
    cin >> n >> m;
    a.resize(m);
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < m; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}