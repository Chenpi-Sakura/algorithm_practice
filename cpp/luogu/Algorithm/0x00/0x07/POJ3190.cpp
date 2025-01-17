/*
有 N 头牛在畜栏中吃草。
每个畜栏在同一时间段只能提供给一头牛吃草，所以可能会需要多个畜栏。
给定 N 头牛和每头牛开始吃草的时间 A 以及结束吃草的时间 B，每头牛在 [A,B] 这一时间段内都会一直吃草。
当两头牛的吃草区间存在交集时（包括端点），这两头牛不能被安排在同一个畜栏吃草。
求需要的最小畜栏数目和每头牛对应的畜栏方案。

输入格式
第 1 行：输入一个整数 N。
第 2...N+1 行：第 i+1 行输入第 i 头牛的开始吃草时间 A 以及结束吃草时间 B，数之间用空格隔开。

输出格式
第 1 行：输出一个整数，代表所需最小畜栏数。
第 2...N+1 行：第 i+1 行输出第 i 头牛被安排到的畜栏编号，编号是从 1 开始的 连续 整数，只要方案合法即可。

数据范围
1≤N≤50000,
1≤A,B≤1000000
*/
#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 10;
typedef pair<int, int> PII;
pair<PII, int> cows[N]; // <区间，编号>

int main()
{
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> cows[i].first.first >> cows[i].first.second;
        cows[i].second = i;
    }
    sort(cows, cows + n);
    int id[N];
    priority_queue<PII, vector<PII>, greater<PII>> heap; // 储存终点最小的编号
    for (int i = 0; i < n; i++)
    {
        auto cow = cows[i].first;
        if (heap.empty() || heap.top().first >= cow.first)
        {
            PII stall = {cow.second, heap.size() + 1};
            id[cows[i].second] = stall.second;
            heap.push(stall);
        }
        else
        {
            PII stall = heap.top();
            heap.pop();
            stall.first = cow.second;
            id[cows[i].second] = stall.second;
            heap.push(stall);
        }
    }
    
    cout << heap.size() << endl;
    for (int i = 0; i < n; i++) cout << id[i] << endl;
    
    return 0;
}