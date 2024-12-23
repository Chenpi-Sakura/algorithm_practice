/*
优先队列
优先队列（Priority Queue）是一种数据结构，它类似于队列，但其中的元素是按优先级顺序排列的。每次访问队列时，取出的元素总是具有最高优先级的元素，而不按照入队顺序。

默认为最大堆，可接受重复元素

priority_queue 是一个模板类，其模板参数包括：

T：元素的类型。
Container：存储容器的类型，通常是 vector，也可以使用其他容器。
Compare：比较器，用来决定元素的优先级。默认是 less<T>，表示最大堆，如果是 greater<T>，则表示最小堆。

push：插入一个元素。
pq.push(value);

pop：移除堆顶元素：
pq.pop();

top：返回堆顶元素（但不移除它）。
pq.top();

empty：检查堆是否为空。
pq.empty();

size：获取堆的元素数量。
pq.size();
*/
//例如以下

#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue <int, vector<int>, greater<int>> pq;//最小堆(必须写这个vector<int>，最大可忽略)小在上
    pq.push(100);
    pq.push(90);
    pq.push(110);
    pq.push(10);
    pq.push(50);
    pq.push(5);

    while (!pq.empty()) 
    {
        cout << pq.top() << " ";  // 输出最小的元素
        pq.pop(); // 移除堆顶元素
    }

    return 0;
}