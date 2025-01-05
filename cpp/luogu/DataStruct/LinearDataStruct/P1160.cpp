/*
P1160 队列安排

题目描述
一个学校里老师要将班上 N 个同学排成一列，同学被编号为 1~N，他采取如下的方法：

1. 先将 1 号同学安排进队列，这时队列中只有他一个人；

2. 2~N 号同学依次入列，编号为 i 的同学入列方式为：老师指定编号为 i 的同学站在编号为 1~(i-1) 中某位同学（即之前已经入列的同学）的左边或右边；

3. 从队列中去掉 M 个同学，其他同学位置顺序不变。

在所有同学按照上述方法队列排列完毕后，老师想知道从左到右所有同学的编号。

输入格式
第一行一个整数 N，表示了有 N 个同学。

第 2~N 行，第 i 行包含两个整数 k,p，其中 k 为小于 i 的正整数，p 为 0 或者 1。若 p 为 0，则表示将 i 号同学插入到 k 号同学的左边，p 为 1 则表示插入到右边。

第 N+1 行为一个整数 M，表示去掉的同学数目。

接下来 M 行，每行一个正整数 x，表示将 x 号同学从队列中移去，如果 x 号同学已经不在队列中则忽略这一条指令。

输出格式
一行，包含最多 N 个空格隔开的整数，表示了队列从左到右所有同学的编号。

对于100% 的数据，1<M≤N≤10^5。
*/
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
typedef Node *HNode;

void insestNode(HNode &Head, int n, int i, int v)
{
    Node *cur = Head;
    Node *NewNode = new Node;
    NewNode->data = n;
    if (v == 0)
    { // 插入左边的情况
        while (cur->next->data == n)
        {
            NewNode->next = cur->next;
            cur->next = NewNode;
        }
    }
    else
    {//插入右边的情况
        while (cur->data == n)
        {
            NewNode = 1
        }
    }
}

int main()
{
}